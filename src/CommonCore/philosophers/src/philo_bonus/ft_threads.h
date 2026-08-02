/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_threads.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 16:08:50 by greus-ro          #+#    #+#             */
/*   Updated: 2024/04/14 16:08:51 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_THREADS_H
# define FT_THREADS_H

# include "ft_table.h"
# include "ft_philosopher.h"

void	*ft_threads_check_philo_dead(void *args);
void	*ft_threads_check_philo_meal(void *args);
void	*ft_threads_check_philo_dead(void *args);
void	*ft_threads_check_philo_meal(void *args);
int		ft_threads_createthread(pthread_t *id, void *(*func)(void *arg), \
				void *arg);

#endif
