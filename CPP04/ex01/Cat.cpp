/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frite <frite@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 16:51:19 by frite             #+#    #+#             */
/*   Updated: 2024/10/01 17:19:00 by frite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat() : Animal(){
    _type = "Cat";
    std::cout << "Cat: Default constructor called." << std::endl;
}

Cat::Cat(Cat const &src) : Animal(){
    std::cout << "Cat: Copy constructor called." << std::endl;
    *this = src;
}

Cat::~Cat(){
    std::cout << "Cat: Destructor called." << std::endl;
}

Cat &Cat::operator=(Cat const &rhs){
	std::cout << "Cat Assignation operator called" << std::endl;
	if (this == &rhs)
		return *this;

	this->_type = rhs._type;
	return *this;
}

void    Cat::makeSound() const{
    std::cout << "MEOOOOOOW I'm a cat." << std::endl;
}
