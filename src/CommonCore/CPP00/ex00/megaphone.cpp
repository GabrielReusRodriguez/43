/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 23:20:35 by gabriel           #+#    #+#             */
/*   Updated: 2024/06/28 11:37:28 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

/*
void	magnifice(char *str)
{
	size_t	i;
	char	character;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i]  >= 'a' && str[i] <= 'z')
			character = str[i] - 32;
		else
			character = str[i];
		std::cout << character;
		i++;
	}
}
*/

void	magnifice(std::string str)
{
	char					character;
	std::string::iterator	it;

	it = str.begin();
	while (it != str.end())
	{
		if (*it  >= 'a' && *it <= 'z')
			character = *it - 32;
		else
			character = *it;
		std::cout << character;
		it++;
	}
}

int main(int argc, char **argv)
{
	int		i;

	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
	else
	{
		i = 1;
		while (i < argc)
		{
			magnifice(argv[i]);
			i++;
		}
	}
	std::cout << std::endl;
	return (0);
}