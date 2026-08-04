/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 22:36:41 by gabriel           #+#    #+#             */
/*   Updated: 2024/10/23 23:24:18 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Dog.hpp"

Dog::Dog(void)
{
	this->_type ="dog";
	this->_brain = new Brain();
	std::cout << "Dog Default Constructor called." << std::endl;
}

Dog::Dog(Dog const &copy) : Animal()
{
	this->_type = copy._type;
	this->_brain = new Brain(*copy._brain);
	std::cout << "Dog Copy Constructor called." << std::endl;
}

Dog::~Dog(void)
{
	delete this->_brain;
	std::cout << "Dog Destructor called." << std::endl;
}

void	Dog::operator=(Dog const &dog)
{
	if (this != &dog)
	{
		this->_type = dog._type;
		if ( this->_brain != NULL)
			delete this->_brain;
		this->_brain = new Brain(*dog._brain);
		std::cout << "Dog Operator Equal called." << std::endl;
	}
}

void Dog::makeSound(void) const
{
	std::cout << "BUP! BUP!" << std::endl;
}

void	Dog::addIdea(std::string idea)
{
	if (this->_brain == NULL)
	{
		std::cout << "Dog: Error Brain is null." << std::endl;
		return ;
	}
	this->_brain->appendIdea(idea);
}

std::string	Dog::rememberIdea(size_t i)
{
	if (this->_brain == NULL)
	{
		std::cout << "Dog: Error Brain is null." << std::endl;
		return ("");
	}
	return (this->_brain->rememberIdea(i));
}
