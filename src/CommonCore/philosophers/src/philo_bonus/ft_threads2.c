/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_threads2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 12:02:48 by greus-ro          #+#    #+#             */
/*   Updated: 2024/04/12 12:57:50 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>

int	ft_threads_createthread(pthread_t *id, void *(*func)(void *arg), void *arg)
{
	if (pthread_create(id, NULL, func, arg) < 0)
		return (-1);
	if (pthread_detach(*id) < 0)
		return (-1);
	return (0);
}
