/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frite <frite@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 14:53:12 by frite             #+#    #+#             */
/*   Updated: 2024/10/01 16:13:37 by frite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
    const WrongAnimal *WrongMeta = new WrongAnimal();
    const WrongAnimal *wcat = new WrongCat();
    const Animal *meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound();
    j->makeSound();
    meta->makeSound();
    wcat->makeSound();
    WrongMeta->makeSound();

    delete meta;
    delete j;
    delete i;
    delete WrongMeta;
	delete wcat;

	std::cout << std::endl << "///////////////////////////////////////////" << std::endl << std::endl;

	Cat testcat;
	WrongCat testwcat;
	WrongAnimal testwanimal;
	
	testcat.makeSound();
	testwcat.makeSound();
	testwanimal.makeSound();
    
    return 0;
}
