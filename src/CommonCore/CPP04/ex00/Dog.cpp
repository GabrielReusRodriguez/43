/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 22:36:41 by gabriel           #+#    #+#             */
/*   Updated: 2024/10/23 22:53:42 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Dog.hpp"

Dog::Dog(void)
{
	this->_type ="dog";
	std::cout << "Dog Default Constructor called." << std::endl;
}

Dog::Dog(Dog const &copy) : Animal()
{
	this->_type = copy._type;
	std::cout << "Dog Copy Constructor called." << std::endl;
}

Dog::~Dog(void)
{
	std::cout << "Dog Destructor called." << std::endl;
}

void	Dog::operator=(Dog const &dog)
{
	if (this != &dog)
	{
		this->_type = dog._type;
		std::cout << "Dog Operator Equal called." << std::endl;
	}
}

void Dog::makeSound(void) const
{
	std::cout << "BUP! BUP!" << std::endl;
}