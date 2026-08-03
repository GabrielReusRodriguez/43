/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 22:27:10 by gabriel           #+#    #+#             */
/*   Updated: 2024/08/08 20:56:08 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog: virtual public Animal
{
	private:
		Brain	*_brain;
	public:
		Dog(void);
		Dog(Dog const &copy);
		~Dog(void);
		void	operator=(Dog const &dog);
		void	makeSound(void) const;
		void	addIdea(std::string idea);
		std::string	rememberIdea(size_t i);

};

#endif