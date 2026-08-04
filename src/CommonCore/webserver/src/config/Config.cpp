/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Config.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gabriel Reus  <gabrielin@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:19:47 by Gabriel Reu       #+#    #+#             */
/*   Updated: 2025/01/06 19:02:54 by Gabriel Reu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Config/Config.hpp"

void	Config::copy(const Config &config)
{
	this->host = config.host;
	this->port = config.port;
	this->error_page_path = config.error_page_path;
	this->max_body_size = config.max_body_size;
	this->suport_server_names =  config.suport_server_names;
}

Config::Config(const Config &config)
{
	if (this != &config)
		this->copy(config);
}

Config::Config(void)
{
	this->port = CFG_DFLT_HTTP_PORT;
}

Config::~Config(void)
{

}

Config&	Config::operator=(const Config &config)
{
	if (this != &config)
		this->copy(config);
	return (*this);
}
		
unsigned int	Config::getPort(void) const
{
	return (this->port);
}

void	Config::setPort(const unsigned int &_port)
{
	this->port = _port;
}
