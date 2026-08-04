/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WebServer_basics.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gabriel Reus  <gabrielin@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:40:16 by Gabriel Reu       #+#    #+#             */
/*   Updated: 2025/01/06 19:10:59 by Gabriel Reu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WebServer.hpp"

/*
		void	copy(const WebServer &ws);

	public:
		WebServer(void);
		WebServer(const Config &_config);
		WebServer(const WebServer &ws);
		WebServer(const std::string _config_file);
		~WebServer(void);

		WebServer&	operator=(const WebServer &ws);
		void		start(void);
*/

/*
void	WebServer::copy(const WebServer &ws) : config_file (ws.config_file)
{
	this->config 		= ws.config;
	//this->config_file 	= ws.config_file;

}
*/

WebServer::WebServer(void)
{
	
}

WebServer::WebServer(const Config &_config) : config_file("")
{
	this->config = _config;
}

WebServer::WebServer(const WebServer &ws): config_file(ws.config_file)
{
	this->config = ws.config;
}

WebServer::WebServer(const std::string _config_file): config_file(_config_file)
{
	
}

WebServer::~WebServer(void)
{
	
}

WebServer&	WebServer::operator=(const WebServer &ws)
{
	(void)ws;
	return (*this);
}

