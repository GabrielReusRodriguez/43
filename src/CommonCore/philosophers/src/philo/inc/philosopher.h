/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 21:53:44 by gabriel           #+#    #+#             */
/*   Updated: 2024/07/22 23:29:09 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <stdbool.h>
# include <pthread.h>

# include "datatypes.h"
# include "mutex_data.h"
# include "rules.h"

/* Forward declaration to avoid error between includes*/
typedef struct s_simulation t_simulation;
typedef struct s_fork		t_fork;

typedef enum e_philo_status
{
	SLEEPING,
	EATING,
	THINKING,
	DIED,
	INIT
} t_philo_status;

typedef struct s_philosopher
{
	size_t			num_philo;
	t_fork			*l_fork;
	t_fork			*r_fork;
	t_philo_status	status;
	t_milisecs		time_of_start;
	
	pthread_t		thread_id;
	pthread_mutex_t	*mutex_printer;

	t_mutex_bool	*mtx_run_sim;
	t_mutex_sizet	mtx_num_meals;
	t_mutex_milisec	mtx_time_last_eat;

	t_rules			*rules;

}	t_philosopher;

bool	philos_init(t_simulation *simulation);
bool	philos_destroy(t_simulation *simulation, size_t total);
void	*philo_life(void * arg);
bool	philo_eat(t_philosopher *philo);
bool	philo_sleep(t_philosopher *philo);
bool	philo_think(t_philosopher *philo);
bool	philo_die(t_philosopher *philo);
bool	philo_inc_num_meal(t_mutex_sizet *mtx_num_meal);
bool	philo_change_time_last_meal(t_mutex_milisec *mtx_time, t_milisecs ms);
bool	philo_get_num_meal(t_mutex_sizet *mtx_num_meal, size_t *num_meal);


#endif
