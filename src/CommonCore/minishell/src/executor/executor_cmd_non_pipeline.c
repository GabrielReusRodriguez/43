/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_cmd_non_pipeline.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 19:15:36 by gabriel           #+#    #+#             */
/*   Updated: 2025/01/01 23:09:51 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

#include "minishell.h"
#include "cmd.h"
#include "fd.h"
#include "builtins.h"
#include "executor.h"


static bool	enable_redirection(int fd_origin, int fd_dest)
{
	if (fd_origin != FD_NONE)
	{
		if (!fd_replace(fd_origin, fd_dest))
			return (false);
		if (!fd_close(fd_origin))
		return (false);
	} 
	return (true);
}

static bool	execute_builtin_non_pipe(t_minishell *shell, t_cmd *cmd)
{
	bool	result;

	if (!enable_redirection(cmd->fd_out, STDOUT_FILENO))
		return (false);
	result = execute_builtin(cmd, shell, false);
	if (cmd->fd_out != FD_NONE)
		if (!fd_replace(shell->config.fd_copy_stdout, STDOUT_FILENO))
			return (false);
	return (result);
}

bool	execute_cmd_non_pipeline(t_minishell *shell, t_cmd *cmd)
{
	cmd->pid = CMD_NO_PID;
	if (!cmd_prepare_redirs(cmd))
		return (false);
	if (is_builtin(cmd))
		return (execute_builtin_non_pipe(shell, cmd));
	cmd->pid = fork();
	if (cmd->pid < 0)
		return (ft_err_errno(NULL),false);
	else
	{
		//En caso del hijo....
		if (cmd->pid  == 0)
		{
			if (!enable_redirection(cmd->fd_out, STDOUT_FILENO))
				return (false);
			if (!enable_redirection(cmd->fd_in, STDIN_FILENO))
				return (false);
			if (!executor_execve(shell, cmd))
				exit(EXIT_FAILURE);
		}
		else
		{
			//Padre...
//			if (!fd_replace(shell->config.fd_copy_stdout, STDOUT_FILENO))
//				return (false);
//			if (!fd_replace(shell->config.fd_copy_stdin, STDIN_FILENO))
//				return (false);
		}
	}
	return (true);
}
