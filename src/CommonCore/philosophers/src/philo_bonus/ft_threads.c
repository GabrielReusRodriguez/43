/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_threads.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 16:08:43 by greus-ro          #+#    #+#             */
/*   Updated: 2024/04/14 23:57:13 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_philosopher.h"
#include "ft_table.h"
#include "ft_timestamp.h"
#include "ft_log.h"
#include "ft_semaphores.h"

void	*ft_threads_check_philo_dead(void *args)
{
	t_timestamp		now;
	t_philosopher	*philo;
	t_timestamp		last_meal;

	philo = (t_philosopher *)args;
	philo->meals.timestamp = philo->start_time;
	while (TRUE)
	{
		ft_semaphore_wait(philo->sem_check_meal, philo->sem_end);
		last_meal = philo->meals.timestamp;
		ft_semaphore_post(philo->sem_check_meal, philo->sem_end);
		now = ft_timestamp_get();
		if (now - last_meal > philo->rules.time_to_die)
		{
			ft_log(philo, "died", now - philo->start_time);
			ft_semaphore_wait(philo->sem_console, philo->sem_end);
			ft_semaphore_post(philo->sem_dead, philo->sem_end);
			exit(EXIT_SUCCESS);
		}
	}
	return (NULL);
}

void	*ft_threads_check_philo_meal(void *args)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)args;
	while (TRUE)
	{
		if (philo->meals.num_meals >= philo->rules.number_eats)
		{
			ft_semaphore_post(philo->sem_meal_condition, philo->sem_end);
			break ;
		}
	}
	return (NULL);
}

void	*ft_threads_check_meals(void *args)
{
	size_t	i;
	t_table	*table;

	table = (t_table *)args;
	i = 0;
	while (i < table->philosophers_set.total)
	{
		if (sem_wait(table->sem_meal) < 0)
		{
			sem_post(table->sem_end);
			break ;
		}
		i++;
	}
	return (NULL);
}
