/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 20:29:23 by gabriel           #+#    #+#             */
/*   Updated: 2024/10/23 23:31:48 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>

#include "Character.hpp"
#include "AMateria.hpp"

void	Character::initSlots(void)
{
	size_t	i;

	i = 0;
	while (i < CHARACTER_MAX_MATERIAS)
	{
		this->_inventory[i] = NULL;
		i++;
	}
	i = 0;
	while (i < CHARACTER_FLOOR_SIZE)
	{
		this->_floor[i] = NULL;
		i++;
	}
	this->_index = 0;
	this->_floor_index = 0;
}

void	Character::clearInventory(void)
{
	size_t	i;

	i = 0;
	while (i < CHARACTER_MAX_MATERIAS)
	{
		if (this->_inventory[i] != NULL)
			delete this->_inventory[i];
		this->_inventory[i] = NULL;
		i++;
	}
	i = 0;
	while (i < CHARACTER_FLOOR_SIZE)
	{
		if (this->_floor[i] != NULL)
			delete this->_floor[i];
		this->_floor[i] = NULL;
		i++;
	}
	this->_index = 0;
	this->_floor_index = 0;
}

void	Character::dropToFloor(AMateria *m)
{
	if (m == NULL)
		return ;
	if (this->_floor_index < CHARACTER_FLOOR_SIZE)
	{
		this->_floor[this->_floor_index] = m;
		this->_floor_index++;
	}
	else
		delete m;
}

Character::Character(void) : _name("")
{
	this->initSlots();
}

Character::Character(std::string name) : _name(name)
{
	this->initSlots();
}

Character::Character(Character const &copy) : _name(copy._name)
{
	size_t	i;

	this->initSlots();
	i = 0;
	while (i < CHARACTER_MAX_MATERIAS)
	{
		if (copy._inventory[i] != NULL)
			this->_inventory[i] = copy._inventory[i]->clone();
		else
			this->_inventory[i] = NULL;
		i++;
	}
	this->_index = copy._index;
}

Character::~Character(void)
{
	this->clearInventory();
}

void	Character::operator=(Character const &ch)
{
	size_t	i;

	if (this != &ch)
	{
		this->clearInventory();
		i = 0;
		while (i < CHARACTER_MAX_MATERIAS)
		{
			if (ch._inventory[i] != NULL)
				this->_inventory[i] = ch._inventory[i]->clone();
			else
				this->_inventory[i] = NULL;
			i++;
		}
		this->_name = ch._name;
		this->_index = ch._index;
	}
}

bool	Character::isInventoryFull(void)
{
	if (this->_index >= CHARACTER_MAX_MATERIAS)
		return (true);
	return (false);	

}

bool	Character::isInventoryEmpty(void)
{
	if (this->_index == 0)
		return (true);
	return (false);
}

std::string const & Character::getName() const
{
	return (this->_name);
}

void Character::equip(AMateria* m)
{
	if (this->isInventoryFull() || m == NULL)
		return ;
	this->_inventory[this->_index] = m;
	this->_index++;
}

/* unequip must NOT delete the materia (subject). We keep it on a floor. */
void Character::unequip(int idx)
{
	size_t	i;

	if (this->isInventoryEmpty() || idx < 0 || (size_t)idx >= this->_index)
		return;

	i = 0;
	if (this->_inventory[idx] != NULL)
	{
		this->dropToFloor(this->_inventory[idx]);
		this->_inventory[idx] = NULL;
		i = idx + 1;
		while (i < this->_index)
		{
			this->_inventory[i - 1] = this->_inventory[i];
			i++;
		}
		this->_inventory[this->_index - 1] = NULL;
		this->_index--;
	}
}

void Character::use(int idx, ICharacter& target)
{
	AMateria	*materia;
	
	if (idx < 0 || idx >= CHARACTER_MAX_MATERIAS )
	{
		std::cout << "ERROR: Incorrect idx : " << idx << std::endl;	
		return ;
	}
	if (this->isInventoryEmpty())
	{
		std::cout << "Inventory of character: " << this->getName() << " is Empty." << std::endl;
		return ;
	}
	if ((size_t)idx >= this->_index)
	{
		std::cout << "ERROR: You are requesting an empty position of the inventory." << std::endl;
		return ;
	}
	materia = 	this->_inventory[idx];
	if (materia == NULL)
	{
		std::cout << "ERROR: You have requested a NULL Material." << std::endl;
		return ;
	}
	materia->use(target);
}
