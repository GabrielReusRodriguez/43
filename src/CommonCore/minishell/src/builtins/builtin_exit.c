/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 21:29:51 by gabriel           #+#    #+#             */
/*   Updated: 2024/12/25 23:02:07 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "minishell.h"
#include "builtins.h"

static bool	validate_params(char **params)
{
	char 	*arg;
	int		i;
	bool	sign;

	arg = params[0];
	i = 0;
	sign = false;
	while (arg[i] != '\0')
	{
		if (sign && (arg[i] == '-' || arg[i] == '+'))
			return (false);
		if (arg[i] == '-' || arg[i] == '+')
			sign = true;
		if (ft_isdigit(arg[i]) != 1)
			return (false);
		i++;
	}	
	return (true);
}

static bool	builtin_process_with_args(char **params, t_minishell *shell, t_cmd *cmd, bool is_pipeline)
{
	if (!validate_params(params))
		return (ft_err_error("A numeric args is required"), false);
	cmd->return_value =  ft_atoi(params[0]);
	if (!is_pipeline)
		shell->run = false;
	return (true);	
}

bool	builtin_exit(char **params, t_minishell *shell, t_cmd *cmd, bool is_pipeline)
{
	int	num_params;

	num_params = builtin_count_params(params);
	if (num_params < 2)
	{
		if (num_params == 0)
		{
			cmd->return_value = EXIT_SUCCESS;
			if (!is_pipeline)
				shell->run = false;
			return (true);
		}
		else
			return (builtin_process_with_args(params, shell, cmd, is_pipeline));
	}
	else
	{
		ft_err_error("Too many args");
		return (true);
	}
	return (true);
}