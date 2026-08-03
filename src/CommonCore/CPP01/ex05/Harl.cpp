/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 16:36:32 by gabriel           #+#    #+#             */
/*   Updated: 2024/07/26 17:01:43 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Harl.hpp"

/* We have to get the address of the function.
	But be carefull because ISO C++  forbids taking the address of an 
	non-static member function. We have to put &Harl::function
*/
Harl::Harl(void)
{
	this->functions_ptr[0] = &Harl::debug;
	this->functions_str[0] = "DEBUG";
	this->functions_ptr[1] = &Harl::info;
	this->functions_str[1] = "INFO";
	this->functions_ptr[2] = &Harl::warning;
	this->functions_str[2] = "WARNING";
	this->functions_ptr[3] = &Harl::error;
	this->functions_str[3] = "ERROR";
}

Harl::~Harl(void)
{

}

/* We have to get the pointer to functyion and then call it
with the * at init to get the value ( address of fucntion of te pionter)*/
void	Harl::complain(std::string level)
{
	size_t	i;

	i = 0;
	while (i < 4)
	{
		if (this->functions_str[i] == level)
		{
			(this->*functions_ptr[i])();
			break;
		}
		i++;
	}
	
	 
}
	
void	Harl::debug(void)
{
	std::cout << "DEBUG : This is a debug msg." <<std::endl;
}

void	Harl::info(void)
{
	std::cout << "INFO : This is a info msg." <<std::endl;
}

void	Harl::warning(void)
{
	std::cout << "WARNING : This is a warning msg." <<std::endl;
}

void	Harl::error(void)
{
	std::cout << "ERROR : This is a error msg." <<std::endl;	
}