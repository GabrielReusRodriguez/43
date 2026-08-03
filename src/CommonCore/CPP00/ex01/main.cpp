/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 12:19:34 by greus-ro          #+#    #+#             */
/*   Updated: 2024/07/23 23:25:44 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>

#include "Contact.hpp"
#include "PhoneBook.hpp"

#define	CMD_EXIT	"EXIT"
#define CMD_ADD		"ADD"
#define CMD_SEARCH	"SEARCH"

void	add_contact(PhoneBook &phonebook)
{
	phonebook.add();
}

void	search_contact(PhoneBook phonebook)
{	
	phonebook.search();
}

int main(int argc, char **argv)
{
	PhoneBook   phonebook;
	std::string	line;

	(void)argc;
	(void)argv;

	line = "";
	while (line.compare(CMD_EXIT) != 0)
	{
		//std::cin >> line;
		std::cout << "Enter a command: ";
		std::getline(std::cin, line);
		if (line.compare(CMD_ADD) == 0)
			add_contact(phonebook);
		if (line.compare(CMD_SEARCH) == 0)
			search_contact(phonebook);
	}
	return (0);
}