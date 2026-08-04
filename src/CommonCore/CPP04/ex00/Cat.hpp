/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 22:28:46 by gabriel           #+#    #+#             */
/*   Updated: 2024/08/06 23:02:31 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : virtual public Animal
{
	public:
		Cat(void);
		Cat(Cat const &copy);
		~Cat(void);
		void operator=(Cat const &cat);
		void	makeSound(void) const;
};

#endif