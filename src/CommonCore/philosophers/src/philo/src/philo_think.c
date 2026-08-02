/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_think.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 00:33:26 by gabriel           #+#    #+#             */
/*   Updated: 2024/07/21 00:38:30 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "simulation.h"
#include "philosopher.h"
#include "utils.h"
#include "timestamp.h"
#include "printer.h"

bool	philo_think(t_philosopher *philo)
{
	t_milisecs	timestamp;
	
	if (!get_timestamp(&timestamp))
	{
		ft_putendl(STDERR_FILENO, "ERROR AT get_timestamp.");
		simulation_force_stop(philo->mtx_run_sim);
		return	(false);
	}
	printer_write(philo, timestamp - philo->time_of_start, "is thinking");
	philo->status = THINKING;
	return (true);	
}
