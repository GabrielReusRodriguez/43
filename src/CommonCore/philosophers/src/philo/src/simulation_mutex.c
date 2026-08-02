/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 23:59:54 by gabriel           #+#    #+#             */
/*   Updated: 2024/07/20 18:59:05 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <pthread.h>

#include "simulation.h"
#include "utils.h"

bool	simulation_is_running(t_mutex_bool *mutex_run, bool *run)
{
	if (pthread_mutex_lock(&mutex_run->mutex) < 0)
		return (ft_putendl(STDERR_FILENO, \
					"ERROR: Error at locking end mutex."), false);
	*run = mutex_run->value;
	if (pthread_mutex_unlock(&mutex_run->mutex) < 0)
		return (ft_putendl(STDERR_FILENO, \
					"ERROR: Error at unlocking end mutex."), false);
	return (true);
}

bool	simulation_stop(t_mutex_bool *mutex_run)
{
	if (pthread_mutex_lock(&mutex_run->mutex) < 0)
		return (ft_putendl(STDERR_FILENO, \
					"ERROR: Error at locking end mutex."), false);
	mutex_run->value = false;
	if (pthread_mutex_unlock(&mutex_run->mutex) < 0)
		return (ft_putendl(STDERR_FILENO, \
					"ERROR: Error at unlocking end mutex."), false);
	return (true);
}

void	simulation_force_stop(t_mutex_bool *mutex_run)
{
	mutex_run->value = false;
}
