/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_semaphores.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 16:08:19 by greus-ro          #+#    #+#             */
/*   Updated: 2024/04/14 23:51:27 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SEMAPHORES_H
# define FT_SEMAPHORES_H

# define SEMAPHOR_FORKS     "semaphor_forks"
# define SEMAPHOR_DEAD      "semaphor_dead"
# define SEMAPHOR_END       "semaphor_end"
# define SEMAPHOR_MEALS     "semaphor_meals"
# define SEMAPHOR_CONSOLE   "semaphor_console"

sem_t	*ft_semaphore_create(char *name, int value);
void	ft_semaphore_destroy(char *sem_name, sem_t *sem_value);
void	ft_semaphore_post(sem_t *sem, sem_t *end);
void	ft_semaphore_wait(sem_t *sem, sem_t *end);

#endif