/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 16:09:01 by gabriel           #+#    #+#             */
/*   Updated: 2024/07/25 16:28:54 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	Zombie	*zombie;
	size_t	i;

	zombie  = new Zombie[N];
	if ( zombie == NULL)
		return (NULL);
	i = 0;
	while (i < (size_t)N)
	{
		zombie[i].set_name(name);
		i++;
	}
	return (zombie);
}