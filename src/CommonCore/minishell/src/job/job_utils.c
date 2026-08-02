/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 21:50:04 by gabriel           #+#    #+#             */
/*   Updated: 2024/12/05 21:37:41 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "job.h"
#include "cmd.h"

void	job_init(t_job *job)
{
	job->cmds = NULL;
}

void	job_destroy(t_job *job)
{
	ft_lstclear(&job->cmds, cmd_clear_list_node);
	//free (job);
}