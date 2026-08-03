/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StringHandler.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 22:58:55 by gabriel           #+#    #+#             */
/*   Updated: 2024/07/26 16:26:34 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

#include "StringHandler.hpp"

StringHandler::StringHandler(void)
{

}

StringHandler::StringHandler(std::string _content)
{
	this->content = _content;
}

StringHandler::~StringHandler(void)
{
	
}

void	StringHandler::setContent(std::string _content)
{
	this->content = _content;
}

std::string	StringHandler::replace(std::string pattern, std::string replace)
{
	size_t		position;
	size_t		last_position;
	std::string	text;
	std::string	pre;
	std::string	post;

	if (pattern.empty())
		return (this->content);
	text = "";
	last_position = 0;
	position = this->content.find(pattern, 0);
	while (position != std::string::npos)
	{
		pre = this->content.substr(last_position, position - last_position);
		last_position = position + pattern.size();
		text += pre + replace;
		position = this->content.find(pattern, last_position);
	}
	text += this->content.substr(last_position, this->content.size() - last_position);
	return (text);
}
