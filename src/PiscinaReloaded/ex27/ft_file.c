/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:21:50 by greus-ro          #+#    #+#             */
/*   Updated: 2024/01/05 17:37:28 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "ft_buffer.h"

int	ft_open_file(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	return (fd);
}

int	ft_read_file(int fd)
{
	unsigned char	buffer[BUFFER_SIZE];
	unsigned int	bytes_read;

	ft_buffer_clear(buffer, BUFFER_SIZE);
	bytes_read = read(fd, &buffer, 1);
	while (bytes_read > 0)
	{
		write(1, &buffer, bytes_read);
		bytes_read = read(fd, &buffer, bytes_read);
	}
	return (bytes_read);
}
