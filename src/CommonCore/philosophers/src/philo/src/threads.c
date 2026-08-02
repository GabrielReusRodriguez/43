/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 18:10:25 by gabriel           #+#    #+#             */
/*   Updated: 2024/07/23 00:32:12 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <pthread.h>
#include <unistd.h>

#include "simulation.h"
#include "utils.h"
#include "timestamp.h"

bool	threads_create(t_simulation *simulation)
{
	size_t			i;
	t_philosopher	*philo;

	i = 0;
	simulation->mtx_run.value = true;
	if (!get_timestamp(&simulation->time_of_start))
		return (ft_putendl(STDERR_FILENO, "ERROR: Error getting time."), \
					false);
	while (i < simulation->rules.number_of_philos)
	{
		philo = &simulation->philos[i];
		philo->time_of_start = simulation->time_of_start;
		philo->mtx_time_last_eat.value = simulation->time_of_start;
		if (pthread_create(&philo->thread_id, NULL, philo_life, philo) < 0)
		{
			ft_putendl(STDERR_FILENO, "ERROR: Error creating thread.");
			simulation_force_stop(&simulation->mtx_run);
			return (false);
		}
		i++;
	}
	return (true);
}

bool	threads_join(t_simulation *simulation)
{
	size_t			i;
	t_philosopher	*philo;

	i = 0;
	while ( i < simulation->rules.number_of_philos)
	{
		philo = &simulation->philos[i];
		if (pthread_join(philo->thread_id, NULL) < 0)
		{
			ft_putendl(STDERR_FILENO, "ERROR: Error at joining threads.");
			simulation_force_stop(&simulation->mtx_run);
			return (false);
		}
		i++;
	}
	return (true);
}

bool	threads_sleep(t_nanosecs usecs)
{
	if (usleep(usecs) < 0)
	{
		ft_putendl(STDERR_FILENO, "ERROR: Error at sleep.");
		return (false);
	}
	return (true);
}
