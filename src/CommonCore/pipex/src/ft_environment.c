/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_environment.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 01:31:03 by greus-ro          #+#    #+#             */
/*   Updated: 2024/11/02 18:28:32 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "ft_environment.h"

char	**ft_env_getpath(char **env)
{
	char	**path;
	char	*folders;
	size_t	i;

	i = 0;
	while (env[i] != NULL && ft_strncmp(env[i], "PATH=", 5))
		i++;
	if (env[i] == NULL)
		return (NULL);
	folders = ft_substr(env[i], 5, ft_strlen(env[i]) - 5);
	if (folders == NULL)
		return (NULL);
	path = ft_split(folders, ':');
	free(folders);
	if (path != NULL)
	{
		i = 0;
		while (path[i] != NULL)
		{
			folders = path[i];
			path[i] = ft_strjoin(path[i], "/");
			free (folders);
			i++;
		}
	}
	return (path);
}

t_env	ft_env_new(char *envp[])
{
	t_env	environment;

	environment.env = envp;
	environment.path = ft_env_getpath(envp);
	return (environment);
}
