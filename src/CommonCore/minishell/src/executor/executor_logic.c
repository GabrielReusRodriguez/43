/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_logic.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 20:29:36 by gabriel           #+#    #+#             */
/*   Updated: 2024/12/26 19:07:12 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "minishell.h"
#include "cmd.h"
#include "builtins.h"
#include "executor.h"

#include <stdio.h>

bool	executor_execute_logic(t_minishell *shell, t_cmd *cmd)
{
	if (is_builtin(cmd))
		return (execute_builtin(cmd, shell, true));
	else
	{
		cmd->return_value = EXIT_SUCCESS;
//		printf("PRE-execve logic\n");
		if (!executor_execve(shell, cmd))
			exit(EXIT_FAILURE);
	}
	return (true);
}