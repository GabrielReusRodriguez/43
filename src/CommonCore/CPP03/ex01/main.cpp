/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 21:47:41 by gabriel           #+#    #+#             */
/*   Updated: 2024/08/01 23:42:33 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap	scav("Gabriel");

	scav.attack("target");
	scav.takeDamage(20);
	scav.beRepaired(10);
	scav.guardGate();
	return (0);
}
