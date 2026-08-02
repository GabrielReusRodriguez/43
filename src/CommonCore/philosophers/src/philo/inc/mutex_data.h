/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_data.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 18:45:37 by gabriel           #+#    #+#             */
/*   Updated: 2024/07/20 19:02:12 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTEX_DATA_H
# define MUTEX_DATA_H

# include <stdbool.h>
# include <pthread.h>

# include "datatypes.h"

typedef struct s_mutex_bool
{
	pthread_mutex_t	mutex;
	bool			value;
}	t_mutex_bool;

typedef struct s_mutex_sizet
{
	pthread_mutex_t	mutex;
	size_t			value;
}	t_mutex_sizet;

typedef struct s_mutex_milisec
{
	pthread_mutex_t	mutex;
	t_milisecs		value;
}	t_mutex_milisec;

#endif