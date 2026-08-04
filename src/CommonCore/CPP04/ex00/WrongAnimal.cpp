/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 22:31:52 by gabriel           #+#    #+#             */
/*   Updated: 2024/08/06 23:10:54 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
	this->_type ="undefined";
	std::cout << "WrongAnimal Default Constructor called." << std::endl;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal Default Destructor called." << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &copy)
{
	this->_type = copy._type;
	std::cout << "WrongAnimal Copy Constructor called." << std::endl;
}

void	WrongAnimal::operator=(WrongAnimal const &animal)
{
	this->_type = animal._type;
	std::cout << "WrongAnimal operator Equal called." << std::endl;
}

void WrongAnimal::makeSound(void) const
{
	std::cout << "MakeSound of a generic Wronganimal." << std::endl;
}

std::string	WrongAnimal::getType(void) const
{
	return (this->_type);
}
