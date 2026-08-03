/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 22:21:55 by gabriel           #+#    #+#             */
/*   Updated: 2024/08/06 23:00:31 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>


/* I made the makeSound virtual to allow the specific call when 
we make a call  to makeSound with a pointer to base class.*/

/*
	To avoid Error: 
	
	error: deleting object of polymorphic class type ‘Animal’ which has 
	non-virtual destructor might cause undefined behavior [-Werror=delete-non-virtual-dtor]
	
	
	When we do a delete of a pointer to child class, we must declare 
	the destructor as  virtual
*/
class Animal
{
	protected:
		std::string _type;

	public:
		Animal(void);
		Animal(Animal const &copy);
		virtual ~Animal(void);
		void 	operator=(Animal const &animal);
		virtual void	makeSound(void) const;
		std::string	getType(void) const;
};

#endif