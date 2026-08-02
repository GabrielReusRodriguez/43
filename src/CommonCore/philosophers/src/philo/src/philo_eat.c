/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 00:34:03 by gabriel           #+#    #+#             */
/*   Updated: 2024/07/22 23:58:53 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "simulation.h"
#include "philosopher.h"
#include "utils.h"
#include "timestamp.h"
#include "printer.h"
#include "threads.h"

#include <stdio.h>

static pthread_mutex_t	*philo_determine_fork(t_philosopher *philo, \
							size_t num_fork)
{
	pthread_mutex_t *fork_mutex;

	if (philo->num_philo % 2 == 1)
	{
		if (num_fork == 1)
			fork_mutex = &philo->l_fork->mutex_fork;
		else
			fork_mutex = &philo->r_fork->mutex_fork;
	}
	else
	{
		if (num_fork == 1)
			fork_mutex = &philo->r_fork->mutex_fork;
		else
			fork_mutex = &philo->l_fork->mutex_fork;
	}
	return (fork_mutex);
}

static bool philo_take_fork(t_philosopher *philo, size_t num_fork, bool *run)
{
	t_milisecs		timestamp;
	pthread_mutex_t *fork_mutex;

	if (!simulation_is_running(philo->mtx_run_sim, run))
		return (false);
	if (!*run)
		return (true);
	fork_mutex = philo_determine_fork(philo, num_fork);
	if (pthread_mutex_lock(fork_mutex) < 0)
	{
		simulation_force_stop(philo->mtx_run_sim);
		return (false);
	}
	if (!get_timestamp(&timestamp))
		return (ft_putendl(STDERR_FILENO, "ERROR AT get_timestamp."), false);
	printer_write(philo, timestamp - philo->time_of_start, "has taken a fork");
	return (true);
}

static bool philo_leave_fork(t_philosopher *philo, size_t num_fork, bool *run)
{
	pthread_mutex_t *fork_mutex;
	
	if (!simulation_is_running(philo->mtx_run_sim, run))
		return (false);
	if (!*run)
		return (true);
	fork_mutex = philo_determine_fork(philo, num_fork);
	if (pthread_mutex_unlock(fork_mutex) < 0)
	{
		simulation_force_stop(philo->mtx_run_sim);
		return (false);		
	}
	return (true);	
}

static bool	philo_eating_time(t_philosopher *philo, bool *run)
{
	t_milisecs	timestamp;

	if (!simulation_is_running(philo->mtx_run_sim, run))
		return (false);
	if (!*run)
		return (true);
	if (!get_timestamp(&timestamp))
		return (ft_putendl(STDERR_FILENO, "ERROR AT get_timestamp."), false);
	if (!philo_change_time_last_meal(&philo->mtx_time_last_eat, timestamp))
		return(false);
	printer_write(philo, timestamp - philo->time_of_start, "is eating");
	philo->status = EATING;
	if (philo->rules->number_of_meals > 0)
		if (!philo_inc_num_meal(&philo->mtx_num_meals))
			return (false);
	threads_sleep(philo->rules->time_to_eat * 1000);
	return (true);
}

/* We calculate if it is running inside every fuction to avoid the 25 lines
limit,
if run is falsem we return false and outside we will force stop 
( it is already stopped so, it is not a problem )
*/
bool	philo_eat(t_philosopher *philo)
{
	bool	run;
	
	if (!philo_take_fork(philo, 1, &run) || !run)
		return (false);	
	if (!philo_take_fork(philo, 2, &run) || !run)
		return (false);	
	if (!philo_eating_time(philo, &run) || !run)
		return (false);
	if (!philo_leave_fork(philo, 2, &run) || !run)
		return (false);
	if (!philo_leave_fork(philo, 1, &run) || !run)
		return (false);
	return (true);
}

/*
bool	philo_eat(t_philosopher *philo)
{
	bool	run;
	
	if (!philo_take_fork(philo, 1, &run ) || !philo_take_fork(philo, 2, &run))
		return (false);	
	if (!philo_eating_time(philo, &run))
		return (false);
	if (!philo_leave_fork(philo, 2, &run) || !philo_leave_fork(philo, 1, &run))
		return (false);
	if (philo->rules->number_of_meals > 0)
		if (!philo_inc_num_meal(&philo->mtx_num_meals))
			return (false);
	return (true);
}
*/

/*
bool	philo_eat(t_philosopher *philo)
{
	if (!philo_take_fork(philo, 1))
		return (false);	
	if (!philo_take_fork(philo, 2))
		return (false);
	if (!philo_eating_time(philo))
		return (false);
	if (!philo_leave_fork(philo, 2))
		return (false);
	if (!philo_leave_fork(philo, 1))
		return (false);
	philo->status = EATING;
	if (philo->rules->number_of_meals > 0)
		if (!philo_inc_num_meal(&philo->mtx_num_meals))
			return (false);
	return (true);
}
*/