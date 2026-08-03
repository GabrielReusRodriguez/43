/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ReaderFileHandler.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 22:11:03 by gabriel           #+#    #+#             */
/*   Updated: 2024/07/26 14:43:30 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

#include "ReaderFileHandler.hpp"

/*In CPP we cannot assign null to string because it is NOT  a pointer.*/
ReaderFileHandler::ReaderFileHandler(void)
{
	this->filename.clear();
}

ReaderFileHandler::ReaderFileHandler(std::string _filename)
{
	this->filename = _filename;
	this->content = "";
}

ReaderFileHandler::~ReaderFileHandler(void)
{

}

void	ReaderFileHandler::setFileName(std::string _filename)
{
	this->filename = _filename;
}

void	ReaderFileHandler::cleafBuffer(char *buffer, size_t buffer_size)
{
	size_t	i;

	i = 0;
	while ( i < buffer_size)
	{
		buffer[i] = '\0';
		i++;
	}
}

bool ReaderFileHandler::readContent(void)
{
	std::ifstream	fileReader;
	std::string		line;
	bool			first;

	if (this->filename.empty())
	{
		std::cout << "ERROR: You have not informed the filename." << std::endl;
		return (false);
	}
	fileReader.open(this->filename.c_str());
	if (!fileReader.is_open())
	{
		std::cout << "ERROR: The file you are trying to open '" << this->filename << "' does NOT exists." << std::endl;
		return (false);
	}
	this->content.clear();
	first = true;
	while (std::getline(fileReader, line))
	{
		if (!first)
			this->content.append("\n");
		this->content.append(line);
		first = false;
	}
	fileReader.close();
	return (true);
}

std::string	ReaderFileHandler::getContent(void)
{
	return (this->content);
}