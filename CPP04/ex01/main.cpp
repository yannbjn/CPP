/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabejani <yabejani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 14:53:12 by frite             #+#    #+#             */
/*   Updated: 2024/11/05 17:28:37 by yabejani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main(void)
{
    Animal* tab[20];

    int x = 0;
    for (; x < 10; x++)
        tab[x] = new Dog();
    for (; x < 20; x++)
        tab[x] = new Cat();
    
    x = 0;
    for (; x < 10; x++)
        tab[x]->makeSound();
    for (; x < 20; x++)
        tab[x]->makeSound();
    
    x = 0;
    for (; x < 20; x++)
        delete tab[x];
	
	// Check if deep copy
	
	// Dog OGdog;
	// Cat OGcat;
	
	// OGdog.setIdea(0, "This is a nice tree to pee on.");
	// OGdog.setIdea(1, "Wow another great tree to pee on!");

	// OGcat.setIdea(0, "This dog looks dumb.");
	// OGcat.setIdea(1, "I'm gonna scratch his face.");

	// Dog COPYdog = OGdog;
	// Cat COPYcat = OGcat;

	// std::cout << "OGdog idea: " << OGdog.getIdea(0) << std::endl;
	// std::cout << "OGdog idea: " << OGdog.getIdea(1) << std::endl;
	// std::cout << "COPYdog idea: " << COPYdog.getIdea(0) << std::endl;
	// std::cout << "COPYdog idea: " << COPYdog.getIdea(1) << std::endl;

	// std::cout << "OGcat idea: " << OGcat.getIdea(0) << std::endl;
	// std::cout << "OGcat idea: " << OGcat.getIdea(1) << std::endl;
	// std::cout << "COPYcat idea: " << COPYcat.getIdea(0) << std::endl;
	// std::cout << "COPYcat idea: " << COPYcat.getIdea(1) << std::endl;


	// COPYdog.setIdea(0, "woof woof woof");
	// COPYdog.setIdea(1, "ball ball ball");
	// COPYcat.setIdea(0, "This dog looks nice.");
	// COPYcat.setIdea(1, "I really love this dog");

	// std::cout << "OGdog idea: " << OGdog.getIdea(0) << std::endl;
	// std::cout << "OGdog idea: " << OGdog.getIdea(1) << std::endl;
	// std::cout << "COPYdog idea: " << COPYdog.getIdea(0) << std::endl;
	// std::cout << "COPYdog idea: " << COPYdog.getIdea(1) << std::endl;

	// std::cout << "OGcat idea: " << OGcat.getIdea(0) << std::endl;
	// std::cout << "OGcat idea: " << OGcat.getIdea(1) << std::endl;
	// std::cout << "COPYcat idea: " << COPYcat.getIdea(0) << std::endl;
	// std::cout << "COPYcat idea: " << COPYcat.getIdea(1) << std::endl;
}
