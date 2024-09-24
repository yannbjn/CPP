/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frite <frite@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:51:53 by yabejani          #+#    #+#             */
/*   Updated: 2024/09/24 14:55:26 by frite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(){
	std::cout << "ScavTrap: Default constructor called." << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &src) : ClapTrap(src){
	std::cout << "ScavTrap: Copy constructor called." << std::endl;
	*this = src;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name){
	//this->_name = name;
	this->_HitPoints = 100;
	this->_EnergyPoints = 50;
	this->_AttackDamage = 20;
	std::cout << "ScavTrap: Constructor of " << UNDERLINE << GREEN << this->_name << RESET << " called." << std::endl;
	ScavTrap::getInfo();
}

////////////DESTRUCTOR/////////////

ScavTrap::~ScavTrap(){
	std::cout << "ScavTrap: Destructor of " << UNDERLINE << GREEN << this->_name << RESET << " called." << std::endl;
}

////////////OP_OVERLOAD////////////

ScavTrap	&ScavTrap::operator=(ScavTrap const &rhs) {
	this->_name = rhs._name;
	this->_HitPoints = rhs._HitPoints;
	this->_EnergyPoints = rhs._EnergyPoints;
	this->_AttackDamage = rhs._AttackDamage;
	return (*this);
}

////////////////////////////////////

int		ScavTrap::getAP(){
	return this->_AttackDamage;
}

void	ScavTrap::attack(const std::string &target){
	if (this->_EnergyPoints <= 0)
		std::cout << BOLD << MAGENTA << "ScavTrap " << this->_name << " can't attack without Energy Points." << RESET << std::endl;
	if (this->_HitPoints <= 0)
		std::cout << BOLD << MAGENTA << "ScavTrap " << this->_name << " can't attack without Hit Points." << RESET << std::endl;
	else if (this->_EnergyPoints > 0 && this->_HitPoints > 0){
		this->_EnergyPoints--;
		std::cout << BOLD << RED << "ScavTrap " << UNDERLINE << GREEN << this->_name << RESET << BOLD << RED << " attacks " << target << ", causing " << this->_AttackDamage << " points of damage!" << RESET << std::endl;
	}
	ScavTrap::getInfo();
}

void	ScavTrap::guardGate() {
	std::cout << BOLD << CYAN << "ScavTrap: " << RESET << UNDERLINE << GREEN << this->_name << RESET << BOLD << CYAN << " is now in Gate Keeper mode." << RESET << std::endl;
}
