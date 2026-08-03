/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 00:56:03 by gabriel           #+#    #+#             */
/*   Updated: 2024/10/10 22:54:00 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "FragTrap.hpp"

FragTrap::FragTrap(void)
{
	this->setName("");
	this->setAttackDamage(FRAGTRAP_DEFAULT_ATTACKDAMAGE);
	this->setEnergyPoints(FRAGTRAP_DEFAULT_ENERGYPOINTS);
	this->setHitPoints(FRAGTRAP_DEFAULT_HITPOINTS);
	std::cout << "FragTrap Default Constructor called." << std::endl;
}

FragTrap::FragTrap(std::string const name) : ClapTrap(name)
{
	this->setAttackDamage(FRAGTRAP_DEFAULT_ATTACKDAMAGE);
	this->setEnergyPoints(FRAGTRAP_DEFAULT_ENERGYPOINTS);
	this->setHitPoints(FRAGTRAP_DEFAULT_HITPOINTS);	
	std::cout << "FragTrap Constructor of " << this->getName() <<" called." << std::endl;
}

FragTrap::FragTrap(FragTrap const &copy) : ClapTrap()
{
	this->setName(copy.getName());
	this->setEnergyPoints(copy.getEnergyPoints());
	this->setHitPoints(copy.getHitPoints());
	this->setAttackDamage(copy.getAttackDamage());
	std::cout << "FragTrap Copy Constructor called." << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap Destructor of " << this->getName() << " called." << std::endl;
}

void	FragTrap::operator=(FragTrap const &trap)
{
	if (this != &trap)
	{
		this->setName(trap.getName());
		this->setAttackDamage(trap.getAttackDamage());
		this->setEnergyPoints(trap.getEnergyPoints());
		this->setHitPoints(trap.getHitPoints());
		std::cout << "FragTrap Assigment operator called." << std::endl;
	}
}

void	FragTrap::highFivesGuys(void)
{
	if (this->getEnergyPoints() > 0)
		std::cout << "FragTrap " << this->getName() << " request highFive!" << std::endl;
	else
		std::cout << "FragTrap " << this->getName() << " is OUT of energy. "<< std::endl;
}
