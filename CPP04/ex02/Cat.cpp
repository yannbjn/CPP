/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabejani <yabejani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 16:51:19 by frite             #+#    #+#             */
/*   Updated: 2024/11/05 16:23:58 by yabejani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat() : _brain(new Brain()){
    std::cout << "Cat: Default constructor called." << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other), _brain(new Brain(*other._brain)){
    std::cout << "Cat: Copy constructor called." << std::endl;
}

Cat& Cat::operator=(const Cat& other){
    if (this != &other) {
        Animal::operator=(other);
        delete _brain;
        _brain = new Brain(*other._brain);
    }
    return *this;
}

Cat::~Cat(){
    delete _brain;
    std::cout << "Cat: Destructor called." << std::endl;
}

void Cat::makeSound()const{
    std::cout << "MEOOOOOOW I'm a cat." << std::endl;
}

void Cat::setIdea(int index,const std::string  &idea){
	this->_brain->setIdea(index, idea);
}

std::string Cat::getIdea(int index)const{
	return this->_brain->getIdea(index);
}

