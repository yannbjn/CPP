/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frite <frite@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 15:50:15 by frite             #+#    #+#             */
/*   Updated: 2024/10/08 16:21:55 by frite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(std::string const &name) : _name(name){
    for (int i = 0; i < 4; i++)
        this->_inventory[i] = 0;
}

Character::Character(Character const &other) : _name(other._name){
    *this = other;
}

Character &Character::operator=(Character const &other){
    if (this != &other) {
        this->_name = other._name;
        for (int i = 0; i < 4; i++) {
            if (this->_inventory[i])
                delete this->_inventory[i];
            if (other._inventory[i])
                this->_inventory[i] = other._inventory[i]->clone();
            else
                this->_inventory[i] = 0;
        }
    }
    return *this;
}

Character::~Character(){
    for (int i = 0; i < 4; i++){
        if (this->_inventory[i])
            delete this->_inventory[i];
    }
}

std::string const &Character::getName() const{
    return this->_name;
}

void Character::equip(AMateria *m){
    for (int i = 0; i < 4; i++) {
        if (this->_inventory[i] == 0) {
            this->_inventory[i] = m;
            return;
        }
    }
}

void Character::unequip(int idx){
    if (idx >= 0 && idx < 4) {
        std::cout << "* [" << this->_name << "] has unequiped [" << this->_inventory[idx]->getType() << "] Materia. *" << std::endl;
        delete this->_inventory[idx];
        this->_inventory[idx] = 0;
    }
}

void Character::use(int idx, ICharacter &target){
    if (idx >= 0 && idx < 4 && this->_inventory[idx]){
        this->_inventory[idx]->use(target);
    }
}
