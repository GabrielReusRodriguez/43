/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 22:31:52 by gabriel           #+#    #+#             */
/*   Updated: 2024/10/23 23:15:54 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Animal.hpp"

Animal::Animal(void)
{
	this->_type ="undefined";
	std::cout << "Animal Default Constructor called." << std::endl;
}

Animal::~Animal(void)
{
	std::cout << "Animal Default Destructor called." << std::endl;
}

Animal::Animal(Animal const &copy)
{
	this->_type = copy._type;
	std::cout << "Animal Copy Constructor called." << std::endl;
}

void	Animal::operator=(Animal const &animal)
{
	if (this != &animal)
	{
		this->_type = animal._type;
		std::cout << "Animal operator Equal called." << std::endl;
	}
}

void Animal::makeSound(void) const
{
	std::cout << "MakeSound of a generic animal." << std::endl;
}

std::string	Animal::getType(void) const
{
	return (this->_type);
}
