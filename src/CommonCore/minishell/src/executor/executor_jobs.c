/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_jobs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 19:34:45 by gabriel           #+#    #+#             */
/*   Updated: 2025/01/01 14:50:42 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "executor.h"
#include "job.h"
#include "cmd.h"
#include "libft.h"
#include "fd.h"

#include <unistd.h>

static	unsigned char	translate_status(int status)
{
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	if (WIFSIGNALED(status))
		return (128 + WTERMSIG(status));
	if (WIFSTOPPED(status))
		return (128 + WSTOPSIG(status));
	return (status);
}

static	bool	wait_cmd(t_cmd*cmd, int *status)
{
	pid_t	pid;

	if (cmd->pid != CMD_NO_PID)
	{
		pid = waitpid(cmd->pid, &cmd->return_value,0);
		if (pid < 0)
			return (ft_err_errno(NULL), false);
		*status = cmd->return_value;
	}
	else
	{
		*status = cmd->return_value;
	}
	return (true);	
}

static	bool	finish_cmds(t_list *init_cmd, t_list *final_cmd, t_minishell *shell)
{
	t_list	*node;
	t_cmd	*cmd;
	int		status;
	
	node = init_cmd;
	while(node != NULL && node != final_cmd)
	{
		cmd = (t_cmd *)node->content;
		if (!wait_cmd(cmd, &status))
			return (false);
		if (cmd->fd_out != FD_NONE && !fd_close(cmd->fd_out))
			return (false);
		node = node->next;
	}
	if (node != NULL)
	{
		cmd = (t_cmd *)node->content;
		if (!wait_cmd(cmd, &status))
			return (false);
		if (cmd->fd_out != FD_NONE && !fd_close(cmd->fd_out))
			return (false);
	}
	shell->last_status = translate_status(status);
	return (true);
}

static bool	executor_jobs_loop(t_minishell *shell, t_list *node_cmd, t_list **last_check, \
				bool *is_in_pipeline)
{
	t_cmd	*cmd;

	cmd = (t_cmd *)node_cmd->content;
	if (cmd->type == CMD_TYPE_PIPE)
		*is_in_pipeline = true;
	executor_execute_cmd(shell, cmd, *is_in_pipeline);
	if (cmd->type != CMD_TYPE_PIPE)
	{
		*is_in_pipeline = false;
		//Hacemos los waits ya que  o es un unico proceso o es el final de una pipe....
		//cmd_debug(cmd);
		if (!finish_cmds(*last_check, node_cmd, shell))
			return (false);
		*last_check = node_cmd->next;
	}
	return (true);
}

bool	executor_execute_job(t_minishell *shell, t_job *job)
{
	t_list	*node;
	t_list	*last_check;
	bool	is_in_pipeline;

	node = job->cmds;
	last_check = node;
	is_in_pipeline = false;
	while (shell->run && node != NULL)
	{
		executor_jobs_loop(shell, node, &last_check, &is_in_pipeline);
		node = node->next;
	}
	//EN caso que sea modo stand alone, hemos de salir del shell.
	if (shell->mode == STANDALONE)
		shell->run = false;
	return (true);
}