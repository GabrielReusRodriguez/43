/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philosopher3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 16:07:53 by greus-ro          #+#    #+#             */
/*   Updated: 2024/04/14 23:59:03 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <semaphore.h>
#include "ft_philosopher.h"
#include "ft_sleep.h"
#include "ft_log.h"
#include "ft_semaphores.h"

/* Philosopher takes fork.*/
static int	ft_philosopher_pickup_forks(t_philosopher *philo)
{
	t_timestamp	timestamp;

	ft_semaphore_wait(philo->sem_forks, philo->sem_end);
	philo->l_fork = TRUE;
	timestamp = ft_timestamp_get();
	ft_log(philo, "has taken a fork", timestamp - philo->start_time);
	if (philo->total == 1)
	{
		ft_sleep(philo->rules.time_to_die);
		ft_semaphore_post(philo->sem_forks, philo->sem_end);
		return (1);
	}
	ft_semaphore_wait(philo->sem_forks, philo->sem_end);
	philo->r_fork = TRUE;
	timestamp = ft_timestamp_get();
	ft_log(philo, "has taken a fork", timestamp - philo->start_time);
	return (0);
}

/* Philosopher eats.*/
void	ft_philosopher_eat(t_philosopher *philo)
{
	t_timestamp	timestamp;

	philo->status = PHILO_STATUS_EAT;
	if (ft_philosopher_pickup_forks(philo) == 1)
		return ;
	timestamp = ft_timestamp_get();
	ft_semaphore_wait(philo->sem_check_meal, philo->sem_end);
	philo->meals.timestamp = timestamp;
	philo->meals.num_meals++;
	ft_semaphore_post(philo->sem_check_meal, philo->sem_end);
	ft_log(philo, "is eating", timestamp - philo->start_time);
	ft_sleep(philo->rules.time_to_eat);
	philo->l_fork = FALSE;
	ft_semaphore_post(philo->sem_forks, philo->sem_end);
	philo->r_fork = FALSE;
	ft_semaphore_post(philo->sem_forks, philo->sem_end);
}
