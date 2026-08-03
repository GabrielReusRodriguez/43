/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 16:34:24 by gabriel           #+#    #+#             */
/*   Updated: 2024/07/26 17:00:35 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <string>

# define NUM_LEVELS 4

class Harl
{
	public: 
		Harl(void);
		~Harl(void);
		void	complain(std::string level);
	
	private:
		void 	(Harl::*functions_ptr[NUM_LEVELS])(void);
		std::string functions_str[NUM_LEVELS];
		
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
};

#endif