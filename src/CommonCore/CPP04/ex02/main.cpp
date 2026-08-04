/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 22:21:07 by gabriel           #+#    #+#             */
/*   Updated: 2024/08/09 22:27:45 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#define TOTAL_ANIMALS 10

int	main(void)
{

	/*
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	*/

/*
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete i;
	delete j;
*/
	//Animal animal;
	
	Animal *animals[TOTAL_ANIMALS];
	size_t	i;

	i = 0;
	while ( i < TOTAL_ANIMALS)
	{
		if ( i % 2 == 0)
		{
			animals[i] = new Dog();
		}
		else
		{
			animals[i] = new Cat();
		}
		i++;
	}	

	i = 0;
	while (i < TOTAL_ANIMALS)
	{
		delete animals[i];
		i++;
	}

	std::cout << "-------------------------------------" << std::endl;
	{
		std::cout << "Check deep copy of Dog class using copy constructor:" << std::endl;
		Dog *dogA = new Dog;
		dogA->addIdea("Hola mundo!");
		Dog *dogB = new Dog(*dogA);
		std::cout << "Idea 0 A" << dogA->rememberIdea(0) << std::endl;
		std::cout << "Idea 0 B" << dogB->rememberIdea(0) << std::endl;
		delete dogA;
		std::cout << "Idea 0 B" << dogB->rememberIdea(0) << std::endl;
		delete dogB;
	}

	std::cout << "-------------------------------------" << std::endl;
	{
		std::cout << "Check deep copy of Dog class using assignment operator overload:" << std::endl;
		Dog *dogA = new Dog;
		Dog *dogB = new Dog;

		*dogA = *dogB;
		delete dogA;
		delete dogB;
	}



	return (0);
}