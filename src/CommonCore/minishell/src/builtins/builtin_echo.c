/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 18:02:21 by gabriel           #+#    #+#             */
/*   Updated: 2024/12/26 19:05:19 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <unistd.h>

#include "minishell.h"
#include "cmd.h"
#include "libft.h"


static bool	is_n_flag(char *param)
{
	size_t	i;

	i = 0;
	if (param != NULL && ft_strlen(param) > 1)
	{
		if (param[i] == '-')
		{
			i++;
			while (param[i] != '\0')
			{
				if (param[i] != 'n')
					return (false);
				i++;
			}
			return (true);
		}
	}
	return (false);
}

bool	builtin_echo(char **params, t_minishell *shell, t_cmd *cmd, \
			bool is_pipeline)
{
	bool	has_n_flag;
	bool	has_printed;
	size_t	i;

	i = 0;
	(void)shell;
	(void)cmd;
	(void)is_pipeline;
	has_n_flag = false;
	has_printed = false;
	while (params[i] != NULL)
	{
		if (is_n_flag(params[i]))
		{
			has_n_flag = true;
			i++;
			continue;
		}
		if (has_printed)
			if (ft_iputstr_fd(" ", STDOUT_FILENO) < 0)
			{
				cmd->return_value = EXIT_FAILURE;
				return (ft_err_errno(NULL), false);
			}
		has_printed = true;
		if (ft_iputstr_fd(params[i], STDOUT_FILENO) < 0)
		{
			cmd->return_value = EXIT_FAILURE;
			return (ft_err_errno(NULL), false);
		}
		i++;
	}
	if (!has_n_flag)
	{
		if (ft_iputstr_fd("\n",STDOUT_FILENO) < 0)
		{
			cmd->return_value = EXIT_FAILURE;
			return (ft_err_errno(NULL), false);
		}
	}
	cmd->return_value = EXIT_SUCCESS;
	return (true);
}
