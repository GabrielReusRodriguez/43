/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 21:47:41 by gabriel           #+#    #+#             */
/*   Updated: 2024/07/31 22:34:41 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	clap("Gabriel");

	clap.attack("target");
	clap.takeDamage(4);
	clap.beRepaired(2);
	clap.takeDamage(50);
	clap.attack("target");
	clap.beRepaired(10);
	return (0);
}
