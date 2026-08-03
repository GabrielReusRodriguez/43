/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 21:47:41 by gabriel           #+#    #+#             */
/*   Updated: 2024/08/04 01:15:36 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "FragTrap.hpp"

int	main(void)
{
	FragTrap	frag("Gabriel");

	frag.attack("target");
	frag.takeDamage(20);
	frag.beRepaired(10);
	frag.highFivesGuys();
	return (0);
}
