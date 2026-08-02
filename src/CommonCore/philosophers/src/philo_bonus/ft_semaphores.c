/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_semaphores.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 16:08:13 by greus-ro          #+#    #+#             */
/*   Updated: 2024/04/15 00:00:58 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <semaphore.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

/*
	With O_CREAT we say to sem_open to open the name semaphoner or create 
		if it does not exists.
	If we add O_EXCL to O_CREAT  we return an error if a semaphore with 
		name already exists.
	0644 are the permission to the semaphore (user, group, others...)
*/
sem_t	*ft_semaphore_create(char *name, int value)
{
	sem_t	*semaphore;

	sem_unlink(name);
	semaphore = sem_open(name, O_CREAT | O_EXCL, 0644, value);
	if (semaphore == SEM_FAILED)
	{
		printf("ERROR creating semaphore %s\n", name);
		exit(EXIT_FAILURE);
	}
	return (semaphore);
}

/* If we do not use unlink before, the semaphore gets in some kind of
		cache and next time uses the last one.
		
	To be sure we have deleted the semaphore, the best is first unlink 
	(de-register de semaphore) and then close.*/
void	ft_semaphore_destroy(char *sem_name, sem_t *sem_value)
{
	sem_unlink(sem_name);
	sem_close(sem_value);
}

void	ft_semaphore_post(sem_t *sem, sem_t *end)
{
	if (sem_post(sem) < 0)
	{
		sem_post(end);
		printf("ERROR posting semaphore \n");
		exit(EXIT_FAILURE);
	}
}

void	ft_semaphore_wait(sem_t *sem, sem_t *end)
{
	if (sem_wait(sem) < 0)
	{
		sem_post(end);
		printf("ERROR waitting semaphore \n");
		exit(EXIT_FAILURE);
	}
}
