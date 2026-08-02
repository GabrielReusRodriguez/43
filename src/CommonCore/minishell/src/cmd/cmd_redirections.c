/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_redirections.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 20:31:58 by gabriel           #+#    #+#             */
/*   Updated: 2025/01/01 23:09:20 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "cmd.h"
#include "fd.h"
#include "pipe.h"

/*
static bool	prepare_input_redirs(t_cmd *cmd)
{
	if (!cmd_open_redir_inputs(cmd))
		return (false);
	if (cmd->fd_in != FD_NONE)
	{
		if (!fd_replace(cmd->fd_in, STDIN_FILENO))
			return (false);
	}
	return (true);
}

static bool	prepare_output_redirs(t_cmd *cmd)
{
	if (!cmd_open_redir_outputs(cmd))
		return (false);
	if (cmd->fd_out != FD_NONE)
	{
		if (!fd_replace(cmd->fd_out, STDOUT_FILENO))
			return (false);
	}
	return (true);
}
*/

static bool	prepare_input_redirs(t_cmd *cmd)
{	
	if (!cmd_open_redir_inputs(cmd))
		return (false);
	/*
	if (cmd->fd_in == FD_NONE)
	{
		if (pipe != NULL)
			cmd->fd_in = pipe->read;
//		else
//			return(fd_replace(shell->config.fd_copy_stdin, STDIN_FILENO));
	}
//	return(fd_replace(cmd->fd_in, STDIN_FILENO));
	*/
	return (true);
}

static bool	prepare_output_redirs(t_cmd *cmd)
{
	if (!cmd_open_redir_outputs(cmd))
		return (false);
	/*
	if (cmd->fd_out == FD_NONE)
	{
		if (pipe != NULL)
			cmd->fd_out = pipe->write;
//		else
//			return(fd_replace(shell->config.fd_copy_stdout, STDOUT_FILENO));
	}
	*/
	return (true);
//	return(fd_replace(cmd->fd_out, STDOUT_FILENO));
}

bool	cmd_prepare_redirs(t_cmd *cmd)
{
	if (!prepare_input_redirs(cmd))
	{
		cmd->return_value = EXIT_FAILURE;
		return (false);
	}
	if (!prepare_output_redirs(cmd))
	{
		cmd->return_value = EXIT_FAILURE;
		return (false);
	}
	return (true);
}
