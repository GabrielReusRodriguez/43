/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 16:59:32 by gabriel           #+#    #+#             */
/*   Updated: 2024/07/25 17:48:21 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

/*
	at class Members we use pointer because it can have weapon or not...
	BUT when we pass a  heap variable as a param we use the ref to avoid
	that C makes a copy ( with anohter address ) so it is the same 
	var and same memory address , if we get this memory address with & we 
	will get the same address of outside the function.

	Otherwhie at class we MUST use a pointer because the weapon can
	change the type. With a pointer we can have the updated value without 
	using a observer pattern.
*/

int	main(void)
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	return (0);
}