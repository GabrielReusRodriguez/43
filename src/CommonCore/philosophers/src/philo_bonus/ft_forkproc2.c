/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_forkproc2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 16:07:09 by greus-ro          #+#    #+#             */
/*   Updated: 2024/04/14 23:53:17 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <unistd.h>
#include "ft_forkproc.h"
#include "ft_philosopher.h"
#include "ft_threads.h"
#include "ft_sleep.h"

/*
	Here we wait for all childs to stop.
*/
int	ft_forkproc_wait(t_philosopher_set philosophers)
{
	size_t	i;
	int		status;

	i = 0;
	while (i < philosophers.total)
	{
		if (waitpid(philosophers.philosophers[i].process, &status, 0) < 0)
			return (-1);
		i++;
	}
	return (0);
}

/*
	Here we kill all child process.
*/
int	ft_forkproc_killall(t_philosopher_set philosophers)
{
	size_t	i;

	i = 0;
	while (i < philosophers.total)
	{
		if (philosophers.philosophers[i].process != -1)
		{
			if (kill(philosophers.philosophers[i].process, SIGKILL) < 0)
				return (-1);
		}
		i++;
	}
	return (0);
}
