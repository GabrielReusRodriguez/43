/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_geometry.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:57:14 by greus-ro          #+#    #+#             */
/*   Updated: 2023/12/11 16:09:23 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GEOMETRY_H
# define FT_GEOMETRY_H

typedef struct s_point
{
	int	x;
	int	y;

}	t_point;

typedef struct s_rectangle
{
	t_point	up_left;
	t_point	down_right;
	int		area;

}	t_rectangle;

#endif
