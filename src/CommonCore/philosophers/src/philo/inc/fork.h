/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 22:01:37 by gabriel           #+#    #+#             */
/*   Updated: 2024/07/20 23:48:43 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORK_H
# define FORK_H

# include <stdbool.h>
# include <pthread.h>

/* Forward declaration to avoid error between includes*/
typedef struct s_simulation t_simulation;

typedef struct s_fork
{
	size_t			num_fork;
	pthread_mutex_t mutex_fork;
}	t_fork;

bool	forks_init(t_simulation *simulation);
bool	forks_destroy(t_simulation *simulation, size_t total);

#endif
