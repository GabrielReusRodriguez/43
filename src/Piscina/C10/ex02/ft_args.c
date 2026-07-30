/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 21:29:07 by greus-ro          #+#    #+#             */
/*   Updated: 2023/12/08 22:39:14 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_string.h"
#include "ft_numbers.h"

#include <stdio.h>

char	**ft_get_files_from_args(int num_files, char **argv)
{
	char	**ptr;
	int		i;

	ptr = (char **)malloc((num_files + 1) * sizeof(char *));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < num_files)
	{
		ptr[i] = argv[i];
		i++;
	}
	ptr[i] = NULL;
	return (ptr);
}

char	**ft_parse_args(char **argv, int argc, int *num_bytes)
{
	char	**ptr;
	int		num_files;
	int		init_files;

	ptr = NULL;
	num_files = argc - 1;
	init_files = 1;
	if (argc >= 4)
	{
		if (ft_strcmp("-c", argv[1]) == 0)
		{
			*num_bytes = ft_atoi(argv[2]);
			num_files = num_files -2;
			init_files = 3;
		}
	}
	ptr = ft_get_files_from_args(num_files, (argv + init_files));
	return (ptr);
}
