/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConfigMethodFactory .hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gabriel Reus  <gabrielin@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:12:12 by Gabriel Reu       #+#    #+#             */
/*   Updated: 2025/01/06 14:18:10 by Gabriel Reu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIGFACTORY_HPP
# define CONFIGFACTORY_HPP

#include <string>

# include "Config.hpp"

class ConfigMethodFactory
{
	public:
		virtual Config	&createConfig(const std::string cfg_file) = 0;
};

#endif