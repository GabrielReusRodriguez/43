/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 23:33:10 by gabriel           #+#    #+#             */
/*   Updated: 2024/07/21 23:18:56 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdio.h>
#include <pthread.h>

#include "datatypes.h"
#include "simulation.h"
#include "utils.h"

bool	printer_write(t_philosopher *philo, t_milisecs time, \
			const char *msg)
{
	bool	running;
	size_t	num_philo;

	num_philo = philo->num_philo;
	if (!simulation_is_running(philo->mtx_run_sim, &running))
		return (false);
	if (running)
	{
		if (pthread_mutex_lock(philo->mutex_printer) < 0)
			return (ft_putendl(STDERR_FILENO, \
						"ERROR: Error at locking print mutex."), false);
		printf("%lu %lu %s\n", time, num_philo, msg);
		if (pthread_mutex_unlock(philo->mutex_printer) < 0)
			return (ft_putendl(STDERR_FILENO, \
						"ERROR: Error at unlocking print mutex."), false);
	}
	return (true);
}

bool	printer_unsafe_write(t_philosopher *philo, t_milisecs time, \
			const char *msg)
{
	size_t	num_philo;

	num_philo = philo->num_philo;
	if (pthread_mutex_lock(philo->mutex_printer) < 0)
		return (ft_putendl(STDERR_FILENO, \
					"ERROR: Error at locking print mutex."), false);
	printf("%lu %lu %s\n", time, num_philo, msg);
	if (pthread_mutex_unlock(philo->mutex_printer) < 0)
		return (ft_putendl(STDERR_FILENO, \
					"ERROR: Error at unlocking print mutex."), false);
	return (true);
}