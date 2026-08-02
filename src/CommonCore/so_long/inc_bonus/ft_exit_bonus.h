/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 23:46:25 by greus-ro          #+#    #+#             */
/*   Updated: 2024/03/02 22:50:31 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EXIT_BONUS_H
# define FT_EXIT_BONUS_H

# include "ft_geometry2d_bonus.h"
# include "ft_utils_bonus.h"

typedef struct s_exit
{
	t_point2d	position;
	t_bool		active;
}	t_exit;

t_exit	ft_exit_new(void);

#endif