/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 22:47:23 by gabriel           #+#    #+#             */
/*   Updated: 2024/08/10 19:56:35 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

# define TYPE_ICE	"ice"


class Ice : public AMateria
{
	public:
		Ice(void);
		Ice(Ice const &copy);
		~Ice(void);
		void	operator=(Ice const &ice);

		AMateria *clone(void) const;
		void	use(ICharacter& target);
};

#endif