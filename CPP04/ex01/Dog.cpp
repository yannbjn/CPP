/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabejani <yabejani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 16:51:16 by frite             #+#    #+#             */
/*   Updated: 2024/10/07 16:45:06 by yabejani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"

Dog::Dog() : Animal(){
    _type = "Dog";
    _Brain = new Brain();
    std::cout << "Dog: Default constructor called." << std::endl;
}

Dog::Dog(Dog const &src) : Animal(){
    std::cout << "Dog: Copy constructor called." << std::endl;
    *this = src;
}

Dog::~Dog(){
    delete _Brain;
    std::cout << "Dog: Destructor called." << std::endl;
}

Dog &Dog::operator=(Dog const &rhs){
	std::cout << "Animal Assignation operator called" << std::endl;
	if (this == &rhs)
		return *this;

	this->_type = rhs._type;
    this->_Brain = rhs._Brain;
	return *this;
}

void    Dog::makeSound() const{
    std::cout << "WOOOOOF I'm a dog." << std::endl;
}
