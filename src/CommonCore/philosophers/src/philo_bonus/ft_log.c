/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_log.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 16:07:24 by greus-ro          #+#    #+#             */
/*   Updated: 2024/04/14 23:50:53 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_philosopher.h"
#include "ft_timestamp.h"
#include "ft_semaphores.h"

void	ft_log(t_philosopher *philo, const char *msg, t_timestamp time)
{
	ft_semaphore_wait(philo->sem_console, philo->sem_end);
	printf("%llu", time);
	printf("\t %d ", philo->number);
	printf("%s\n", msg);
	ft_semaphore_post(philo->sem_console, philo->sem_end);
}
