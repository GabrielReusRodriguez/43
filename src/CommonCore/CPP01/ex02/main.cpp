/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 16:41:04 by gabriel           #+#    #+#             */
/*   Updated: 2024/07/25 16:49:28 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>


/* A reference is an alias 4 another variable so it is another name
for the same var.*/
int	main(void)
{
	std::string salute;
	std::string *stringPTR;
	std::string	&stringREF = salute;

	salute = "HI THIS IS BRAIN";
	stringPTR = &salute;

	std::cout << "Memory Address of string: " << &salute << std::endl;
	std::cout << "Memory Address held by stringPTR " << stringPTR << std::endl;
	std::cout << "Memory Address held by stringREF " << &stringREF << std::endl;

	std::cout << "Value of string: " << salute << std::endl;
	std::cout << "Value pointed by stringPTR: " << *stringPTR << std::endl;
	std::cout << "Value pointed by stringREF: " << stringREF << std::endl;

	return (0);
}