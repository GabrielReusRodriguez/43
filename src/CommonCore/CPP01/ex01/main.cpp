/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 16:09:05 by gabriel           #+#    #+#             */
/*   Updated: 2024/07/25 16:29:32 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

#define N 10

int	main(void)
{
	Zombie *zombies;
	size_t	i;

	zombies = zombieHorde(N, "ZzZz");
	if (zombies == NULL)
	{
		std::cout << "ERROR at memory reserve." << std::endl;
		return  (1);
	}
	i = 0;
	while (i < N)
	{
		zombies[i].announce();
		i++;
	}
	delete [] zombies;
	return (0);
}