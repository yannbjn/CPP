/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frite <frite@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:49:12 by frite             #+#    #+#             */
/*   Updated: 2024/10/24 14:22:55 by frite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure"){
}

Cure::Cure(Cure const &other) : AMateria(other){
}

Cure::~Cure(){
}

Cure &Cure::operator=(Cure const &other){
    if (this != &other) {
        this->_type = other._type;
    }
    return *this;
}

AMateria *Cure::clone() const{
    return new Cure(*this);
}

void Cure::use(ICharacter &target){
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
