/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 21:47:41 by gabriel           #+#    #+#             */
/*   Updated: 2024/08/05 21:27:28 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap	diamond("Gabriel");

	diamond.whoAmI();
	std::cout << "HP: " << diamond.getHitPoints() << std::endl;
	std::cout << "EP: " << diamond.getEnergyPoints() << std::endl;
	std::cout << "AD: " << diamond.getAttackDamage() << std::endl;
	diamond.attack("target");
	diamond.guardGate();
	diamond.highFivesGuys();

	DiamondTrap	copy(diamond);
	copy.whoAmI();
	return (0);
}
