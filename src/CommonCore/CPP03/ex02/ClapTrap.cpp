/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 21:47:28 by gabriel           #+#    #+#             */
/*   Updated: 2024/10/10 22:55:42 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "ClapTrap.hpp"

/*
class ClapTrap
{
	private:
		std::string	_name;
		int			_hit_points;
		int			_energy_points;
		int			_attack_damage;

	public:
		ClapTrap(void);
		ClapTrap(Claptrap const &copy);
		ClapTrap(std::string const name);
		~ClapTrap(void);
		std::string	getName(void) const;
		int			getHitPoints(void) const;
		int			getEnergyPoints(void) const;
		int			getAttackDamage(void) const;
		void		setName(std::string const name);
		void		setHitPoints(int const hit_points);
		void		setEnergyPoints(int const energy_points);
		void		setAttackDamage(int const attack_damage);
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

void	operator=(ClapTrap &clap1 , ClapTrap &clap2);

*/

ClapTrap::ClapTrap(void)
{
	this->setName("");
	this->setEnergyPoints(CLAPTRAP_DEFAULT_ENERGYPOINTS);
	this->setHitPoints(CLAPTRAP_DEFAULT_HITPOINTS);
	this->setAttackDamage(CLAPTRAP_DEFAULT_ATTACKDAMAGE);
	std::cout << "ClapTrap Default Constructor called." << std::endl;
}

ClapTrap::ClapTrap(std::string const name)
{
	this->setName(name);
	this->setEnergyPoints(CLAPTRAP_DEFAULT_ENERGYPOINTS);
	this->setHitPoints(CLAPTRAP_DEFAULT_HITPOINTS);
	this->setAttackDamage(CLAPTRAP_DEFAULT_ATTACKDAMAGE);
	std::cout << "ClapTrap Constructor of " << this->_name <<" called." << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &copy)
{
	this->setName(copy.getName());
	this->setEnergyPoints(copy.getEnergyPoints());
	this->setHitPoints(copy.getHitPoints());
	this->setAttackDamage(copy.getAttackDamage());
	std::cout << "ClapTrap Copy Constructor called." << std::endl;
}

void	ClapTrap::operator=(ClapTrap const &clap)
{
	if (this != &clap)
	{
		this->setName(clap.getName());
		this->setEnergyPoints(clap.getEnergyPoints());
		this->setHitPoints(clap.getHitPoints());
		this->setAttackDamage(clap.getAttackDamage());
		std::cout << "ClapTrap Assigment operator called." << std::endl;
	}
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap Destructor of " << this->_name << " called." << std::endl;	
}

void	ClapTrap::attack(const std::string &target)
{
	if (this->_energy_points > 0 && this->_hit_points > 0)
	{
		this->_energy_points--;
		std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attack_damage << " points of damage!" << std::endl;
	}
	else
	{
		if (this->_hit_points <= 0)
		{
			std::cout << "ClapTrap " << this->_name << " is dead." << std::endl;
			return ;
		}
		if (this->_energy_points <= 0)
		{
			std::cout << "ClapTrap " << this->_name << " is out of energy." << std::endl;
			return ;
		}

		std::cout << "ClapTrap " << this->_name << " has NOT energy points to attack!" << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hit_points > 0)
	{
		this->_hit_points -= amount;
		std::cout << "ClapTrap " << this->_name << " has taken " << amount << " points of damage " << std::endl;
		if (this->_hit_points < 0)
			this->_hit_points = 0;
	}
	else
	{
		std::cout << "ClapTrap " << this->_name << " is already dead." << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energy_points > 0 && this->_hit_points > 0)
	{
		this->_hit_points += amount;
		this->_energy_points--;
		std::cout << "ClapTrap " << this->_name << " is repaired, getting " << amount << " points healed!" << std::endl;
	}
	else
	{
		if (this->_hit_points <= 0)
		{
			std::cout << "ClapTrap " << this->_name << " is dead." << std::endl;
			return ;
		}
		std::cout << "ClapTrap " << this->_name << " has NOT energy points to be repaired!" << std::endl;
	}
}

std::string	ClapTrap::getName(void) const
{
	return (this->_name);
}

int			ClapTrap::getHitPoints(void) const
{
	return (this->_hit_points);
}

int			ClapTrap::getEnergyPoints(void) const
{
	return (this->_energy_points);
}

int			ClapTrap::getAttackDamage(void) const
{
	return (this->_attack_damage);
}

void		ClapTrap::setName(std::string const name)
{
	this->_name = name;
}

void		ClapTrap::setHitPoints(int const hit_points)
{
	this->_hit_points = hit_points;
}

void		ClapTrap::setEnergyPoints(int const energy_points)
{
	this->_energy_points = energy_points;
}

void		ClapTrap::setAttackDamage(int const attack_damage)
{
	this->_attack_damage = attack_damage;
}