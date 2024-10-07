/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabejani <yabejani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 14:53:12 by frite             #+#    #+#             */
/*   Updated: 2024/10/07 16:56:33 by yabejani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

// int main()
// {
//     const WrongAnimal *WrongMeta = new WrongAnimal();
//     const WrongAnimal *wcat = new WrongCat();
//     const Animal *meta = new Animal();
//     const Animal* j = new Dog();
//     const Animal* i = new Cat();
//     std::cout << j->getType() << " " << std::endl;
//     std::cout << i->getType() << " " << std::endl;
//     i->makeSound();
//     j->makeSound();
//     meta->makeSound();
//     wcat->makeSound();
//     WrongMeta->makeSound();

//     delete meta;
//     delete j;
//     delete i;
//     delete WrongMeta;
// 	delete wcat;

// 	std::cout << std::endl << "///////////////////////////////////////////" << std::endl << std::endl;

// 	Cat testcat;
// 	WrongCat testwcat;
// 	WrongAnimal testwanimal;
	
// 	testcat.makeSound();
// 	testwcat.makeSound();
// 	testwanimal.makeSound();
    
//     return 0;
// }

int main(void)
{
    // const Animal* j = new Dog();
    // const Animal* i = new Cat();

    // delete j;
    // delete i;
    
    // std::cout << std::endl << "///////////////////////////////////////////" << std::endl << std::endl;

    // Cat testCat;
    // std::cout << std::endl << "///////////////////////////////////////////" << std::endl << std::endl;
    // Dog testDog;
    // std::cout << std::endl << "///////////////////////////////////////////" << std::endl << std::endl;
    // Animal testAnimal;
    // std::cout << std::endl << "///////////////////////////////////////////" << std::endl << std::endl;
    // WrongAnimal testWrongAnimal;
    // std::cout << std::endl << "///////////////////////////////////////////" << std::endl << std::endl;
    // WrongCat testWrongCat;
    // std::cout << std::endl << "///////////////////////////////////////////" << std::endl << std::endl;

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
}
