/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frite <frite@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:28:42 by frite             #+#    #+#             */
/*   Updated: 2024/10/09 14:28:43 by frite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include "IMateriaSource.hpp"
#include "ICharacter.hpp"


int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	ICharacter* bob = new Character("bob");
	AMateria* tmp;
	AMateria* tmpb;
	tmp = src->createMateria("ice");
	tmpb = src->createMateria("ice");
	me->equip(tmp);
	bob->equip(tmpb);
	tmp = src->createMateria("cure");
	tmpb = src->createMateria("cure");
	me->equip(tmp);
	bob->equip(tmpb);
	tmp = src->createMateria("ice");
	tmpb = src->createMateria("ice");
	me->equip(tmp);
	bob->equip(tmpb);
	tmp = src->createMateria("cure");
	tmpb = src->createMateria("cure");
	me->equip(tmp);
	bob->equip(tmpb);
	tmp = src->createMateria("ice");
	tmpb = src->createMateria("ice");
	me->equip(tmp);
	bob->equip(tmpb);
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);
	me->use(4, *bob);
	bob->use(0, *me);
	bob->use(1, *me);
	bob->unequip(1);
	bob->use(1, *me);
	me->unequip(3);
	me->use(3, *bob);
	me->use(5, *bob);
	delete bob;
	delete me;
	delete src;
	delete tmp;
	delete tmpb;
	return 0;
}
