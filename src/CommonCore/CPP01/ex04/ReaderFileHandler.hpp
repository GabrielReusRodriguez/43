/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ReaderFileHandler.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 22:04:32 by gabriel           #+#    #+#             */
/*   Updated: 2024/07/26 13:35:30 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FILEHANDLER_HPP
# define FILEHANDLER_HPP

# include <string>

# define READ_BUFFER 50

class ReaderFileHandler
{
	private:
		std::string filename;
		std::string content;

		void	cleafBuffer(char *buffer, size_t buffer_size);
	
	public:
		ReaderFileHandler(void);
		ReaderFileHandler(std::string filename);
		~ReaderFileHandler(void);
		void	setFileName(std::string _fileName);
		bool	readContent(void);
		std::string	getContent(void);
		

};

#endif