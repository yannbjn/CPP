/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabejani <yabejani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 18:28:16 by yabejani          #+#    #+#             */
/*   Updated: 2024/09/26 20:03:29 by yabejani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(){
	std::cout << "DiamondTrap: Default constructor called." << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const &src) : ClapTrap(src), ScavTrap(src), FragTrap(src) {
	std::cout << "DiamondTrap: Copy constructor called." << std::endl;
	*this = src;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), ScavTrap(name), FragTrap(name){
	this->_name = name;
	this->ClapTrap::_name = name + "_clap_name";
	this->_HitPoints = FragTrap::_HitPoints;
	//this->_EnergyPoints = 50; //tmp solution pcq jpp
	this->_EnergyPoints = ScavTrap::_EnergyPoints;
	//std::cout << "baSBAHbj = " << ScavTrap::_EnergyPoints << std::endl;
	this->_AttackDamage = FragTrap::_AttackDamage;
	std::cout << "DiamondTrap: Constructor of " << BOLD << GREEN << this->_name << RESET << " called." << std::endl;
	DiamondTrap::getInfo();
}

////////////DESTRUCTOR/////////////

DiamondTrap::~DiamondTrap(){
	std::cout << "DiamondTrap: Destructor of " << BOLD << GREEN << this->_name << RESET << " called." << std::endl;
}

////////////OP_OVERLOAD////////////

DiamondTrap	&DiamondTrap::operator=(DiamondTrap const &rhs) {
	this->_name = rhs._name;
	this->_HitPoints = rhs._HitPoints;
	this->_EnergyPoints = rhs._EnergyPoints;
	this->_AttackDamage = rhs._AttackDamage;
	return (*this);
}

//////////////////////////////////

void	DiamondTrap::whoAmI(){
	std::cout << BOLD << CYAN << "My Diamond name is " << RESET << BOLD << GREEN <<  this->_name << RESET << std::endl;
	std::cout << BOLD << CYAN << "My ClapTrap name is " << RESET << BOLD << GREEN << this->ClapTrap::_name << RESET << std::endl;
}
