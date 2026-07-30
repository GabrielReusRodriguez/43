/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 10:34:47 by greus-ro          #+#    #+#             */
/*   Updated: 2023/12/08 14:27:53 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <libgen.h>
#include "ft_string.h"
#include "ft_buffer.h"
#include "ft_file.h"

#define BUFFER_SIZE 30000

#include <stdio.h>
#include "ft_string.h"

int	ft_cat(char *file)
{
	int				fd;
	unsigned char	buffer[BUFFER_SIZE];
	int				bytes_read;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		return (-1);
	}
	bytes_read = -1;
	while (bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			return (-1);
		}
		write(1, buffer, bytes_read);
	}
	close(fd);
	return (0);
}

void	ft_print_error(char *name_program, char *file)
{
	ft_putstr(name_program);
	ft_putstr(": ");
	ft_putstr(file);
	ft_putstr(": ");
	ft_putline(strerror(errno));
}

int	main(int argc, char **argv)
{
	int		i;
	char	*name_program;

	if (argc < 2)
	{
		ft_putline("No files found");
		return (-1);
	}
	i = 1;
	name_program = basename(argv[0]);
	if (name_program == NULL)
	{
		ft_putline(strerror(errno));
		return (-1);
	}
	while (i < argc)
	{
		if (ft_cat(argv[i]) < 0)
			ft_print_error(name_program, argv[i]);
		i++;
	}
	return (0);
}
