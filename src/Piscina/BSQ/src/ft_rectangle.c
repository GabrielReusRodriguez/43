/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rectangle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:56:14 by greus-ro          #+#    #+#             */
/*   Updated: 2023/12/11 16:27:01 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_geometry.h"

int	ft_get_area(t_rectangle *rectangle)
{
	int area;
	int	long_side;
	int	long_up;

	area = 0;
	long_side = rectangle->up_left.y - rectangle->down_right.y;
	long_up = rectangle->up_left.x - rectangle->down_right.x;
	area = long_side * long_up;
	if (area < 0 )
	{	
		area = -area;
	}
	rectangle->area = area;
	return (area);
}
