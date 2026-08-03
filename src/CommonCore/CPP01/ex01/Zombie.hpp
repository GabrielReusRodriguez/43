/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:36:12 by gabriel           #+#    #+#             */
/*   Updated: 2024/07/25 16:22:08 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class Zombie
{
	public:
		Zombie(void);
		~Zombie(void);
		void 	announce (void);
		void	set_name(std::string _name);

	private:
		std::string	name;
};

Zombie	*zombieHorde(int N, std::string name);

#endif