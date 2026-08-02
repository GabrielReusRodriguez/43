/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_forkproc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 16:07:09 by greus-ro          #+#    #+#             */
/*   Updated: 2024/04/14 23:55:55 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <unistd.h>
#include "ft_forkproc.h"
#include "ft_philosopher.h"
#include "ft_threads.h"
#include "ft_sleep.h"

static void	ft_forkproc_new_philo_sem(t_philosopher *philo)
{
	char	*num_philo;

	num_philo = ft_utils_itoa(philo->number);
	philo->name_sem_check_meal = ft_utils_strjoin("sem_check_meals", \
									num_philo);
	free (num_philo);
	if (philo->name_sem_check_meal == NULL)
		exit(EXIT_FAILURE);
	philo->sem_check_meal = ft_semaphore_create(philo->name_sem_check_meal, 1);
}

static void	ft_forkproc_copy_semaphores(t_table *table, t_philosopher *philo)
{
	philo->sem_console = table->sem_console;
	philo->sem_forks = table->sem_forks;
	philo->sem_meal_condition = table->sem_meal;
	philo->sem_dead = table->sem_dead;
	philo->sem_end = table->sem_end;
	ft_forkproc_new_philo_sem(philo);
}

static void	ft_forkproc_child(t_philosopher *philo)
{
	pthread_t	id;

	if (pthread_create(&id, NULL, ft_threads_check_philo_dead, \
						philo) < 0)
		exit(EXIT_FAILURE);
	if (pthread_detach(id) < 0)
		exit(EXIT_FAILURE);
	if (philo->rules.number_eats > 0)
	{
		if (pthread_create(&id, NULL, \
					ft_threads_check_philo_meal, philo) < 0)
			exit(EXIT_FAILURE);
		if (pthread_detach(id) < 0)
			exit(EXIT_FAILURE);
	}
	ft_philosopher_life((void *)philo);
	exit(EXIT_SUCCESS);
}

/*
	Here we create the fork  and at the child process we create the 
		checking threads for each child.
*/
int	ft_forkproc_create_proc(t_table *table)
{
	size_t			i;
	pid_t			pid;
	t_philosopher	*philo;

	i = 0;
	table->start_time = ft_timestamp_get();
	while (i < table->philosophers_set.total)
	{
		philo = table->philosophers_set.philosophers + i;
		philo->start_time = table->start_time;
		ft_forkproc_copy_semaphores(table, philo);
		if (i % 2 == 0)
			ft_sleep_micro(10);
		pid = fork();
		if (pid != 0)
		{
			if (pid < 0)
				exit(EXIT_FAILURE);
			philo->process = pid;
		}
		else
			ft_forkproc_child(philo);
		i++;
	}
	return (0);
}
