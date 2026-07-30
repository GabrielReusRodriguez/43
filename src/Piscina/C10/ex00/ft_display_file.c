/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 09:29:02 by greus-ro          #+#    #+#             */
/*   Updated: 2023/12/08 12:58:25 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

#define BUFFER_SIZE 100

void	ft_putstr(unsigned char *str)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
	write(1, "\n", 1);
}

void	ft_clean_buffer(unsigned char *buffer, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		buffer[i] = '\0';
		i++;
	}
}

void	ft_display_file(char *file)
{
	int				fd;
	int				bytes_read;
	unsigned char	buffer[BUFFER_SIZE];
	int				buffer_size;

	buffer_size = BUFFER_SIZE;
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr((unsigned char *)"Cannot read file.");
		return ;
	}
	bytes_read = -1;
	while (bytes_read != 0)
	{
		ft_clean_buffer(buffer, buffer_size);
		bytes_read = read(fd, buffer, buffer_size);
		write(1, buffer, bytes_read);
	}
	close(fd);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		ft_putstr((unsigned char *)"File name missing.");
		return (1);
	}
	if (argc > 2)
	{
		ft_putstr((unsigned char *)"Too many arguments.");
		return (1);
	}
	ft_display_file(argv[1]);
	return (0);
}
