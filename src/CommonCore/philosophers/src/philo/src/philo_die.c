/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_die.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 22:41:50 by gabriel           #+#    #+#             */
/*   Updated: 2024/07/21 23:20:12 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "simulation.h"
#include "philosopher.h"
#include "utils.h"
#include "printer.h"
#include "timestamp.h"

bool	philo_die(t_philosopher *philo)
{
	t_milisecs	ms;
	if (!get_timestamp(&ms))
		return (ft_putendl(STDERR_FILENO, "ERROR AT get_timestamp."), false);
	//simulation_stop(philo->mtx_run_sim);
	printer_unsafe_write(philo, ms - philo->time_of_start, "died");
	return (true);
}