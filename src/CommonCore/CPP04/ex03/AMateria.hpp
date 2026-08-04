/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 22:38:54 by gabriel           #+#    #+#             */
/*   Updated: 2024/08/10 19:32:22 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>

# include "ICharacter.hpp"

class AMateria
{
	protected:
		const std::string _type;
	
	public:
		AMateria(std::string  const &type);
		virtual ~AMateria(void);
		std::string const & getType(void) const;
		virtual AMateria *clone(void) const = 0;
		virtual void	use(ICharacter& target);

};

#endif