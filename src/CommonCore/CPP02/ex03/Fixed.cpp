/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 22:17:44 by gabriel           #+#    #+#             */
/*   Updated: 2024/10/09 00:46:18 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>

#include "Fixed.hpp"

const int Fixed::number_fractional_bits = 8;

Fixed::Fixed(void)
{
	this->number_value = 0;
}

Fixed::Fixed(Fixed const &copy)
{
	this->number_value = copy.number_value;
}

Fixed::Fixed(int const value)
{
	this->number_value = value << Fixed::number_fractional_bits;
}

Fixed::Fixed(float const value)
{
	this->number_value = static_cast<int>(roundf(value * (1 << Fixed::number_fractional_bits)));
}

Fixed::~Fixed(void)
{
}

Fixed	&Fixed::operator=(Fixed const &copy)
{
	if (this != &copy)
		this->number_value = copy.number_value;
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

bool	operator<(Fixed const &lhs, Fixed const &rhs)
{
	return (lhs.getRawBits() < rhs.getRawBits());
}

bool	operator>(Fixed const &lhs, Fixed const &rhs)
{
	return (lhs.getRawBits() > rhs.getRawBits());
}

bool	operator<=(Fixed const &lhs, Fixed const &rhs)
{
	return (lhs.getRawBits() <= rhs.getRawBits());
}

bool	operator>=(Fixed const &lhs, Fixed const &rhs)
{
	return (lhs.getRawBits() >= rhs.getRawBits());
}

bool	operator==(Fixed const &lhs, Fixed const &rhs)
{
	return (lhs.getRawBits() == rhs.getRawBits());
}

bool	operator!=(Fixed const &lhs, Fixed const &rhs)
{
	return (lhs.getRawBits() != rhs.getRawBits());
}

Fixed	operator+(Fixed const &lhs, Fixed const &rhs)
{
	Fixed	result;

	result.setRawBits(lhs.getRawBits() + rhs.getRawBits());
	return (result);
}

Fixed	operator-(Fixed const &lhs, Fixed const &rhs)
{
	Fixed	result;

	result.setRawBits(lhs.getRawBits() - rhs.getRawBits());
	return (result);
}

Fixed	operator*(Fixed const &lhs, Fixed const &rhs)
{
	return (Fixed(lhs.toFloat() * rhs.toFloat()));
}

Fixed	operator/(Fixed const &lhs, Fixed const &rhs)
{
	return (Fixed(lhs.toFloat() / rhs.toFloat()));
}

Fixed	&Fixed::operator++(void)
{
	this->number_value++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	result(*this);

	this->number_value++;
	return (result);
}

Fixed	&Fixed::operator--(void)
{
	this->number_value--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	result(*this);

	this->number_value--;
	return (result);
}

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return (a);
	return (b);
}

Fixed const	&Fixed::min(Fixed const &a, Fixed const &b)
{
	if (a.getRawBits() < b.getRawBits())
		return (a);
	return (b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	return (b);
}

Fixed const	&Fixed::max(Fixed const &a, Fixed const &b)
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	return (b);
}
