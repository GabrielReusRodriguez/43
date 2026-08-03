/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 19:11:20 by gabriel           #+#    #+#             */
/*   Updated: 2024/08/10 21:49:22 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria(std::string const &type) : _type(type)
{
}

AMateria::~AMateria(void)
{
	
}

std::string const & AMateria::getType(void) const
{
	return (this->_type);
}

void	AMateria::use(ICharacter &target)
{
	(void)target;	
}
