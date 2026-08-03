/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 02:00:09 by greus-ro          #+#    #+#             */
/*   Updated: 2024/08/06 22:08:28 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
	private:
		Fixed const	x;
		Fixed const	y;

	public:
		Point(void);
		Point(float const x, float const y);
		Point(Point const &copy);
		~Point(void);
		Point	&operator=(Point const &copy);
		Fixed	getX(void) const;
		Fixed	getY(void) const;
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif
