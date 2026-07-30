/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 21:12:42 by greus-ro          #+#    #+#             */
/*   Updated: 2023/12/08 22:37:33 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_args.h"
#include "ft_put.h"
#include "ft_tail_program.h"

#include <stdio.h>

int	main(int argc, char **argv)
{
	int		num_bytes;
	char	**files;
	int		i;

	if (argc < 4)
	{
		ft_putline("No files found");
		return (-1);
	}
	files = ft_parse_args(argv, argc, &num_bytes);
	i = 0;
	while (files[i] != NULL)
	{
		ft_tail_program(files[i], num_bytes);
		i++;
	}
	return (0);
}
