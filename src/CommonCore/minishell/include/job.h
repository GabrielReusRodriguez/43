/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 21:23:03 by gabriel           #+#    #+#             */
/*   Updated: 2024/12/05 18:55:08 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef JOB_H
# define JOB_H

# include "libft.h"

typedef	struct s_job
{
	t_list	*cmds;
}	t_job;

void	job_init(t_job *job);
bool	job_parse_tokens(t_list **tokens, t_job *job);
bool	job_add_cmd(t_list *init, t_list *final, t_job *job);
void	job_destroy(t_job *job);



#endif