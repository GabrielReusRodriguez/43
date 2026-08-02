/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 00:26:28 by gabriel           #+#    #+#             */
/*   Updated: 2024/12/25 23:02:42 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "minishell.h"
#include "cmd.h"

static void	builtin_env_print_var(t_pair pair)
{
	ft_putstr_fd(pair.key,STDOUT_FILENO);
	ft_putstr_fd("=", STDOUT_FILENO);
	ft_putendl_fd(pair.value, STDOUT_FILENO);
}


bool	builtin_env(char **params, t_minishell *shell, t_cmd *cmd, bool is_pipeline)
{
	t_list	*node;
	t_pair	*pair;

	(void)params;
	(void)cmd;
	(void)is_pipeline;
	node = shell->env.vars;
	while (node != NULL)
	{
		pair = (t_pair *)node->content;
		builtin_env_print_var(*pair);
		node = node->next;
	}
	return (true);
}