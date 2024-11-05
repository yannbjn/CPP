/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabejani <yabejani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 15:50:15 by frite             #+#    #+#             */
/*   Updated: 2024/10/25 16:04:11 by yabejani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : _name("DEFAULT NAME"){
    for (int i = 0; i < 4; i++){
        _inventory[i] = 0;
        _stockunequiped[i] = 0;
    }
}

Character::Character(std::string const &name) : _name(name){
    for (int i = 0; i < 4; i++){
        _inventory[i] = 0;
        _stockunequiped[i] = 0;
    }
}

Character::Character(Character const &other) : _name(other._name){
    for (int i = 0; i < 4; i++) {
        if (other._inventory[i]) {
            _inventory[i] = other._inventory[i]->clone();
        } else {
            _inventory[i] = NULL;
        }
        if (other._stockunequiped[i]) {
            _stockunequiped[i] = other._stockunequiped[i]->clone();
        } else {
            _stockunequiped[i] = NULL;
        }
    }
}

Character &Character::operator=(Character const &other){
    if (this != &other) {
        this->_name = other._name;
        for (int i = 0; i < 4; i++) {
            if (this->_inventory[i])
                delete this->_inventory[i];
            if (this->_stockunequiped[i])
                delete this->_stockunequiped[i];
            if (other._inventory[i])
                this->_inventory[i] = other._inventory[i]->clone();
            else
                this->_inventory[i] = 0;
            if (other._stockunequiped[i])
                this->_stockunequiped[i] = other._stockunequiped[i]->clone();
            else
                this->_stockunequiped[i] = 0;
        }
    }
    return *this;
}

Character::~Character(){
    for (int i = 0; i < 4; i++){
        if (this->_inventory[i])
            delete this->_inventory[i];
    }
    del_unequiped();
}

std::string const &Character::getName() const{
    return this->_name;
}

void Character::equip(AMateria *m){
    if (m == NULL)
        return ;
    if (checkfull(this->_inventory)){
        //std::cout << "Full inventory" << std::endl;
        return ;
    }
    for (int i = 0; i < 4; i++){
        if (this->_inventory[i] == 0){
            this->_inventory[i] = m->clone();
            std::cout << "Materia " << m->getType() << " equiped at index: " << i << std::endl;
            return;
        }
    }
}

void Character::unequip(int idx){
    if (checkempty(this->_inventory)){
        //std::cout << "EMPTY INVENTORY" << std::endl;
        return ;
    }
    if (idx < 0 || idx > 3){
        //std::cout << "BAD INDEX" << std::endl;
        return ;
    }
    if (_inventory[idx] == NULL){
        //std::cout << "Materia doesn't exist" << std::endl;
        return ;
    }
    for (int i = 0; i < 4; i++){
        if (_stockunequiped[i] == NULL){
            std::cout << "* [" << this->_name << "] has unequiped [" << this->_inventory[idx]->getType() << "] Materia. *" << std::endl;
            _stockunequiped[i] = _inventory[idx];
            this->_inventory[idx] = 0;
            return ;
        }
    }
    del_unequiped();
    unequip(idx);
}

void Character::use(int idx, ICharacter &target){
    if (checkempty(this->_inventory)){
        //std::cout << "No learned materia" << std::endl;
        return ;
    }
    if (idx < 0 || idx > 3){
        //std::cout << "Bad index" << std::endl;
        return ;
    }
    if (_inventory[idx] == NULL){
        //std::cout << "No Materia at this index" << std::endl;
        return ;
    }
    if (this->_inventory[idx]){
        this->_inventory[idx]->use(target);
    }
}

bool    Character::checkempty(AMateria **_inventory){
    for (int i = 0; i < 4; i++){
        if (_inventory[i])
            return false;
    }
    return true;
}

bool    Character::checkfull(AMateria **_inventory){
    for (int i = 0; i < 4; i++){
        if (_inventory[i] == NULL)
            return false;
    }
    return true;
}

void    Character::del_unequiped(){
    for (int i = 0; i < 4; i++){
        if (_stockunequiped[i]){
            delete _stockunequiped[i];
            _stockunequiped[i] = 0;
        }
    }
}

void    Character::displayinvetory() const{
    std::cout << std::setw(40) << "INVENTORY" << std::endl;
    std::cout << "-------------------------------------------------" << std::endl;
    for(int i = 0; i < 4; i++)
    {
        if(this->_inventory[i] != NULL)
            std::cout << i << ". " << this->_inventory[i]->getType() << std::endl;
        else
            std::cout << i << ". empty" << std::endl;
    }
    std::cout << "-------------------------------------------------" << std::endl;
}
