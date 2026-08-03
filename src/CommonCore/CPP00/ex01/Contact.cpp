/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 11:45:45 by greus-ro          #+#    #+#             */
/*   Updated: 2024/06/28 13:24:11 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
	this->first_name      = "";
	this->last_name       = "";
	this->nickname        = "";
	this->phone_number	= "";
	this->darkest_secret	= "";
}

Contact::Contact(std::string _first_name, std::string _last_name, std::string _nickname, std::string _phone_number, std::string _darkest_secret)
{
	this->first_name      	= _first_name;
	this->last_name       	= _last_name;
	this->nickname        	= _nickname;
	this->phone_number		= _phone_number;
	this->darkest_secret	= _darkest_secret;
}

Contact::~Contact(void)
{

}

std::string Contact::get_first_name(void)
{
	return (this->first_name);
}

std::string Contact::get_last_name(void)
{
	return (this->last_name);
}

std::string Contact::get_nickname(void)
{
	return (this->nickname);
}

std::string Contact::get_phone_number(void)
{
	return (this->phone_number);
}

std::string Contact::get_darkest_secret(void)
{
	return (this->darkest_secret);
}

void	Contact::set_first_name(std::string _first_name)
{
	this->first_name = _first_name;
}

void	Contact::set_last_name(std::string _last_name)
{
	this->last_name = _last_name;
}

void	Contact::set_nickname(std::string _nickname)
{
	this->nickname = _nickname;
}

void	Contact::set_darkest_secret(std::string _darkest_secret)
{
	this->darkest_secret = _darkest_secret;
}

void	Contact::set_phone_number(std::string _phone_number)
{
	this->phone_number = _phone_number;
}
