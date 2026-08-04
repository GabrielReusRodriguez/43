/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WebServer.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gabriel Reus  <gabrielin@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 13:53:45 by Gabriel Reu       #+#    #+#             */
/*   Updated: 2025/01/10 19:21:33 by Gabriel Reu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEBSERVER_HPP
# define WEBSERVER_HPP

# include <string>

# include "Config/Config.hpp"
# include "Services/NetworkService.hpp"

class WebServer
{
	protected:
		std::string		config_file;
		Config			config;
		NetworkService	network;
		bool			running;
		
		void	copy(const WebServer &ws);

	public:
		WebServer(void);
		WebServer(const Config &_config);
		WebServer(const WebServer &ws);
		WebServer(const std::string _config_file);
		~WebServer(void);

		void	start(void);
		void	run(void);
		void	stop(void);

	private: 
		WebServer&	operator=(const WebServer &ws);

};

#endif