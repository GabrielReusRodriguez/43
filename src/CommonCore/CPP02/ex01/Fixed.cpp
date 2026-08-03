/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 22:17:44 by gabriel           #+#    #+#             */
/*   Updated: 2024/10/09 00:09:26 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>

#include "Fixed.hpp"

const int Fixed::number_fractional_bits = 8;

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->number_value = 0;
}

Fixed::Fixed(Fixed const &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	this->number_value = copy.getRawBits();
}

Fixed::Fixed(int const value)
{
	std::cout << "Int constructor called" << std::endl;
	this->number_value = value << Fixed::number_fractional_bits;
}

Fixed::Fixed(float const value)
{
	std::cout << "Float constructor called" << std::endl;
	this->number_value = static_cast<int>(roundf(value * (1 << Fixed::number_fractional_bits)));
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed	&Fixed::operator=(Fixed const &copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)
		this->number_value = copy.getRawBits();
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	return (this->number_value);
}

void	Fixed::setRawBits(int const raw)
{
	this->number_value = raw;
}

float	Fixed::toFloat(void) const
{
	return (static_cast<float>(this->number_value) / static_cast<float>(1 << Fixed::number_fractional_bits));
}

int	Fixed::toInt(void) const
{
	return (this->number_value >> Fixed::number_fractional_bits);
}

std::ostream	&operator<<(std::ostream &os, Fixed const &copy)
{
	return (os << copy.toFloat());
}
