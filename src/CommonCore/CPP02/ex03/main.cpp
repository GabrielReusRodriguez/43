/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 23:32:08 by gabriel           #+#    #+#             */
/*   Updated: 2024/07/31 21:30:25 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Point.hpp"

int	main(void)
{
	Point const	a(0.0f, 0.0f);
	Point const	b(5.0f, 0.0f);
	Point const	c(2.0f, 5.0f);

	std::cout << "outside: " << bsp(a, b, c, Point(-1.0f, 0.0f)) << std::endl;
	std::cout << "inside:  " << bsp(a, b, c, Point(2.0f, 2.0f)) << std::endl;
	std::cout << "vertex:  " << bsp(a, b, c, a) << std::endl;
	std::cout << "edge:    " << bsp(a, b, c, Point(2.5f, 0.0f)) << std::endl;
	return (0);
}
