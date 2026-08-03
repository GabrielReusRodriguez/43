/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 23:14:48 by gabriel           #+#    #+#             */
/*   Updated: 2024/07/31 21:28:03 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : x(0), y(0)
{
}

Point::Point(float const x1, float const y1) : x(x1), y(y1)
{
}

Point::Point(Point const &copy) : x(copy.x), y(copy.y)
{
}

Point::~Point(void)
{
}

/* const members cannot be reassigned; keep OCF signature without UB. */
Point	&Point::operator=(Point const &copy)
{
	(void)copy;
	return (*this);
}

Fixed	Point::getX(void) const
{
	return (this->x);
}

Fixed	Point::getY(void) const
{
	return (this->y);
}
