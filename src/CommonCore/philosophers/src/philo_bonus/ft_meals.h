/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_meals.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 19:25:15 by greus-ro          #+#    #+#             */
/*   Updated: 2024/04/12 12:52:02 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MEALS_H
# define FT_MEALS_H

# include "ft_timestamp.h"

typedef struct s_meals
{
	t_timestamp		timestamp;
	int				num_meals;
}	t_meals;

#endif