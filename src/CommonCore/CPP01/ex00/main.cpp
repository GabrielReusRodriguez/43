/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:35:53 by gabriel           #+#    #+#             */
/*   Updated: 2024/07/25 16:04:08 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*
 * Heap (newZombie): when the zombie must outlive the function that creates it.
 * Stack (randomChump): when it only lives inside the function; destroyed on return.
 */
int	main(void)
{
	Zombie	*zombie_heap;

	zombie_heap = newZombie("Zombie heap");
	if (zombie_heap != NULL)
	{
		zombie_heap->announce();
		delete (zombie_heap);
	}
	randomChump("Zombie stack");
	return (0);
}