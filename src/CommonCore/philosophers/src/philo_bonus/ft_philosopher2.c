/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philosopher2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 16:07:46 by greus-ro          #+#    #+#             */
/*   Updated: 2024/04/14 22:31:47 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_args.h"
#include "ft_philosopher.h"
#include "ft_timestamp.h"
#include "ft_sleep.h"
#include "ft_log.h"

static void	ft_philosopher_do_state(t_philosopher *philo)
{
	while (TRUE)
	{
		if (philo->status == PHILO_STATUS_INIT || \
				philo->status == PHILO_STATUS_THINK)
		{
			ft_philosopher_eat(philo);
			continue ;
		}
		if (philo->status == PHILO_STATUS_EAT)
		{
			ft_philosopher_sleep(philo);
			continue ;
		}
		if (philo->status == PHILO_STATUS_SLEEP)
		{
			ft_philosopher_think(philo);
			continue ;
		}
	}
}

void	*ft_philosopher_life(void *arg)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)arg;
	ft_philosopher_do_state(philo);
	return (NULL);
}

void	ft_philosopher_sleep(t_philosopher *philo)
{
	t_timestamp	timestamp;

	philo->status = PHILO_STATUS_SLEEP;
	timestamp = ft_timestamp_get();
	ft_log(philo, "is sleeping", timestamp - philo->start_time);
	ft_sleep(philo->rules.time_to_sleep);
}

void	ft_philosopher_think(t_philosopher *philo)
{
	t_timestamp	timestamp;

	philo->status = PHILO_STATUS_THINK;
	timestamp = ft_timestamp_get();
	ft_log(philo, "is thinking", timestamp - philo->start_time);
}
