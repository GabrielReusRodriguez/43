/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 23:48:04 by greus-ro          #+#    #+#             */
/*   Updated: 2024/04/14 23:59:54 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#include "ft_args.h"
#include "ft_philosopher.h"
#include "ft_table.h"
#include "ft_log.h"
#include "ft_threads.h"
#include "ft_forkproc.h"

void	*ft_main_check_deads(void *arg)
{
	t_table	*table;

	table = (t_table *)arg;
	sem_wait(table->sem_dead);
	sem_post(table->sem_end);
	return (NULL);
}

void	*ft_main_check_meals(void *arg)
{
	t_table	*table;
	size_t	i;

	table = (t_table *)arg;
	i = 0;
	while (i < table->philosophers_set.total)
	{
		if (sem_wait(table->sem_meal) < 0)
		{
			printf("ERROR at semaphor waitting\n");
			break ;
		}
		i++;
	}
	sem_post(table->sem_end);
	return (NULL);
}

void	ft_main_run_simulation(t_table *table)
{
	pthread_t	deads_thread;
	pthread_t	meals_thread;

	if (ft_threads_createthread(&deads_thread, ft_main_check_deads, table) < 0)
	{
		ft_forkproc_killall(table->philosophers_set);
		exit(EXIT_FAILURE);
	}
	if (ft_threads_createthread(&meals_thread, ft_main_check_meals, table) < 0)
	{
		ft_forkproc_killall(table->philosophers_set);
		exit(EXIT_FAILURE);
	}
	if (sem_wait(table->sem_end) < 0)
	{
		ft_forkproc_killall(table->philosophers_set);
		exit(EXIT_FAILURE);
	}
	ft_forkproc_killall(table->philosophers_set);
}

int	ft_main_check_init(t_table *table)
{
	if (table->philosophers_set.philosophers == NULL || \
			table->num_forks <= 0)
	{
		ft_table_destroy(table);
		return (-1);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_args		args;
	t_table		table;

	if (ft_args_validate_format(argv, argc) == FALSE)
		return (EXIT_FAILURE);
	args = ft_args_parse(argv, argc);
	if (ft_args_validate_value(args) == FALSE)
		return (EXIT_FAILURE);
	table = ft_table_init(args);
	if (ft_main_check_init(&table) == -1)
		return (EXIT_FAILURE);
	ft_forkproc_create_proc(&table);
	ft_main_run_simulation(&table);
	ft_forkproc_wait(table.philosophers_set);
	ft_table_destroy(&table);
	return (0);
}
