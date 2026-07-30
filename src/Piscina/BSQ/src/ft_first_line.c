/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_first_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:27:21 by greus-ro          #+#    #+#             */
/*   Updated: 2023/12/11 17:37:42 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../headers/ft_map.h"
#include "../headers/ft_numbers.h"
#include "../headers/ft_string.h"
#include "../headers/ft_bool.h"

#define BUFFER_SIZE 100
#include <stdio.h>


int ft_parse_char(int fd, char *character)
{
	char    c;
	int     bytes_read;
	bytes_read = read(fd, &c, 1);
	if (bytes_read < 0)
		return (bytes_read);
	*character = c;
	return (bytes_read);
}


int ft_parse_first_line(int fd, t_map *map)
{
	int     bytes_read;
	char    buffer[BUFFER_SIZE];
	int     i;
	char    c;

	i = 0;
	c = '0';
	while (c >= '0' && c <= '9')
	{
		buffer[i++] = c;
		bytes_read = read(fd,&c,1);
		if (bytes_read <= 0 )
			return (bytes_read);
	}
	buffer[i] = '\0';
	map->lines = ft_atoi(buffer);
	map->empty = c;
	bytes_read = ft_parse_char(fd, &(map->obstacle));
	if (bytes_read <= 0 )
		return (bytes_read);
	bytes_read = ft_parse_char(fd, &(map->full));
	if (bytes_read <= 0 )
		return (bytes_read);
	bytes_read = read(fd,&c,1);
	if (bytes_read <= 0 )
		return (bytes_read);
	return (1);
}


/*
int    ft_parse_first_line(int fd, t_map *map)
{
	int 	flags;
	char	newline;

	flags = ft_parse_num_lines(fd,map);
	if (flags <= 0)
		return (flags);
	flags = ft_parse_char(fd,&(map->empty));
	printf("Return %d valor %c\n",flags,map->empty);
	if (flags <= 0)
		return (flags);
	flags = ft_parse_char(fd,&(map->obstacle));
	printf("Return %d valor %c\n",flags,map->obstacle);
	if (flags <= 0)
		return (flags);
	flags = ft_parse_char(fd,&(map->full));
	printf("Return %d valor %c\n",flags,map->full);
	if (flags <= 0)
		return (flags);
	read(fd,&newline,1);
	return (0);
}
*/
