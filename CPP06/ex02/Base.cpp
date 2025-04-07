/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabejani <yabejani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 18:17:54 by yabejani          #+#    #+#             */
/*   Updated: 2025/04/07 19:02:44 by yabejani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base::~Base()
{
	
}

Base *generate(void)
{
	int random = std::rand() % 3;
	if (random == 1)
		return std::cout << "Generating object type A" << std::endl, new A();
	else if (random == 2)
		return std::cout << "Generating object type B" << std::endl, new B();
	else
		return std::cout << "Generating object type C" << std::endl, new C();
}

void identify(Base *p)
{
	std::cout << "POINTER IDENTIFY" << std::endl;
	if (dynamic_cast<A*>(p))
		std::cout << "Object of type A identified" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Object of type B identified" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Object of type C identified" << std::endl;
	else
		std::cout << "Unknown object type" << std::endl;
}

void identify(Base &p)
{
	std::cout << "REFERENCE IDENTIFY" << std::endl;
	try{
		A base = dynamic_cast<A &>(p);
		std::cout << "object of type A identified" << std::endl;
		return ;
	}
	catch(const std::exception& e) {}
	try{
		B base = dynamic_cast<B &>(p);
		std::cout << "object of type B identified" << std::endl;
		return ;
	}
	catch(const std::exception& e) {}
	try{
		C base = dynamic_cast<C &>(p);
		std::cout << "object of type C identified" << std::endl;
		return ;
	}
	catch(const std::exception& e) {}
	std::cout << "Unknown object type" << std::endl;
	
}