/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 23:38:05 by gabriel           #+#    #+#             */
/*   Updated: 2024/07/23 00:34:18 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "utils.h"
#include "simulation.h"
#include "fork.h"
#include "philosopher.h"

t_simulation	simulation_new(void)
{
	t_simulation	simulation;
	
	simulation.forks 			= NULL;
	simulation.philos 			= NULL;
	simulation.mtx_run.value	= false;
	simulation.time_of_start	= 0;
	return (simulation);
}

void	simulation_destroy(t_simulation *simulation)
{
	forks_destroy(simulation, simulation->rules.number_of_philos);
	philos_destroy(simulation, simulation->rules.number_of_philos);
	if (pthread_mutex_unlock(&simulation->mutex_print) < 0)
		ft_putendl(STDERR_FILENO, "ERROR: Error unlocking mutex of print.");
	if (pthread_mutex_destroy(&simulation->mutex_print) < 0)
		ft_putendl(STDERR_FILENO, "ERROR: Error destroying mutex of print.");
	if (pthread_mutex_unlock(&simulation->mtx_run.mutex) < 0)
		ft_putendl(STDERR_FILENO, "ERROR: Error unlocking mutex of end.");
	if (pthread_mutex_destroy(&simulation->mtx_run.mutex) < 0)
		ft_putendl(STDERR_FILENO, "ERROR: Error destroying mutex of end.");
}

bool	simulation_init(t_simulation *simulation)
{
	if (pthread_mutex_init(&simulation->mutex_print, NULL) < 0)
		return (ft_putendl(STDERR_FILENO, "ERROR: Creating mutex of print."), \
					false);
	if (pthread_mutex_init(&simulation->mtx_run.mutex, NULL) < 0)
		return (ft_putendl(STDERR_FILENO, "ERROR: Creating mutex of end."), \
					false);
	if (!forks_init(simulation))
		return (false);
	if (!philos_init(simulation))
		return (false);
	return (true);
}