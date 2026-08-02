/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 20:59:46 by gabriel           #+#    #+#             */
/*   Updated: 2024/07/23 00:31:20 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "fork.h"
#include "utils.h"
#include "simulation.h"

static bool	fork_init(size_t i, t_fork *fork)
{
	fork->num_fork = i;
	if (pthread_mutex_init(&fork->mutex_fork, NULL) < 0)
	{
		ft_putendl(STDERR_FILENO, "ERROR: Error creating fork mutex.");
		return (false);
	}
	return (true);
}

bool	forks_init(t_simulation *simulation)
{
	size_t	i;

	simulation->forks = (t_fork *)malloc(simulation->rules.number_of_philos \
									* sizeof(t_fork));
	if (simulation->forks == NULL)
	{
		ft_putendl(STDERR_FILENO, "ERROR: Error at malloc 1.");
		return (false);
	}
	i = 0;
	while (i < simulation->rules.number_of_philos)
	{
		if (!fork_init(i, simulation->forks + i))
		{
			forks_destroy(simulation, i);
			return (false);
		}
		i++;
	}
	return (true);
}

static bool	fork_destroy(t_fork	*fork)
{
	if (pthread_mutex_unlock(&fork->mutex_fork) < 0)
	{
		ft_putendl(STDERR_FILENO, "ERROR: Error destroying mutex 1");
		return (false);
	}
	if (pthread_mutex_destroy(&fork->mutex_fork) < 0)
	{
		ft_putendl(STDERR_FILENO, "ERROR: Error destroying mutex");
		return (false);
	}
	return (true);
}

bool	forks_destroy(t_simulation *simulation, size_t	total)
{
	size_t	i;

	i = 0;
	if (simulation->forks != NULL)
	{
		while (i < total)
		{
			fork_destroy(&simulation->forks[i]);
			i++;
		}
		simulation->forks = ft_free(simulation->forks);
	}
	return (true);
}