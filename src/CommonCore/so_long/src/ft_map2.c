/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 23:59:33 by gabriel           #+#    #+#             */
/*   Updated: 2024/03/03 18:56:55 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "ft_get_next_line.h"
#include "libft.h"
#include "ft_error.h"

static char	*ft_read_map_line(int fd, char **map)
{
	char	*line;
	char	*aux;

	line = ft_get_next_line_many_fds(fd);
	if (line != NULL)
	{
		if (ft_strncmp(line, "\n", 1) == 0)
		{
			free (line);
			free (*map);
			*map = NULL;
			return (NULL);
		}
		aux = *map;
		*map = ft_strjoin(*map, line);
		free(aux);
		free(line);
	}
	return (line);
}

char	*ft_read_map_file(const char *map_file)
{
	int		fd;
	char	*line;
	char	*map;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
	{
		ft_error_print_errno();
		return (NULL);
	}
	map = (char *)ft_calloc(1, 1);
	if (map == NULL)
	{
		ft_error_print_code(ENOMEM);
		return (NULL);
	}
	line = (char *)map_file;
	while (line != NULL)
		line = ft_read_map_line(fd, &map);
	close(fd);
	if (map != NULL && ft_strlen(map) == 0)
		return (ft_ptr_free(map));
	return (map);
}
