/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:36:12 by gabriel           #+#    #+#             */
/*   Updated: 2024/07/25 15:51:27 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class Zombie
{
	public:
		Zombie(std::string _name);
		~Zombie(void);
		void announce (void);

	private:
		std::string	name;
};

Zombie	*newZombie(std::string name);
void	randomChump( std::string name );

#endif