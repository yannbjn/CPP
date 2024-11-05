/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabejani <yabejani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 16:51:16 by frite             #+#    #+#             */
/*   Updated: 2024/11/05 15:25:37 by yabejani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"

Dog::Dog() : Animal(){
    _type = "Dog";
    std::cout << "Dog: Default constructor called." << std::endl;
}

Dog::Dog(Dog const &src) : Animal(){
    std::cout << "Dog: Copy constructor called." << std::endl;
    *this = src;
}

Dog::~Dog(){
    std::cout << "Dog: Destructor called." << std::endl;
}

Dog &Dog::operator=(Dog const &rhs){
	std::cout << "Dog Assignation operator called" << std::endl;
	if (this == &rhs)
		return *this;

	this->_type = rhs._type;
	return *this;
}

void    Dog::makeSound() const{
    std::cout << "WOOOOOF I'm a dog." << std::endl;
}
