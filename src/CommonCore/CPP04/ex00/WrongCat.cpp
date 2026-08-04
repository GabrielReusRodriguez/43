/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 22:40:39 by gabriel           #+#    #+#             */
/*   Updated: 2024/10/23 22:54:42 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
	this->_type ="Wrongcat";
	std::cout << "WrongCat Default Constructor called." << std::endl;
}

WrongCat::WrongCat(WrongCat const &copy) : WrongAnimal()
{
	this->_type = copy._type;
	std::cout << "WrongCat Copy Constructor called." << std::endl;
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat Destructor called." << std::endl;
}

void	WrongCat::operator=(WrongCat const &cat)
{
	if (this != &cat)
	{
		this->_type = cat._type;
		std::cout << "WrongCat Operator Equal called." << std::endl;
	}
}

void WrongCat::makeSound(void) const
{
	std::cout << "Wrong Meu! Meu!" << std::endl;
}
