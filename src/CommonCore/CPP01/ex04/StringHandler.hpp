/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StringHandler.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 22:54:51 by gabriel           #+#    #+#             */
/*   Updated: 2024/07/26 13:34:06 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef STRINGHANDLER_HPP
# define STRINGHANDLER_HPP

# include <string>

class StringHandler
{
	private: 
		std::string content;

	public:
		StringHandler(void);
		StringHandler(std::string content);
		~StringHandler(void);
		void	setContent(std::string _content);
		std::string	replace(std::string pattern, std::string replace);
};

#endif