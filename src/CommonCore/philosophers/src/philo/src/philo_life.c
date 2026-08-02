/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 23:28:36 by gabriel           #+#    #+#             */
/*   Updated: 2024/07/23 00:32:50 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"
#include "simulation.h"

#include <stdio.h>

void	*philo_life(void * arg)
{
	t_philosopher	*philo;
	bool			simulation_running;

	philo = (t_philosopher *)arg;
	if (!simulation_is_running(philo->mtx_run_sim, &simulation_running))
		return (simulation_force_stop(philo->mtx_run_sim), arg);
	while (simulation_running)
	{
		if (philo->status == INIT || philo->status == THINKING)
			if (!philo_eat(philo))
				return (simulation_force_stop(philo->mtx_run_sim), arg);
		if (philo->status == EATING)
			if (!philo_sleep(philo))
				return (simulation_force_stop(philo->mtx_run_sim), arg);
		if (philo->status == SLEEPING)
			if (!philo_think(philo))
				return (simulation_force_stop(philo->mtx_run_sim), arg);
		if (!simulation_is_running(philo->mtx_run_sim, &simulation_running))
			return (simulation_force_stop(philo->mtx_run_sim), arg);
	}
	return (arg);
}

/*

	if (!get_timestamp(&timestamp))
	{
		ft_putendl(STDERR_FILENO, "ERROR AT get_timestamp.\n");
		simulation_force_stop(philo->mtx_run_sim);
		return	(NULL);
	}
	printer_write(philo, timestamp - philo->time_of_start, "Hola mundo!\n");

*/