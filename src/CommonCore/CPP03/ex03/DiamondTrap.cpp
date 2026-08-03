/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 01:29:41 by gabriel           #+#    #+#             */
/*   Updated: 2024/10/10 22:54:23 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap(), FragTrap(), ScavTrap()
{
	this->_name = "";
	this->setEnergyPoints(SCAVTRAP_DEFAULT_ENERGYPOINTS);
	this->setHitPoints(FRAGTRAP_DEFAULT_HITPOINTS);
	this->setAttackDamage(FRAGTRAP_DEFAULT_ATTACKDAMAGE);
	std::cout << "DiamondTrap Default Constructor of " << this->_name << " called." << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const &diamond)
	: ClapTrap(diamond), FragTrap(diamond), ScavTrap(diamond)
{
	this->_name = diamond._name;
	this->setEnergyPoints(diamond.getEnergyPoints());
	this->setHitPoints(diamond.getHitPoints());
	this->setAttackDamage(diamond.getAttackDamage());
	std::cout << "DiamondTrap Copy Constructor of " << this->_name << " called." << std::endl;
}

DiamondTrap::DiamondTrap(std::string name)
	: ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name)
{
	this->_name = name;
	this->setEnergyPoints(SCAVTRAP_DEFAULT_ENERGYPOINTS);
	this->setHitPoints(FRAGTRAP_DEFAULT_HITPOINTS);
	this->setAttackDamage(FRAGTRAP_DEFAULT_ATTACKDAMAGE);
	std::cout << "DiamondTrap Constructor of " << this->_name << " called." << std::endl;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap " << this->_name << " Destructor called." << std::endl;
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "DiamondTrap name: " << this->_name << "." << std::endl;
	std::cout << "ClapTrap name: " << this->ClapTrap::getName() << "." << std::endl;
}

void	DiamondTrap::attack(std::string const &target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::operator=(DiamondTrap const &diamond)
{
	if (this != &diamond)
	{
		this->_name = diamond._name;
		this->setName(diamond.ClapTrap::getName());
		this->setEnergyPoints(diamond.getEnergyPoints());
		this->setHitPoints(diamond.getHitPoints());
		this->setAttackDamage(diamond.getAttackDamage());
		std::cout << "DiamondTrap Assigment operator called." << std::endl;
	}
}
