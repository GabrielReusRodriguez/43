/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 21:59:24 by gabriel           #+#    #+#             */
/*   Updated: 2024/07/20 19:08:08 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIMULATION_H
# define SIMULATION_H

# include <stdbool.h>
# include <pthread.h>

# include "datatypes.h" 
# include "rules.h"
# include "philosopher.h"
# include "fork.h"
# include "mutex_data.h" 

typedef	struct s_simulation
{
	t_mutex_bool		mtx_run;
	t_rules				rules;
	t_philosopher		*philos;
	t_fork				*forks;
	t_milisecs			time_of_start;
	pthread_mutex_t		mutex_print;
	pthread_t			thread_supervisor;
}	t_simulation;

t_simulation	simulation_new(void);
bool			simulation_init(t_simulation *simulation);
void			simulation_destroy(t_simulation *simulation);
bool			simulation_is_running(t_mutex_bool *mutex_run, bool *run);
bool			simulation_stop(t_mutex_bool *mutex_run);
void			simulation_force_stop(t_mutex_bool *mutex_run);

#endif
