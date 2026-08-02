/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 00:11:52 by greus-ro          #+#    #+#             */
/*   Updated: 2024/04/02 17:29:48 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ARGS_H
# define FT_ARGS_H

# include <stddef.h>

# include "ft_utils.h"

typedef struct s_args
{
	size_t	num_philo;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	int		num_must_eat;
}	t_args;

t_args	ft_args_parse(char **argv, int argc);
t_bool	ft_args_validate_format(char **argv, int argc);
t_bool	ft_args_validate_value(t_args args);

#endif