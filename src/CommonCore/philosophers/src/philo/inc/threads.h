/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 18:09:51 by gabriel           #+#    #+#             */
/*   Updated: 2024/07/20 23:43:54 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef THREADS_H
# define THREADS_H

# include <stdbool.h>
# include <stddef.h>

# include "simulation.h"
# include "mutex_data.h"

bool	threads_create(t_simulation *simulation);
bool	threads_join(t_simulation *simulation);
bool	threads_sleep(t_nanosecs usecs);

#endif