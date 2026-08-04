/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 22:40:39 by gabriel           #+#    #+#             */
/*   Updated: 2024/10/23 22:52:10 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Cat.hpp"

Cat::Cat(void)
{
	this->_type ="cat";
	std::cout << "Cat Default Constructor called." << std::endl;
}

Cat::Cat(Cat const &copy) : Animal()
{
	this->_type = copy._type;
	std::cout << "Cat Copy Constructor called." << std::endl;
}

Cat::~Cat(void)
{
	std::cout << "Cat Destructor called." << std::endl;
}

void	Cat::operator=(Cat const &cat)
{
	if (this != &cat)
	{
		this->_type = cat._type;
		std::cout << "Cat Operator Equal called." << std::endl;
	}
}

void Cat::makeSound(void) const
{
	std::cout << "Meu! Meu!" << std::endl;
}
