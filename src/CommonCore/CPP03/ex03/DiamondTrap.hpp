/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 01:18:28 by gabriel           #+#    #+#             */
/*   Updated: 2024/10/10 22:34:08 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include <string>

# include "FragTrap.hpp"
# include "ScavTrap.hpp"

/*
n C++98 and C++03 the OCCF had four different methods that the C++ compiler is willing to generate:

    Default constructor
    Copy constructor
    Destructor
    Copy assignment operator
*/


//Here we do not need the virutal because they are herency once.
class DiamondTrap : public FragTrap, public ScavTrap
{
	private:
		std::string _name;

	public:
		DiamondTrap(void);
		DiamondTrap(std::string const name);
		DiamondTrap(DiamondTrap const &diamond);
		~DiamondTrap(void);
		void	whoAmI(void);
		void	attack(std::string const &target);
		void	operator=(DiamondTrap const &daimond);
};

#endif