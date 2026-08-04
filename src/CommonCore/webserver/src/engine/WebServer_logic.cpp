/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WebServer_logic.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gabriel Reus  <gabrielin@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 19:09:54 by Gabriel Reu       #+#    #+#             */
/*   Updated: 2025/01/11 20:27:25 by Gabriel Reu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "WebServer.hpp"
#include "Exceptions/NetWorkException.hpp"

void	WebServer::start(void)
{
	this->running = true;
	try
	{
		this->network.start();
	}
	catch(NetworkException& e)
	{
		std::cerr << e.what() << std::endl;
		this->network.stop();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		this->running = false;
	}
	
}

void	WebServer::run(void)
{
	while (this->running)
	{
		
	}
}

void	WebServer::stop(void)
{
	this->running = false;

}