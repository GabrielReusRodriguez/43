/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_forkproc.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 16:07:15 by greus-ro          #+#    #+#             */
/*   Updated: 2024/04/14 16:07:17 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FORKPROC_H
# define FT_FORKPROC_H

# include "ft_table.h"
# include "ft_philosopher.h"

int	ft_forkproc_create_proc(t_table *table);
int	ft_forkproc_wait(t_philosopher_set philosophers);
int	ft_forkproc_killall(t_philosopher_set philosophers);

#endif