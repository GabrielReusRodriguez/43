/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_table.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 16:08:37 by greus-ro          #+#    #+#             */
/*   Updated: 2024/04/14 16:08:38 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TABLE_H
# define FT_TABLE_H

# include <stddef.h>
# include <semaphore.h>
# include "ft_philosopher.h"
# include "ft_utils.h"
# include "ft_args.h"
# include "ft_rules.h"
# include "ft_semaphores.h"

typedef struct s_table
{
	size_t				num_forks;
	t_philosopher_set	philosophers_set;
	t_rules				rules;
	t_timestamp			start_time;
	sem_t				*sem_end;
	sem_t				*sem_dead;
	sem_t				*sem_meal;
	sem_t				*sem_console;
	sem_t				*sem_forks;
}	t_table;

void	ft_table_destroy(t_table *table);
t_bool	ft_table_isdead(void);
t_table	ft_table_init(t_args args);

#endif