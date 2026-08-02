/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 19:37:43 by gabriel           #+#    #+#             */
/*   Updated: 2024/12/26 19:21:19 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <unistd.h>

#include "cmd.h"
#include "minishell.h"
#include "executor.h"

bool	executor_execute_cmd(t_minishell *shell, t_cmd *cmd, bool is_pipeline)
{
	if (is_pipeline)
		return (execute_cmd_pipeline(shell, cmd));
	else
		return (execute_cmd_non_pipeline(shell, cmd));
}