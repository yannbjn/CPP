/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frite <frite@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 18:11:46 by yabejani          #+#    #+#             */
/*   Updated: 2024/10/08 14:55:53 by frite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(){
	//std::cout << "AMateria: Defaukt constructor called." << std::endl;
}

AMateria::AMateria(std::string const &type) : _type(type){
	//std::cout << "AMateria: Constructor called." << std::endl;
}

AMateria::AMateria(AMateria const &src) : _type(src._type){
	//std::cout << "AMateria: Copy constructor called." << std::endl;
}

AMateria::~AMateria(){
	//std::cout << "AMateria: Destructor called." << std::endl;
}

AMateria &AMateria::operator=(AMateria const &rhs){
	//std::cout << "AMateria: Assignation operator called." << std::endl;
	if (this == &rhs)
		return *this;
	this->_type = rhs._type;
	return *this;
}

std::string const &AMateria::getType() const {
	return this->_type;
}

void AMateria::use(ICharacter &target) {
    std::cout << "* uses a Materia on " << target.getName() << " *" << std::endl;
}
