/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 00:59:00 by gabriel           #+#    #+#             */
/*   Updated: 2024/12/26 19:38:07 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "libft.h"
#include "cmd.h"


int	builtin_count_params(char **params)
{
	int		num;

	num = 0;
	if (params == NULL)
		return (0);
	while(params[num] != NULL)
		num++;
	return (num);
}

bool	is_builtin(t_cmd *cmd)
{
	if (ft_strcmp(BUILTIN_CD, cmd->executable) == 0)
		return (true);
	if (ft_strcmp(BUILTIN_DECLARE, cmd->executable) == 0)
		return (true);
	if (ft_strcmp(BUILTIN_ECHO, cmd->executable) == 0)
		return (true);
	if (ft_strcmp(BUILTIN_ENV, cmd->executable) == 0)
		return (true);
	if (ft_strcmp(BUILTIN_EXIT, cmd->executable) == 0)
		return (true);
	if (ft_strcmp(BUILTIN_EXPORT, cmd->executable) == 0)
		return (true);
	if (ft_strcmp(BUILTIN_PWD, cmd->executable) == 0)
		return (true);
	if (ft_strcmp(BUILTIN_UNSET, cmd->executable) == 0)
		return (true);
	return (false);
}

bool	execute_builtin(t_cmd *cmd, t_minishell *shell, bool is_pipeline)
{
	char	**params;

	params = NULL;
	if(!cmd_export_params(cmd, &params))
		return (false);
	if (ft_strcmp(BUILTIN_ENV, cmd->executable)  == 0)
		builtin_env(params, shell, cmd, is_pipeline);
	if (ft_strcmp(BUILTIN_EXIT, cmd->executable) == 0)
		builtin_exit(params, shell, cmd, is_pipeline);
	if (ft_strcmp(BUILTIN_EXPORT, cmd->executable) == 0)
		builtin_export(params, shell, cmd, is_pipeline);
	if (ft_strcmp(BUILTIN_ECHO, cmd->executable) == 0)
		builtin_echo(params, shell, cmd, is_pipeline);
	ft_ptr_free_dchar_ptr(params);
	return (true);
}