/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_sleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 00:31:13 by gabriel           #+#    #+#             */
/*   Updated: 2024/07/21 00:48:43 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "simulation.h"
#include "philosopher.h"
#include "utils.h"
#include "timestamp.h"
#include "printer.h"
#include "threads.h"

bool philo_sleep(t_philosopher *philo)
{
	t_milisecs	timestamp;
	
	if (!get_timestamp(&timestamp))
	{
		ft_putendl(STDERR_FILENO, "ERROR AT get_timestamp.");
		simulation_force_stop(philo->mtx_run_sim);
		return	(false);
	}
	printer_write(philo, timestamp - philo->time_of_start, "is sleeping");
	threads_sleep(philo->rules->time_to_sleep * 1000);
	philo->status = SLEEPING;
	return (true);	
}
