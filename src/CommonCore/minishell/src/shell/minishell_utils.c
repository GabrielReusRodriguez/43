/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 22:48:29 by gabriel           #+#    #+#             */
/*   Updated: 2024/11/09 00:19:22 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include "minishell.h"
#include "fd.h"
#include "env/environment.h"

bool	minishell_init(t_minishell *shell, const char **env)
{
	shell->run = true;
	shell->last_status = EXIT_SUCCESS;
	shell->cmd = NULL;
	shell->mode = INTERACTIVE;
	shell->last_status = EXIT_SUCCESS;
	if (!env_load(&shell->env, env))
		return (false);
	//env_load(shell->)
	if (!fd_copy(STDIN_FILENO, &shell->config.fd_copy_stdin))
		return (false);
	if (!fd_copy(STDOUT_FILENO, &shell->config.fd_copy_stdout))
		return (false);
	return (true);
}

bool	minishell_destroy(t_minishell *shell)
{
	if (shell->cmd != NULL)
	{
		free(shell->cmd);
		shell->cmd = NULL;
	}
	if (shell->env.vars != NULL)
		env_destroy(&shell->env);
	if (!fd_close(shell->config.fd_copy_stdin) || \
			!fd_close(shell->config.fd_copy_stdout))
		return (false);
	return (true);
}
