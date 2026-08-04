/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Debugger.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gabriel Reus  <gabrielin@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 20:25:09 by Gabriel Reu       #+#    #+#             */
/*   Updated: 2025/01/11 20:29:33 by Gabriel Reu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "Debugger/Debugger.hpp"


Debugger::Debugger(void)
{

}

Debugger::~Debugger(void)
{
	
}

void	Debugger::debug(const std::string& msg)
{
	std::cerr << DEBUG_HEADER << msg << std::endl;
	
}