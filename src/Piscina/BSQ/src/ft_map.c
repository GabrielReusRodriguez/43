/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:27:21 by greus-ro          #+#    #+#             */
/*   Updated: 2023/12/11 17:37:42 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "../headers/ft_map.h"
#include "../headers/ft_put.h"
#include "../headers/ft_numbers.h"
#include "../headers/ft_first_line.h"
#include "../headers/ft_line.h"

#include <stdio.h>

t_map	*ft_load_map(char *file)
{
	t_map 				*map;
	int					fd;
	unsigned int		i;
	//char	*line;
	//int					last_bytes_read;

	map = (t_map *)malloc(sizeof(t_map));
	if(map == NULL)
		return (NULL);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	if(ft_parse_first_line(fd, map) < 0)
	{
		close(fd);
		return (NULL);
	}
	map->map = (char **)malloc(map->lines*sizeof(char *));
	if (map->map == NULL)
		return (NULL);
	i = 0;
	while(i < map->lines)
	{
		map->map[i] = ft_get_line(fd, &(map->rows));
		if(map->map == NULL)
		{
			close(fd);
			return (NULL);
		}
		//printf("La linea es: %s\n",map->map[i]);
		i++;
	}
	close(fd);
	return (map);
}

t_rectangle	*ft_get_next_rectangle(t_map map, t_point  initial)
{
	t_rectangle	*rectangle;
	//int			i;
	//int			j;
	map.lines++;
	initial.x++;
	rectangle = NULL;
/*	i = initial.x;
	j = initial.y;
*/
	return (rectangle);
}

void	ft_print_map(t_map *map)
{
	unsigned int	i;

	ft_putstr("Lineas: ");
	ft_putnbr(map->lines);
	ft_putchar('\n');
	ft_putstr("Empty: ");
	ft_putchar(map->empty);
	ft_putchar('\n');
	ft_putstr("Full: ");
	ft_putchar(map->full);
	ft_putchar('\n');
	ft_putstr("Obstacle: ");
	ft_putchar(map->obstacle);
	ft_putchar('\n');
	ft_putchar('\n');
	ft_putline("MAPA: ");
	i = 0;
	while (i < map->lines)
	{
		ft_putline(map->map[i]);
		i++;
	}
}

void	ft_free_map(t_map *map)
{
	unsigned int	i;

	i = 0;
	if (map != NULL)
	{
		while (i < map->lines)
		{
			if (map->map[i] != NULL)
				free (map->map[i]);
			i++;
		}
		free (map);
	}
}