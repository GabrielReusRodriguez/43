/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_geometry2d.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 22:32:12 by greus-ro          #+#    #+#             */
/*   Updated: 2024/03/02 20:34:25 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GEOMETRY2D_H
# define FT_GEOMETRY2D_H

# define LOOKING_UP     1
# define LOOKING_DOWN   2
# define LOOKING_RIGHT  3
# define LOOKING_LEFT   4

# define MOVE_UP    1
# define MOVE_DOWN  2
# define MOVE_LEFT  3
# define MOVE_RIGHT 4

typedef struct s_point2d
{
	int	x;
	int	y;
}	t_point2d;

t_point2d	ft_point2d_new(int x, int y);

#endif