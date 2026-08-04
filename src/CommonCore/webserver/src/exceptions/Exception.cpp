/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exception.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gabriel Reus  <gabrielin@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 20:00:11 by Gabriel Reu       #+#    #+#             */
/*   Updated: 2025/01/11 20:14:28 by Gabriel Reu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstring>

#include "Exceptions/Exception.hpp"

Exception::Exception(const char *msg) : _msg(msg)
{
	
}

Exception::Exception(std::string& msg) : _msg(msg)
{
	
}

Exception::Exception(const int& _errno)
{
	char*	errno_desc;

	errno_desc = strerror(_errno);
	this->_msg = std::string(errno_desc);
	//delete errno_desc;
}

Exception::~Exception(void) throw ()
{
	
}

const char*	Exception::what(void)
{
	return (this->_msg.c_str());
}
