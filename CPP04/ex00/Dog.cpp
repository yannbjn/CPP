/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frite <frite@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 16:51:16 by frite             #+#    #+#             */
/*   Updated: 2024/09/26 17:09:29 by frite            ###   ########.fr       */
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
	std::cout << "Animal Assignation operator called" << std::endl;
	if (this == &rhs)
		return *this;

	this->_type = rhs._type;
	return *this;
}

void    Dog::makeSound() const{
    std::cout << "MEOOOOOOW I'm a dog." << std::endl;
}
