/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:27:21 by greus-ro          #+#    #+#             */
/*   Updated: 2023/12/11 17:37:42 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "../headers/ft_buffer.h"
#include "../headers/ft_string.h"

#include <stdio.h>

#define BUFFER_SIZE 100

char	*ft_get_line(int fd, unsigned int *size)
{
	int					bytes_read;
	char				*line;
	char				buffer[BUFFER_SIZE];
	char 				c;
	unsigned int		i;

	i = 0;
	ft_clear_buffer(buffer, BUFFER_SIZE);
	c = ' ';
	*size = 0;
	bytes_read = read(fd, &c, 1);
	if (bytes_read < 0)
		return (NULL);
	while (c != '\n' && c != '\0' && bytes_read != 0)
	{
		buffer[i] = c;
		i++;
		*size= *size + 1;
		bytes_read = read(fd, &c, 1);
		if (bytes_read < 0)
			return (NULL);
	}
	buffer[i] = '\0';
	line = (char *)malloc(*size);
	if (line == NULL)
		return (NULL);
	ft_strncpy(line, buffer, *size);
	line[*size] = '\0';
	return (line);
}

/*
char	*ft_get_line(int fd, unsigned int *size, int *last_bytes_read)
{
	int					bytes_read;
	char				*line;
	char				buffer[BUFFER_SIZE];
	char 				c;
	unsigned int		i;

	i = 0;
	ft_clear_buffer(buffer, BUFFER_SIZE);
	c = ' ';
	*size = 0;
	bytes_read = read(fd, &c, 1);
	if (bytes_read < 0)
		return (NULL);
	*last_bytes_read = bytes_read;
	while (c != '\n' && c != '\0' && bytes_read != 0)
	{
		buffer[i] = c;
		i++;
		*size= *size + 1;
		bytes_read = read(fd, &c, 1);
		if (bytes_read < 0)
			return (NULL);
		*last_bytes_read = bytes_read;
	}
	buffer[i] = '\0';
	line = (char *)malloc(*size);
	if (line == NULL)
		return (NULL);
	ft_strncpy(line, buffer, *size);
	line[*size] = '\0';
	return (line);
}
*/
