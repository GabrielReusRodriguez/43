/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 22:58:30 by gabriel           #+#    #+#             */
/*   Updated: 2024/08/06 22:01:30 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# define SCAVTRAP_DEFAULT_HITPOINTS 100
# define SCAVTRAP_DEFAULT_ENERGYPOINTS 50
# define SCAVTRAP_DEFAULT_ATTACKDAMAGE 20

# include <string>

# include "ClapTrap.hpp"

/*
virtual public ensures that only a copy of the object is inheretance.
*/
class ScavTrap : virtual public ClapTrap
{
	private:

	public:
		ScavTrap(void);
		ScavTrap(ScavTrap const &copy);
		ScavTrap(std::string const _name);
		~ScavTrap(void);
		void	attack(const std::string& target);
		void	guardGate(void);
		void	operator=(ScavTrap const &trap);
};


#endif