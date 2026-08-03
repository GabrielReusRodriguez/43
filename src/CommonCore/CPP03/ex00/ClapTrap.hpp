/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 21:47:02 by gabriel           #+#    #+#             */
/*   Updated: 2024/10/10 21:56:02 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# define CLAPTRAP_DEFAULT_HITPOINTS 10
# define CLAPTRAP_DEFAULT_ENERGYPOINTS 10
# define CLAPTRAP_DEFAULT_ATTACKDAMAGE 0

# include <string>


/* We use the reference in copy constructor because if we do not use it
	it will pass a copy of the object and it would call the copy constructor
	making an infinite loop.*/
class ClapTrap
{
	private:
		std::string	_name;
		int			_hit_points;
		int			_energy_points;
		int			_attack_damage;

	public:
		ClapTrap(void);
		ClapTrap(ClapTrap const &copy);
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
		void	operator=(ClapTrap const &clap);

};

#endif