/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WritterFileHandler.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 22:46:05 by gabriel           #+#    #+#             */
/*   Updated: 2024/07/26 13:48:38 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <fstream>
#include <iostream>

#include "WritterFileHandler.hpp"

WritterFileHandler::WritterFileHandler(void)
{
	this->filename.clear();
}

WritterFileHandler::WritterFileHandler(std::string _filename)
{
	this->filename = _filename;
}

WritterFileHandler::~WritterFileHandler(void)
{

}

void	WritterFileHandler::setFileName(std::string _filename)
{
	this->filename = _filename;
}

bool WritterFileHandler::writeContent(std::string content)
{
	std::ofstream writter;

	if (this->filename.empty())
	{
		std::cout << "ERROR: You have not passed the filename." << std::endl;
		return (false);
	}
	writter.open(this->filename.c_str());
	if (writter.is_open())
	{
		writter.write(content.c_str(), content.size());
		writter.close();
		return (true);
	}
	else
	{
		std::cout << "ERROR: openning "  << this->filename << std::endl;
		return (false);
	}
}