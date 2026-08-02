/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 22:14:40 by gabriel           #+#    #+#             */
/*   Updated: 2024/07/19 21:08:07 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdbool.h>

#include "rules.h"
#include "args.h"
#include "utils.h"

static bool	rules_validate_args(int argc, char **argv)
{
	int	i;

	if (argc < 4 || argc > 6)
	{
		ft_putendl(STDERR_FILENO, "ERROR: Invalid number of args");
		return (false);
	}
	i = 1;
	while (i < argc)
	{
		if (!args_validate_uint(argv[i]))
		{
			ft_putendl(STDERR_FILENO, "ERROR: Invalid format of args.");
			return (false);
		}
		i++;
	}
	return (true);
}

bool	rules_import_args(int argc, char **argv, t_rules *rules)
{
	if (!rules_validate_args(argc, argv))
		return (false);
	rules->number_of_philos = ft_atou(argv[1]);
	rules->time_to_die = ft_atou(argv[2]);
	rules->time_to_eat = ft_atou(argv[3]);
	rules->time_to_sleep = ft_atou(argv[4]);
	if (argc == 6)
		rules->number_of_meals = ft_atou(argv[5]);
	else
		rules->number_of_meals = 0;
	return (true);
}
