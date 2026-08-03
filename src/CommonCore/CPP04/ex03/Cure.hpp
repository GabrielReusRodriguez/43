/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 22:49:13 by gabriel           #+#    #+#             */
/*   Updated: 2024/08/10 21:33:17 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

# define TYPE_CURE "cure"

class Cure : public AMateria
{
	public:
		Cure(void);
		Cure(Cure const &copy);
		~Cure(void);
		void	operator=(Cure const &cure);

		AMateria *clone(void) const;
		void	use(ICharacter& target);
};

#endif