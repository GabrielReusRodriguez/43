/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_geometry2d_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 20:23:02 by greus-ro          #+#    #+#             */
/*   Updated: 2024/03/02 20:31:40 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_geometry2d_bonus.h"

t_point2d	ft_point2d_new(int x, int y)
{
	t_point2d	point;

	point.x = x;
	point.y = y;
	return (point);
}
