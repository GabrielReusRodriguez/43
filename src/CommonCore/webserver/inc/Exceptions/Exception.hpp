/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exception.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gabriel Reus  <gabrielin@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 19:57:05 by Gabriel Reu       #+#    #+#             */
/*   Updated: 2025/01/11 19:34:29 by Gabriel Reu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXCEPTION_HPP
# define EXCEPTION_HPP

# include <string>
# include <exception>

class Exception : public std::exception
{
	public:
		Exception(const char *msg);
		Exception(std::string& msg);
		Exception(const int& _errno);
		//Lo hacemos virtual para aceptar subclases.
		virtual ~Exception(void) throw ();

		//pdte mirar el what...
		const char*	what(void);

	protected:
		std::string	_msg;
};

#endif