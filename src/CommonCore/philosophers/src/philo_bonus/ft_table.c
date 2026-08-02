/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_table.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 16:08:30 by greus-ro          #+#    #+#             */
/*   Updated: 2024/04/14 23:46:06 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include "ft_table.h"
#include "ft_args.h"
#include "ft_semaphores.h"

void	ft_table_destroy(t_table *table)
{
	if (table->philosophers_set.philosophers != NULL)
	{
		ft_philosophers_destroy(&table->philosophers_set);
	}
	ft_semaphore_destroy(SEMAPHOR_CONSOLE, table->sem_console);
	ft_semaphore_destroy(SEMAPHOR_DEAD, table->sem_dead);
	ft_semaphore_destroy(SEMAPHOR_FORKS, table->sem_forks);
	ft_semaphore_destroy(SEMAPHOR_MEALS, table->sem_meal);
	ft_semaphore_destroy(SEMAPHOR_END, table->sem_end);
}

t_table	ft_table_init(t_args args)
{
	t_table	table;

	table.rules = ft_rules_init(args);
	table.num_forks = args.num_philo;
	table.philosophers_set = ft_philosophers_init(args, \
								table.rules);
	table.sem_console = ft_semaphore_create(SEMAPHOR_CONSOLE, 1);
	table.sem_meal = ft_semaphore_create(SEMAPHOR_MEALS, 0);
	table.sem_forks = ft_semaphore_create(SEMAPHOR_FORKS, args.num_philo);
	table.sem_dead = ft_semaphore_create(SEMAPHOR_DEAD, 0);
	table.sem_end = ft_semaphore_create(SEMAPHOR_END, 0);
	return (table);
}
