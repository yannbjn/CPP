/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabejani <yabejani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 16:40:24 by frite             #+#    #+#             */
/*   Updated: 2024/10/25 16:38:21 by yabejani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(){
    std::cout << "Animal: Default constructor called." << std::endl;
}

Animal::Animal(Animal const &src){
    std::cout << "Animal: Copy constructor called." << std::endl;
    *this = src;
}

Animal::~Animal(){
    std::cout << "Animal: Destructor called." << std::endl;
}

Animal  &Animal::operator=(Animal const &rhs){
	std::cout << "Animal Assignation operator called" << std::endl;
	if (this == &rhs)
		return *this;

	this->_type = rhs._type;
	return *this;
}

std::string Animal::getType() const{
    return this->_type;
}

void    Animal::makeSound() const{
    std::cout << "No animal type, no sound." << std::endl;
}
