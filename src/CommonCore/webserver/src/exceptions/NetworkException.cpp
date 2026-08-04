/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NetworkException.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gabriel Reus  <gabrielin@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 19:43:21 by Gabriel Reu       #+#    #+#             */
/*   Updated: 2025/01/11 19:34:12 by Gabriel Reu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Exceptions/NetWorkException.hpp"

NetworkException::NetworkException(const char *msg) : Exception(msg)
{
	
}

NetworkException::NetworkException(std::string& msg) : Exception(msg)
{
	
}

NetworkException::NetworkException(const int& _errno) : Exception(_errno)
{
	
}

NetworkException::~NetworkException(void) throw ()
{
	
}


/*
const char*	NetworkException::what(void)
{
	return (this->_msg.c_str());
}
*/