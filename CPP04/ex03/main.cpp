/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabejani <yabejani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:28:42 by frite             #+#    #+#             */
/*   Updated: 2024/10/25 16:27:23 by yabejani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include "IMateriaSource.hpp"
#include "ICharacter.hpp"


// int main()
// {
// 	IMateriaSource* src = new MateriaSource();
// 	src->learnMateria(new Ice());
// 	src->learnMateria(new Cure());
// 	ICharacter* me = new Character("me");
// 	ICharacter* bob = new Character("bob");
// 	AMateria* tmp;
// 	AMateria* tmpb;
// 	tmp = src->createMateria("ice");
// 	tmpb = src->createMateria("ice");
// 	me->equip(tmp);
// 	bob->equip(tmpb);
// 	tmp = src->createMateria("cure");
// 	tmpb = src->createMateria("cure");
// 	me->equip(tmp);
// 	bob->equip(tmpb);
// 	tmp = src->createMateria("ice");
// 	tmpb = src->createMateria("ice");
// 	me->equip(tmp);
// 	bob->equip(tmpb);
// 	tmp = src->createMateria("cure");
// 	tmpb = src->createMateria("cure");
// 	me->equip(tmp);
// 	bob->equip(tmpb);
// 	tmp = src->createMateria("ice");
// 	tmpb = src->createMateria("ice");
// 	me->equip(tmp);
// 	bob->equip(tmpb);
// 	me->use(0, *bob);
// 	me->use(1, *bob);
// 	me->use(2, *bob);
// 	me->use(3, *bob);
// 	me->use(4, *bob);
// 	static_cast<Character*> (me)->displayinvetory();
// 	bob->use(0, *me);
// 	bob->use(1, *me);
// 	bob->unequip(1);
// 	bob->use(1, *me);
// 	me->unequip(0);
// 	me->unequip(3);
// 	static_cast<Character*> (me)->displayinvetory();
// 	me->use(3, *bob);
// 	me->use(5, *bob);
// 	delete bob;
// 	delete me;
// 	delete src;
// 	delete tmp;
// 	delete tmpb;
// 	return 0;
// }

int main()
{

/***************MANDATORY***************/
IMateriaSource* src = new MateriaSource();
src->learnMateria(new Ice());
src->learnMateria(new Cure());

ICharacter* me = new Character("me");
AMateria* tmp;
tmp = src->createMateria("ice");
me->equip(tmp);
me->equip(tmp);
me->equip(tmp);
me->equip(tmp);
me->equip(tmp);
me->equip(tmp);
me->equip(tmp);
tmp = src->createMateria("cure");
me->equip(tmp);
ICharacter* bob = new Character("bob");
static_cast<Character*> (me)->displayinvetory();
me->unequip(2);
static_cast<Character*> (me)->displayinvetory();
me->equip(tmp);
static_cast<Character*> (me)->displayinvetory();
me->use(0, *bob);
me->use(1, *bob);
delete bob;
delete me;
delete src;
// /********************************************/

// /***************INVENTORY FULL***************/
// IMateriaSource* src = new MateriaSource();
// src->learnMateria(new Ice());
// src->learnMateria(new Cure());
// src->learnMateria(new Ice());
// src->learnMateria(new Ice());
// src->learnMateria(new Ice());


// ICharacter* me = new Character("me");
// AMateria* tmp;
// static_cast<Character*> (me)->displayinvetory();

// tmp = src->createMateria("ice");
// me->equip(tmp);
// tmp = src->createMateria("ice");
// me->equip(tmp);
// tmp = src->createMateria("cure");
// me->equip(tmp);
// tmp = src->createMateria("ice");
// me->equip(tmp);
// tmp = src->createMateria("cure");
// me->equip(tmp);
// tmp = src->createMateria("ice");
// me->equip(tmp);

// static_cast<Character*> (me)->displayinvetory();
// ICharacter* bob = new Character("bob");
// me->use(0, *bob);
// me->use(2, *bob);
// delete bob;
// delete me;
// delete src;
// /********************************************/

// // /******************WRONGTYPE***************/
// IMateriaSource* src = new MateriaSource();
// src->learnMateria(new Ice());
// src->learnMateria(new Cure());
// ICharacter* me = new Character("me");
// AMateria* tmp;
// static_cast<Character*> (me)->displayinvetory();
// tmp = src->createMateria("fire");
// me->equip(tmp);
// tmp = src->createMateria("cure");
// me->equip(tmp);
// tmp = src->createMateria("water");
// me->equip(tmp);
// tmp = src->createMateria("ice");
// me->equip(tmp);

// static_cast<Character*> (me)->displayinvetory();
// ICharacter* bob = new Character("bob");
// me->use(0, *bob);
// me->use(1, *bob);
// delete bob;
// delete me;
// delete src;
/********************************************/

/*********************UNEQUIP********************/
// IMateriaSource* src = new MateriaSource();
// src->learnMateria(new Ice());
// src->learnMateria(new Cure());
// ICharacter* me = new Character("me");
// AMateria* tmp;
// static_cast<Character*> (me)->displayinvetory();
// tmp = src->createMateria("ice");
// me->equip(tmp);
// tmp = src->createMateria("cure");
// me->equip(tmp);
// tmp = src->createMateria("ice");
// me->equip(tmp);
// tmp = src->createMateria("cure");
// me->equip(tmp);
// static_cast<Character*> (me)->displayinvetory();
// me->unequip(0);
// static_cast<Character*> (me)->displayinvetory();
// me->equip(tmp);
// static_cast<Character*> (me)->displayinvetory();

// ICharacter* bob = new Character("bob");
// me->use(0, *bob);
// me->use(1, *bob);

// delete bob;
// delete me;
// delete src;

/********************************************/

}
