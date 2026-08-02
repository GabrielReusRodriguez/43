/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_pathfile.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 21:04:03 by gabriel           #+#    #+#             */
/*   Updated: 2024/12/22 19:45:14 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <unistd.h>

#include "minishell.h"
#include "cmd.h"
#include "path.h"

#include <stdio.h>


static bool	try_path_folders(t_cmd *cmd, char **folders, char **pathname)
{
	int		i;
	char 	*cmd_path;
	char *aux;

	i = 0;
	while(folders[i] != NULL)
	{
//		printf("\t\tPRobamos carpeta : _%s_\n", folders[i]);
		aux = ft_strjoin(folders[i], "/");
		if (aux == NULL)
			return (false); 
		cmd_path = ft_strjoin(aux, cmd->executable);
		free(aux);
		if (cmd_path == NULL)
			return(ft_err_errno(NULL), false);
		if (path_check_mask(cmd_path, F_OK | X_OK, false))
		{
			*pathname = cmd_path;
			break;
		}
		free (cmd_path);
		i++;
	}
	return (true);
}

/*
bool	env_get_var(t_environment env, const char *key, char **value)
*/
bool	path_get_pathname(t_minishell *shell, t_cmd *cmd, char **pathname)
{
	char	*path;
	char	**folders;

	*pathname = NULL;
	path = NULL;
	if (path_check_mask(cmd->executable, F_OK | X_OK, false))
	{
		*pathname = ft_strdup(cmd->executable);
		return (true);
	}
	if (!env_get_var(shell->env, "PATH", &path))
		return (false);
	folders = ft_split(path, ':');
	free (path);
	if (folders == NULL)
		return (ft_err_errno(NULL), false);
	if (!try_path_folders(cmd, folders, pathname))
	{
		ft_ptr_free_dchar_ptr(folders);
		return (false);
	}
	ft_ptr_free_dchar_ptr(folders);
	return (true);
}