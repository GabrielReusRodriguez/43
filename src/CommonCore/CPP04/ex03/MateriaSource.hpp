/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 22:53:00 by gabriel           #+#    #+#             */
/*   Updated: 2024/08/10 21:23:29 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

# define MATERIASOURCE_MAX_NUM_MAT	4
class MateriaSource: public IMateriaSource
{
	private: 
		AMateria	*_templates[MATERIASOURCE_MAX_NUM_MAT];
		size_t		_index;

		bool	materiaExists(std::string const &type);

	public:
		MateriaSource(void);
		MateriaSource(MateriaSource const & copy);
		~MateriaSource(void);
		void	operator=(MateriaSource const & materiaSource);
		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);

};

#endif