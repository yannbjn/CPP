/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabejani <yabejani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 16:51:16 by frite             #+#    #+#             */
/*   Updated: 2024/11/05 16:23:40 by yabejani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"

Dog::Dog() : _brain(new Brain()){
    std::cout << "Dog: Default constructor called." << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other), _brain(new Brain(*other._brain)){
    std::cout << "Dog: Copy constructor called." << std::endl;
}

Dog& Dog::operator=(const Dog& other){
    if (this != &other) {
        Animal::operator=(other);
        delete _brain;
        _brain = new Brain(*other._brain);
    }
    return *this;
}

Dog::~Dog(){
    delete _brain;
    std::cout << "Dog: Destructor called." << std::endl;
}

void Dog::makeSound() const{
    std::cout << "WOOOOOF! I'm a dog" << std::endl;
}

void Dog::setIdea(int index,const std::string  &idea){
	this->_brain->setIdea(index, idea);
}

std::string Dog::getIdea(int index)const{
	return this->_brain->getIdea(index);
}
