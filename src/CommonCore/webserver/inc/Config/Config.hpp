/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Config.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gabriel Reus  <gabrielin@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 13:52:55 by Gabriel Reu       #+#    #+#             */
/*   Updated: 2025/01/06 19:02:59 by Gabriel Reu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_HPP
# define CONFIG_HPP

# include <string>

# define CFG_DFLT_HTTP_PORT 80

class Config
{
	protected:
		std::string		host;
		unsigned int	port;
		bool 			suport_server_names;	
		std::string		error_page_path;
		unsigned int	max_body_size;
	
		void	copy(const Config &_config);

	public:
		Config(void);
		Config(const Config &config);
		~Config(void);
		Config&	operator=(const Config &config);
		
		unsigned int	getPort(void) const;
		void			setPort(const unsigned int &_port);
	
};

#endif