/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NetWorkException.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gabriel Reus  <gabrielin@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 19:37:28 by Gabriel Reu       #+#    #+#             */
/*   Updated: 2025/01/11 19:34:22 by Gabriel Reu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NETWORKEXCEPTION_HPP
# define NETWORKEXCEPTION_HPP

# include <string>

# include "Exceptions/Exception.hpp"

class NetworkException: public Exception
{
	public:
		NetworkException(const char *msg);
		NetworkException(std::string& msg);
		NetworkException(const int& erno);
		//Lo hacemos virtual para aceptar subclases.
		virtual ~NetworkException(void) throw ();
	
	protected:
		std::string	_msg;
};

#endif