/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_mutex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 00:15:21 by gabriel           #+#    #+#             */
/*   Updated: 2024/07/22 23:55:32 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <pthread.h>

#include "mutex_data.h"
#include "utils.h"

bool	philo_inc_num_meal(t_mutex_sizet *mtx_num_meal)
{
	if (pthread_mutex_lock(&mtx_num_meal->mutex) < 0)
		return (ft_putendl(STDERR_FILENO, \
					"ERROR: Error at locking num_meal mutex."), false);
	mtx_num_meal->value++;
	if (pthread_mutex_unlock(&mtx_num_meal->mutex) < 0)
		return (ft_putendl(STDERR_FILENO, \
					"ERROR: Error at unlocking num_meal mutex."), false);
	return (true);
}

bool	philo_change_time_last_meal(t_mutex_milisec *mtx_time, t_milisecs ms)
{
	if (pthread_mutex_lock(&mtx_time->mutex) < 0)
		return (ft_putendl(STDERR_FILENO, \
					"ERROR: Error at locking time_last_meal mutex."), false);
	mtx_time->value = ms;
	if (pthread_mutex_unlock(&mtx_time->mutex) < 0)
		return (ft_putendl(STDERR_FILENO, \
					"ERROR: Error at unlocking time_last_meal mutex."), false);
	return (true);
	
}

bool	philo_get_num_meal(t_mutex_sizet *mtx_num_meal, size_t *num_meal)
{
	if (pthread_mutex_lock(&mtx_num_meal->mutex) < 0)
		return (ft_putendl(STDERR_FILENO, \
					"ERROR: Error at locking num_meal mutex."), false);
	*num_meal = mtx_num_meal->value;
	if (pthread_mutex_unlock(&mtx_num_meal->mutex) < 0)
		return (ft_putendl(STDERR_FILENO, \
					"ERROR: Error at unlocking num_meal mutex."), false);
	return (true);
}