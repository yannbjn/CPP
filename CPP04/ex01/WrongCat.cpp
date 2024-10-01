/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frite <frite@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:44:54 by frite             #+#    #+#             */
/*   Updated: 2024/10/01 15:50:26 by frite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal(){
    _type = "WrongCat";
    std::cout << "WrongCat: Default constructor called." << std::endl;
}

WrongCat::WrongCat(WrongCat const &src) : WrongAnimal(){
    std::cout << "WrongCat: Copy constructor called." << std::endl;
    *this = src;
}

WrongCat::~WrongCat(){
    std::cout << "WrongCat: Destructor called." << std::endl;
}

WrongCat &WrongCat::operator=(WrongCat const &rhs){
	std::cout << "WrongCat Assignation operator called" << std::endl;
	if (this == &rhs)
		return *this;

	this->_type = rhs._type;
	return *this;
}

void    WrongCat::makeSound() const{
    std::cout << "Woof Woof I'm a WrongCat." << std::endl;
}
