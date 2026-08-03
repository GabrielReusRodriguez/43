/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 22:28:46 by gabriel           #+#    #+#             */
/*   Updated: 2024/08/08 20:53:13 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"


class Cat : virtual public Animal
{
	private:
		Brain	*_brain;
	public:
		Cat(void);
		Cat(Cat const &copy);
		~Cat(void);
		void	operator=(Cat const &cat);
		void	makeSound(void) const;
		void	addIdea(std::string idea);
		std::string	rememberIdea(size_t i);
};

#endif