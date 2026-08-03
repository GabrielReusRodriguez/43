/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 22:00:50 by gabriel           #+#    #+#             */
/*   Updated: 2024/07/26 16:15:25 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

#include "ReaderFileHandler.hpp"
#include "WritterFileHandler.hpp"
#include "StringHandler.hpp"

int	main(int argc, char **argv)
{

	ReaderFileHandler 	reader;
	WritterFileHandler 	writter;
	StringHandler		string_handler;
	std::string			content;

	if (argc != 4)
	{
		std::cout << "ERROR: bad arguments: ex04 filename string1 string2" << std::endl;
		return (1);
	}
	if (std::string(argv[2]).empty())
	{
		std::cout << "ERROR: s1 must not be empty." << std::endl;
		return (1);
	}
	reader.setFileName(argv[1]);
	if (!reader.readContent())
		return (1);
	content = reader.getContent();
	string_handler.setContent(content);
	content = string_handler.replace(argv[2], argv[3]);
	writter.setFileName(std::string(argv[1]) + ".replace");
	if (!writter.writeContent(content))
		return (1);
	return (0);
}