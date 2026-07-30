/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:13:09 by greus-ro          #+#    #+#             */
/*   Updated: 2024/01/05 17:40:57 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_put.h"
#include "ft_file.h"

static int	ft_display_file(char *file)
{
	int	fd;
	int	error;

	fd = ft_open_file(file);
	if (fd < 0)
	{
		return (3);
	}
	error = ft_read_file(fd);
	close(fd);
	return (error);
}

int	main(int argc, char **argv)
{
	int	error;

	if (argc == 1)
	{
		ft_putline("File name missing.");
		return (1);
	}
	if (argc > 2)
	{
		ft_putline("Too many arguments.");
		return (2);
	}
	error = ft_display_file(argv[1]);
	if (error != 0)
	{
		ft_putline("Cannot read file.");
		return (1);
	}
	return (0);
}
