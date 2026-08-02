/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 23:01:15 by gabriel           #+#    #+#             */
/*   Updated: 2024/11/09 00:40:40 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>
#include "libft.h"
#include "minishell.h"

static bool main_get_cmd_from_param(char **argv, char **cmd)
{

	*cmd = ft_strdup(argv[2]);
	if (*cmd == NULL)
	{
		ft_err_errno(NULL);
		return (false);
	}
	return (true);
}

static bool	main_init(t_minishell *shell, const char **env)
{
	if (!minishell_init(shell, env))
		return (false);
	return (true);
}

static bool	main_destroy(t_minishell *shell)
{
	if(!minishell_destroy(shell))
		return (false);
	return(true);
}

int	main(int argc, char **argv, char **env)
{
	t_minishell		shell;
	unsigned char	status;

	if (!main_init(&shell, (const char **)env))
			return (EXIT_FAILURE);
	if (argc > 2 && ft_strcmp("-c", argv[1]) == 0)
	{
		shell.mode = STANDALONE;
		if (!main_get_cmd_from_param(argv, &shell.cmd))
			return (EXIT_FAILURE);	
	}
	while (shell.run)
	{
		if (!minishell_loop(&shell))
			shell.run = false;
	}
	status = shell.last_status;
	main_destroy(&shell);
	return (status);
}