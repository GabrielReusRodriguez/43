/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WritterFileHandler.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 22:44:07 by gabriel           #+#    #+#             */
/*   Updated: 2024/07/26 13:36:54 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRITTERFILEHANDLER_HPP
# define WRITTERFILEHANDLER_HPP

# include <string>

class WritterFileHandler
{
	private:
		std::string	filename;
		
	public:
	WritterFileHandler(void);
	WritterFileHandler(std::string filename);
	~WritterFileHandler(void);
	void	setFileName(std::string _filename);
	bool	writeContent(std::string content);
};

#endif