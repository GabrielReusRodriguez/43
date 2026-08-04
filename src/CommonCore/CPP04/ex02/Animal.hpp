/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 22:21:55 by gabriel           #+#    #+#             */
/*   Updated: 2024/08/09 22:04:53 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>


/* 

To make a class asbtract, we have to declare the function as vitual = 0; and 
we MUST implement it  in hcildren class
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
		virtual void	makeSound(void) const = 0;
		std::string	getType(void) const;
};

#endif