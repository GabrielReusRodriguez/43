/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 19:36:04 by gabriel           #+#    #+#             */
/*   Updated: 2024/08/10 21:33:45 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void) : _index(0)
{
	size_t	i;

	i = 0;
	while (i < MATERIASOURCE_MAX_NUM_MAT)
	{
		this->_templates[i] = NULL;
		i++;
	}
}

MateriaSource::MateriaSource(MateriaSource const &copy)
{
	size_t	i;

	i = 0;
	this->_index = copy._index;
	while (i < MATERIASOURCE_MAX_NUM_MAT)
	{
		if (copy._templates[i] != NULL)
			this->_templates[i] = copy._templates[i]->clone();
		else
			this->_templates[i] = NULL;
		i++;
	}
}

MateriaSource::~MateriaSource(void)
{
	size_t	i;

	i = 0;
	while ( i < MATERIASOURCE_MAX_NUM_MAT)
	{
		if (this->_templates[i] != NULL)
			delete this->_templates[i];
		i++;
	}
}

void	MateriaSource::operator=(MateriaSource const &ms)
{
	size_t	i;

	if (this == &ms)
		return ;
	this->_index =  ms._index;
	i = 0;
	while (i < MATERIASOURCE_MAX_NUM_MAT)
	{
		if (this->_templates[i] != NULL)
			delete this->_templates[i];
		if (ms._templates[i] != NULL)
			this->_templates[i] = ms._templates[i]->clone();
		else
			this->_templates[i] = NULL;
		i++;
	}
}

bool	MateriaSource::materiaExists(std::string const &type)
{
	size_t	i;

	i = 0;
	while (i < MATERIASOURCE_MAX_NUM_MAT)
	{
		if (this->_templates[i] != NULL && this->_templates[i]->getType() == type)
			return (true);
		i++;
	}
	return (false);
}

/*
	We have to destroy the object if the place in inventary is full
	or the type was already learned.
*/
void	MateriaSource::learnMateria(AMateria *materia)
{
	if (materia == NULL)
		return ;
	if (this->materiaExists(materia->getType()))
	{
		delete materia;
		return ;
	}
	if (this->_templates[this->_index] != NULL)
		delete this->_templates[this->_index];
	this->_templates[this->_index] = materia;
	this->_index++;
	if (this->_index >= MATERIASOURCE_MAX_NUM_MAT)
		this->_index = 0;
}

AMateria	*MateriaSource::createMateria(std::string const & type)
{
	size_t	i;

	i = 0;
	while (i < MATERIASOURCE_MAX_NUM_MAT)
	{
		if (this->_templates[i] != NULL)
		{
			if(this->_templates[i]->getType() == type)
				return this->_templates[i]->clone();
		}
		i++;
	}
	return (NULL);
}
