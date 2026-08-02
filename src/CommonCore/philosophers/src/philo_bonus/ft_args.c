/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 00:14:51 by greus-ro          #+#    #+#             */
/*   Updated: 2024/04/12 13:28:20 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_args.h"
#include "ft_utils.h"

t_bool	ft_args_validate_format(char **argv, int argc)
{
	size_t	i;

	if (argc < 5 || argc > 6)
	{
		ft_utils_print(STDERR_FILENO, "Invalid number of args\n");
		return (FALSE);
	}
	i = 1;
	while (i < (size_t)argc)
	{
		if (ft_utils_contains_num(argv[i]) == FALSE)
		{
			ft_utils_print(STDERR_FILENO, "Invalid format of args\n");
			return (FALSE);
		}
		i++;
	}
	return (TRUE);
}

t_args	ft_args_parse(char **argv, int argc)
{
	t_args	args;

	args.num_philo = ft_utils_atoi(argv[1]);
	args.time_to_die = ft_utils_atoi(argv[2]);
	args.time_to_eat = ft_utils_atoi(argv[3]);
	args.time_to_sleep = ft_utils_atoi(argv[4]);
	if (argc == 6)
		args.num_must_eat = ft_utils_atoi(argv[5]);
	else
		args.num_must_eat = -1;
	return (args);
}

static t_bool	ft_args_validate_optional_value(t_args args)
{
	if (args.num_must_eat == 0)
	{
		ft_utils_print(STDERR_FILENO, \
			"Invalid number of times each philosopher must eat\n");
		return (FALSE);
	}
	return (TRUE);
}

t_bool	ft_args_validate_value(t_args	args)
{
	if (args.num_philo <= 0)
	{
		ft_utils_print(STDERR_FILENO, "Invalid philosophers number\n");
		return (FALSE);
	}
	if (args.time_to_die <= 0)
	{
		ft_utils_print(STDERR_FILENO, "Invalid time to die\n");
		return (FALSE);
	}
	if (args.time_to_eat <= 0)
	{
		ft_utils_print(STDERR_FILENO, "Invalid time to eat\n");
		return (FALSE);
	}
	if (args.time_to_sleep <= 0)
	{
		ft_utils_print(STDERR_FILENO, "Invalid time to sleep\n");
		return (FALSE);
	}
	return (ft_args_validate_optional_value(args));
}
