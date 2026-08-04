/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 22:50:25 by gabriel           #+#    #+#             */
/*   Updated: 2024/08/10 21:24:47 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"

# define CHARACTER_MAX_MATERIAS	4
# define CHARACTER_FLOOR_SIZE	16

class Character : public ICharacter
{

	private:
		AMateria	*_inventory[CHARACTER_MAX_MATERIAS];
		AMateria	*_floor[CHARACTER_FLOOR_SIZE];
		std::string	_name;
		size_t		_index;
		size_t		_floor_index;

		bool	isInventoryFull(void);
		bool	isInventoryEmpty(void);
		void	initSlots(void);
		void	clearInventory(void);
		void	dropToFloor(AMateria *m);
	public:
	
		Character(void);
		Character(std::string name);
		Character(Character const &copy);
		~Character(void);
		void	operator=(Character const &character);

		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};

#endif
