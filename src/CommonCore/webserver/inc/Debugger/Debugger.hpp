/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Debugger.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gabriel Reus  <gabrielin@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 20:18:40 by Gabriel Reu       #+#    #+#             */
/*   Updated: 2025/01/11 20:29:14 by Gabriel Reu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUGGER_HPP
# define DEBUGGER_HPP

# include <string>

# define DEBUG_HEADER	"DEBUG: "

class Debugger
{
	private:
		Debugger(void);
		~Debugger(void);
	public:
		static void	debug(const std::string& msg);
};

#endif