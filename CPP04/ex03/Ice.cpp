/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frite <frite@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 18:27:27 by yabejani          #+#    #+#             */
/*   Updated: 2024/10/24 14:21:59 by frite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice"){
}

Ice::Ice(Ice const &other) : AMateria(other){
}

Ice::~Ice(){
}

Ice &Ice::operator=(Ice const &other){
    if (this != &other) {
        this->_type = other._type;
    }
    return *this;
}

AMateria *Ice::clone() const{
    return new Ice(*this);
}

void Ice::use(ICharacter &target){
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
