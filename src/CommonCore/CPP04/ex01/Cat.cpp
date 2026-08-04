/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 22:40:39 by gabriel           #+#    #+#             */
/*   Updated: 2024/10/23 23:07:07 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Cat.hpp"

Cat::Cat(void) 
{
	this->_type ="cat";
	this->_brain = new Brain();
	std::cout << "Cat Default Constructor called." << std::endl;
}

Cat::Cat(Cat const &copy) : Animal()
{
	this->_type = copy._type;
	this->_brain = new Brain(*copy._brain);
	std::cout << "Cat Copy Constructor called." << std::endl;
}

Cat::~Cat(void)
{
	delete this->_brain;
	std::cout << "Cat Destructor called." << std::endl;
}

void	Cat::operator=(Cat const &cat)
{
	if (this != &cat)
	{
		this->_type = cat._type;
		if ( this->_brain != NULL)
			delete this->_brain;
		this->_brain = new Brain(*cat._brain);
		std::cout << "Cat Operator Equal called." << std::endl;
	}
}

void Cat::makeSound(void) const
{
	std::cout << "Meu! Meu!" << std::endl;
}

void	Cat::addIdea(std::string idea)
{
	if (this->_brain == NULL)
	{
		std::cout << "Cat: Error Brain is null." << std::endl;
		return ;
	}
	this->_brain->appendIdea(idea);
}

std::string	Cat::rememberIdea(size_t i)
{
	if (this->_brain == NULL)
	{
		std::cout << "Cat: Error Brain is null." << std::endl;
		return ("");
	}
	return (this->_brain->rememberIdea(i));
}
