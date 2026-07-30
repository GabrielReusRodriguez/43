/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:24:18 by greus-ro          #+#    #+#             */
/*   Updated: 2024/11/02 19:42:11 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#include "libft.h"

char	*ft_utils_which(char	**cmd_args, char **path)
{
	char	*cmd_path;
	size_t	i;

	cmd_path = NULL;
	if (access(cmd_args[0], F_OK) == 0)
		cmd_path = ft_strdup(cmd_args[0]);
	else
	{
		i = 0;
		while (path[i] != NULL)
		{
			cmd_path = ft_strjoin(path[i], cmd_args[0]);
			if (access(cmd_path, F_OK) == 0)
				return (cmd_path);
			free(cmd_path);
			i++;
		}
		return (NULL);
	}
	return (cmd_path);
}