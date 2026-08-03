/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 02:03:10 by greus-ro          #+#    #+#             */
/*   Updated: 2024/07/31 21:23:02 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/* Cross product of edges (b-a) and (p-a). Zero means p is on the line ab. */
static Fixed	sign(Point const &p1, Point const &p2, Point const &p3)
{
	return ((p1.getX() - p3.getX()) * (p2.getY() - p3.getY())
		- (p2.getX() - p3.getX()) * (p1.getY() - p3.getY()));
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed const	d1 = sign(point, a, b);
	Fixed const	d2 = sign(point, b, c);
	Fixed const	d3 = sign(point, c, a);
	bool const	has_neg = (d1 < Fixed(0) || d2 < Fixed(0) || d3 < Fixed(0));
	bool const	has_pos = (d1 > Fixed(0) || d2 > Fixed(0) || d3 > Fixed(0));

	if (d1 == Fixed(0) || d2 == Fixed(0) || d3 == Fixed(0))
		return (false);
	return (!(has_neg && has_pos));
}
