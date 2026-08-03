/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 22:17:47 by gabriel           #+#    #+#             */
/*   Updated: 2024/09/25 19:12:49 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	private:
		int					number_value;
		static const int	number_fractional_bits;

	public:
		Fixed(void);
		Fixed(Fixed const &copy);
		Fixed(int const value);
		Fixed(float const value);
		~Fixed(void);
		Fixed		&operator=(Fixed const &copy);
		int			getRawBits(void) const;
		void		setRawBits(int const raw);
		float		toFloat(void) const;
		int			toInt(void) const;

		Fixed		&operator++(void);
		Fixed		operator++(int);
		Fixed		&operator--(void);
		Fixed		operator--(int);

		static Fixed		&min(Fixed &a, Fixed &b);
		static Fixed const	&min(Fixed const &a, Fixed const &b);
		static Fixed		&max(Fixed &a, Fixed &b);
		static Fixed const	&max(Fixed const &a, Fixed const &b);
};

bool	operator<(Fixed const &lhs, Fixed const &rhs);
bool	operator>(Fixed const &lhs, Fixed const &rhs);
bool	operator<=(Fixed const &lhs, Fixed const &rhs);
bool	operator>=(Fixed const &lhs, Fixed const &rhs);
bool	operator==(Fixed const &lhs, Fixed const &rhs);
bool	operator!=(Fixed const &lhs, Fixed const &rhs);
Fixed	operator+(Fixed const &lhs, Fixed const &rhs);
Fixed	operator-(Fixed const &lhs, Fixed const &rhs);
Fixed	operator*(Fixed const &lhs, Fixed const &rhs);
Fixed	operator/(Fixed const &lhs, Fixed const &rhs);

std::ostream	&operator<<(std::ostream &os, Fixed const &copy);

#endif
