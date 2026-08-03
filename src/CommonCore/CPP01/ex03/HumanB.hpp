/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 17:07:00 by gabriel           #+#    #+#             */
/*   Updated: 2024/07/25 17:36:08 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <string>
# include "Weapon.hpp"

class HumanB
{
	private:
		std::string name;
		Weapon		*weapon;
	
	public:
		HumanB(std::string name);
		HumanB(std::string _name, Weapon& _weapon);
		~HumanB(void);
		void	setWeapon(Weapon &_weapon);
		void	attack(void);
};

#endif