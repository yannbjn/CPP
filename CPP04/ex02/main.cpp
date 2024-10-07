/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabejani <yabejani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 14:53:12 by frite             #+#    #+#             */
/*   Updated: 2024/10/07 17:15:25 by yabejani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

// Si tu veux empêcher l'instanciation directe de la classe de base Animal
// tout en maintenant la hiérarchie d'héritage, tu peux utiliser une classe abstraite.
// En C++, une classe devient abstraite dès qu'elle contient au moins
// une fonction virtuelle pure (une méthode virtuelle sans implémentation, marquée par = 0).
// L'idée ici est de rendre Animal abstrait afin qu'elle ne puisse jamais être instanciée directement.
// Seules les classes dérivées concrètes (Cat et Dog) pourront être instanciées.
// Même si le constructeur de la classe Animal sera toujours appelé dans le processus d'instanciation de Cat ou Dog,
// il n'y aura jamais de création d'objets directement de type Animal.


//CONSTRUCTOR AND DESTRUCTOR OF ANIMAL CLASS WILL STILL BE CALLED, BUT IT'S NOW IMPOSSIBLE TO CREATE AN INSTANCE OF THIS CLASS WITHOUT USING CAT OR DOG



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
    const Animal* j = new Dog();
    // const Animal* i = new Cat();

    delete j;
    // delete i;
    
    // std::cout << std::endl << "///////////////////////////////////////////" << std::endl << std::endl;

    // Cat testCat;
    // std::cout << std::endl << "///////////////////////////////////////////" << std::endl << std::endl;
    // Dog testDog;
    // std::cout << std::endl << "//////uncommenting whats under this should block compilation////////" << std::endl << std::endl;
    // Animal testAnimal;
    // std::cout << std::endl << "///////////////////////////////////////////" << std::endl << std::endl;
    // WrongAnimal testWrongAnimal;
    // std::cout << std::endl << "///////////////////////////////////////////" << std::endl << std::endl;
    // WrongCat testWrongCat;
    // std::cout << std::endl << "///////////////////////////////////////////" << std::endl << std::endl;

    // Animal* tab[20];

    // int x = 0;
    // for (; x < 10; x++)
    //     tab[x] = new Dog();
    // for (; x < 20; x++)
    //     tab[x] = new Cat();
    
    // x = 0;
    // for (; x < 10; x++)
    //     tab[x]->makeSound();
    // for (; x < 20; x++)
    //     tab[x]->makeSound();
    
    // x = 0;
    // for (; x < 20; x++)
    //     delete tab[x];
}
