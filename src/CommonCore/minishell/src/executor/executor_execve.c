/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_execve.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 22:20:07 by gabriel           #+#    #+#             */
/*   Updated: 2024/12/22 19:48:11 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "libft.h"
#include "minishell.h"
#include "cmd.h"
#include "env/environment.h"
#include "path.h"
#include "utils/string.h"

#include <stdio.h>

/*
static void	debug(char **vector)
{
	size_t	i;

	i = 0;
	printf("Debug...........\n");
	while (vector[i] != NULL)
	{
		printf("\t\t str _%s_\n", vector[i]);
		i++;
	}
	printf("NULL\n");
	printf("Debug ends.....\n");

}
*/

/*
int execve(const char *pathname, char *const _Nullable argv[],
                  char *const _Nullable envp[]);
*/
bool	executor_execve(t_minishell *shell, t_cmd *cmd)
{
	char	*pathname;
	char	**args;
	char	**envp;

	args = NULL;
	envp = NULL;
	if (!path_get_pathname(shell, cmd, &pathname))
	{
		ft_err_error("Error getting command path"	);
		exit (127);		
	}
	if (pathname == NULL)
	{
		ft_err_error("Command not found");
		exit(127);
	}
	if (!cmd_export_params(cmd, &args))
	{
		ft_err_error("Error treating command args");
		exit (EXIT_FAILURE);
	}
	if (!utils_dchar_append_front(&args, cmd->executable))
		exit(EXIT_FAILURE);
	if (!env_to_char_ptr(shell, &envp))
	{
		ft_err_error("Error treating environment");
		exit (EXIT_FAILURE);
	}
//	printf("Args\n");
//	debug(args);
//	printf("Environment\n");
//	debug(envp);
//	printf("PATH : _%s_\n", pathname);
	if (execve(pathname, args, envp) < 0)
	{
		ft_ptr_free_dchar_ptr(envp);
		ft_ptr_free_dchar_ptr(args);
		free (pathname);
		ft_err_errno(NULL);
		exit(EXIT_FAILURE);
	}
	return (true);
}