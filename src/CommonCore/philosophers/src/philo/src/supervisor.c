/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervisor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 21:48:45 by gabriel           #+#    #+#             */
/*   Updated: 2024/07/23 00:32:23 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <pthread.h>

#include "supervisor.h"
#include "simulation.h"
#include "threads.h"
#include "utils.h"
#include "timestamp.h"

#include <stdio.h>

static bool supervisor_check_philo(t_philosopher *philo, t_milisecs ms, \
				bool *philo_dead, bool *everybody_ate)
{	
	size_t	num_meals;
	*philo_dead = false;
	if(pthread_mutex_lock(&philo->mtx_time_last_eat.mutex) < 0)
		return (ft_putendl(STDERR_FILENO, "ERROR: Error locking last eat"), \
					false);
	if (ms - philo->mtx_time_last_eat.value >= philo->rules->time_to_die)
		*philo_dead = true;
	if (pthread_mutex_unlock(&philo->mtx_time_last_eat.mutex) < 0)
		return (ft_putendl(STDERR_FILENO, "ERROR: Error unlocking last eat"), \
				false);
	if (philo->rules->number_of_meals > 0 && *everybody_ate)
	{
		if (!philo_get_num_meal(&philo->mtx_num_meals, &num_meals))
			return (false);
		if (num_meals < philo->rules->number_of_meals)
			*everybody_ate = false;
	}
	return (true);
}


static bool	supervisor_check_philos(t_simulation *simulation, t_milisecs ms)
{
	size_t			i;
	t_philosopher	*philo;
	bool			everybody_ate;
	bool			philo_dead;
	
	i = 0;
	everybody_ate = true;
	while (i < simulation->rules.number_of_philos)
	{
		philo = &simulation->philos[i];
		if (!supervisor_check_philo(philo, ms, &philo_dead, &everybody_ate))
			return (false);
		if (philo_dead)
		{
			if (!philo_die(philo))
				return (false);
			simulation_force_stop(&simulation->mtx_run);
			return (true);
		}
		i++;
	}
	if (simulation->rules.number_of_meals > 0 && everybody_ate)
		simulation_force_stop(&simulation->mtx_run);
	return (true);
}

bool	supervisor_gettimestamp(t_milisecs *ms)
{
	if (!get_timestamp(ms))
		return (ft_putendl(STDERR_FILENO, "ERROR AT get_timestamp."), false);	
	return (true);
}

bool	supervisor_checks(t_simulation *simulation)
{
	bool		check_ok;
	bool		run;
	t_milisecs	ms;

	if (!simulation_is_running(&simulation->mtx_run, &run))
		return (false);
	while (run)
	{
		if (!supervisor_gettimestamp(&ms))
			return (simulation_force_stop(&simulation->mtx_run), false);
		if (pthread_mutex_lock(&simulation->mtx_run.mutex) < 0)
		{
			ft_putendl(STDERR_FILENO, "ERROR: Error locking run.");
			return (simulation_force_stop(&simulation->mtx_run), false);
		}
		check_ok = supervisor_check_philos(simulation, ms);
		if (pthread_mutex_unlock(&simulation->mtx_run.mutex) < 0)
		{
			ft_putendl(STDERR_FILENO, "ERROR: Error unlocking run.");
			return (simulation_force_stop(&simulation->mtx_run), false);
		}
		if (!check_ok)
			return (simulation_force_stop(&simulation->mtx_run), false);
		if (!threads_sleep(SUPERVISOR_SLEEP_USECS))
			return (simulation_force_stop(&simulation->mtx_run), false);
		if (!simulation_is_running(&simulation->mtx_run, &run))
			return (false);
	}
	forks_destroy(simulation, simulation->rules.number_of_philos);
	return (true);
}