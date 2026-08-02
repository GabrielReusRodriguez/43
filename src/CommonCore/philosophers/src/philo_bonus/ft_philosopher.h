/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philosopher.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 00:03:25 by greus-ro          #+#    #+#             */
/*   Updated: 2024/04/14 22:02:28 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PHILOSOPHER_H
# define FT_PHILOSOPHER_H

# include <stddef.h>
# include <semaphore.h>

# include "ft_args.h"
# include "ft_rules.h"
# include "ft_meals.h"

# define PHILO_STATUS_INIT -1
# define PHILO_STATUS_EAT   1
# define PHILO_STATUS_THINK 2
# define PHILO_STATUS_SLEEP 3

typedef struct s_philosopher
{
	int				total;
	int				number;
	int				status;
	t_bool			l_fork;
	t_bool			r_fork;
	t_rules			rules;
	t_timestamp		start_time;
	t_meals			meals;
	sem_t			*sem_end;
	sem_t			*sem_dead;
	sem_t			*sem_meal_condition;
	sem_t			*sem_console;
	sem_t			*sem_forks;
	sem_t			*sem_check_meal;
	char			*name_sem_check_meal;
	pid_t			process;
}	t_philosopher;

typedef struct s_philosopher_set
{
	size_t			total;
	t_philosopher	*philosophers;
}	t_philosopher_set;

t_philosopher_set	ft_philosophers_init(t_args args, \
						t_rules rules);
t_philosopher		ft_philosopher_new(size_t num_philo);
void				ft_philosopher_destroy(t_philosopher *philosopher);
void				ft_philosophers_destroy(t_philosopher_set *philosophers);
void				*ft_philosopher_life(void *arg);
void				ft_philosopher_eat(t_philosopher *philo);
void				ft_philosopher_sleep(t_philosopher *philo);
void				ft_philosopher_think(t_philosopher *philo);
#endif