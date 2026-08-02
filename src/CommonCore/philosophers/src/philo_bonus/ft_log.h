/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_log.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 08:12:11 by greus-ro          #+#    #+#             */
/*   Updated: 2024/04/14 16:07:28 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LOG_H
# define FT_LOG_H

# include "ft_philosopher.h"

void	ft_log(t_philosopher *philo, const char *msg, t_timestamp time);

#endif