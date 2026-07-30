/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail_program.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:01:59 by greus-ro          #+#    #+#             */
/*   Updated: 2023/12/08 22:04:05 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include "ft_put.h"
#include "ft_buffer.h"

#include <stdio.h>

#define SIZE_BUFFER 1024

void	ft_append_char(char *buffer, char character, unsigned int num_bytes, \
	unsigned int *position)
{
	if (*position < num_bytes - 1)
	{
		buffer[*position] = character;
		*position = *position + 1;
		return ;
	}
	else
	{
		ft_shift_buffer(buffer, character, num_bytes);
	}
}

char	*ft_parse_file(int fd, unsigned int num_bytes)
{
	char			*buffer;
	unsigned int	i;
	char			read_char;
	int				bytes_read;

	buffer = (char *)malloc(num_bytes + 1);
	if (buffer == NULL)
		return (NULL);
	ft_clean_buffer(buffer, num_bytes);
	i = 0;
	bytes_read = 2;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, &read_char, 1);
		if (bytes_read < 0)
		{
			strerror(errno);
			return (NULL);
		}
		if (bytes_read > 0)
			ft_append_char(buffer, read_char, num_bytes, &i);
	}
	buffer[num_bytes] = '\0';
	return (buffer);
}

void	ft_tail_program(char *file, unsigned int num_bytes)
{
	char	*lines;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		strerror(errno);
		return ;
	}
	lines = ft_parse_file(fd, num_bytes);
	ft_putstr(lines);
	close(fd);
}
