/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 20:08:23 by gabriel           #+#    #+#             */
/*   Updated: 2024/08/08 20:48:44 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>

# define BRAIN_NUMBER_IDEAS 100

class Brain
{
	private:
		std::string	_ideas[BRAIN_NUMBER_IDEAS];
		size_t	_num_ideas;

	public:
		Brain(void);
		Brain(Brain const &copy);
		virtual ~Brain(void);
		void	operator=(Brain const &brain);
		void	appendIdea(std::string idea);
		std::string	rememberIdea(size_t i);

};

#endif