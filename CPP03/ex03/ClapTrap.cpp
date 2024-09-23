/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabejani <yabejani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 15:03:36 by yabejani          #+#    #+#             */
/*   Updated: 2024/09/23 19:54:22 by yabejani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

////////////CONSTRUCTORS/////////////

ClapTrap::ClapTrap(){
	std::cout << "ClapTrap: Default constructor called." << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &src){
	std::cout << "ClapTrap: Copy constructor called." << std::endl;
	*this = src;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _HitPoints(10), _EnergyPoints(10), _AttackDamage(0){
	std::cout << "ClapTrap: Constructor of " << BOLD << GREEN << this->_name << RESET << " called." << std::endl;
	ClapTrap::getInfo();
}

////////////DESTRUCTOR/////////////

ClapTrap::~ClapTrap(){
	std::cout << "ClapTrap: Destructor of " << BOLD << GREEN << this->_name << RESET << " called." << std::endl;
}

////////////OP_OVERLOAD////////////

ClapTrap	&ClapTrap::operator=(ClapTrap const &rhs) {
	this->_name = rhs._name;
	this->_HitPoints = rhs._HitPoints;
	this->_EnergyPoints = rhs._EnergyPoints;
	this->_AttackDamage = rhs._AttackDamage;
	return (*this);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void	ClapTrap::setAD(int AD){
	this->_AttackDamage = AD;
	std::cout << BOLD << GREEN << this->_name << RESET << " Attack Damage has been set to " << BOLD << YELLOW << this->_AttackDamage << RESET << "." << std::endl;
}

void	ClapTrap::getInfo(){
	std::cout << BOLD << GREEN << this->_name << RESET << BOLD << YELLOW << " has:" << std::endl;
	std::cout << "   " << this->_HitPoints << " Hit points left." << std::endl;
	std::cout << "   " << this->_EnergyPoints << " Energy points left." << std::endl;
	std::cout << "   " << this->_AttackDamage << " Attack damage." << RESET << std::endl;
	std::cout << std::endl;
}

int	ClapTrap::getHP(){
	return this->_HitPoints;
}

int	ClapTrap::getEP(){
	return this->_EnergyPoints;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void	ClapTrap::attack(const std::string &target){
	if (this->_EnergyPoints <= 0)
		std::cout << BOLD << MAGENTA << "Claptrap " << this->_name << " can't attack without Energy Points." << RESET << std::endl;
	if (this->_HitPoints <= 0)
		std::cout << BOLD << MAGENTA << "Claptrap " << this->_name << " can't attack without Hit Points." << RESET << std::endl;
	else if (this->_EnergyPoints > 0 && this->_HitPoints > 0){
		this->_EnergyPoints--;
		std::cout << BOLD << RED << "ClapTrap " << BOLD << GREEN << this->_name << RESET << BOLD << RED << " attacks " << target << ", causing " << this->_AttackDamage << " points of damage!" << RESET << std::endl;
	}
	ClapTrap::getInfo();
}

void	ClapTrap::takeDamage(unsigned int amount){
	this->_HitPoints -= amount;
	std::cout << BOLD << GREEN << this->_name << RESET << BOLD << RED << " took " << amount << " damage after being attacked!" << RESET << std::endl;
	ClapTrap::getInfo();
}

void	ClapTrap::beRepaired(unsigned int amount){
	if (this->_EnergyPoints <= 0)
		std::cout << BOLD << GREEN << this->_name << RESET << BOLD << MAGENTA << " can't be repaired without Energy Points." << RESET << std::endl;
	if (this->_HitPoints <= 0)
		std::cout << BOLD << GREEN << this->_name << RESET << BOLD << MAGENTA << " can't be repaired without Hit Points." << RESET << std::endl;
	else if (this->_EnergyPoints > 0 && this->_HitPoints > 0){
		this->_EnergyPoints--;
		this->_HitPoints += amount;
		std::cout << BOLD << GREEN << this->_name << RESET << BOLD << BLUE << " got repaired for " << amount << " Hit Points." << RESET << std::endl;
	}
	ClapTrap::getInfo();
}

void ClapTrap::initializeAttributes(int hitPoints, int energyPoints, int attackDamage) {
    this->_HitPoints = hitPoints;
    this->_EnergyPoints = energyPoints;
    this->_AttackDamage = attackDamage;
}
