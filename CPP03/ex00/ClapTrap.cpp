/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabejani <yabejani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 15:03:36 by yabejani          #+#    #+#             */
/*   Updated: 2024/09/23 16:49:26 by yabejani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

////////////CONSTRUCTORS/////////////

ClapTrap::ClapTrap(){
	std::cout << "ClatTrap: Default constructor called." << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &src){
	std::cout << "ClatTrap: Copy constructor called." << std::endl;
	*this = src;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _HitPoints(10), _EnergyPoints(10), _AttackDamage(0){
	std::cout << "ClapTrap: Constructor of " << UNDERLINE << GREEN << this->_name << RESET << " called." << std::endl;
	ClapTrap::GetInfo();
}

////////////DESTRUCTOR/////////////

ClapTrap::~ClapTrap(){
	std::cout << "ClapTrap: Destructor of " << UNDERLINE << GREEN << this->_name << RESET << " called." << std::endl;
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

void	ClapTrap::SetAD(int AD){
	this->_AttackDamage = AD;
	std::cout << "ClapTrap " << UNDERLINE << GREEN << this->_name << RESET << " Attack Damage has been set to " << BOLD << YELLOW << this->_AttackDamage << RESET << "." << std::endl;
}

void	ClapTrap::GetInfo(){
	std::cout << BOLD << YELLOW << "ClapTrap " << UNDERLINE << GREEN << this->_name << RESET << BOLD << YELLOW << " has:" << std::endl;
	std::cout << "   " << this->_HitPoints << " Hit points left." << std::endl;
	std::cout << "   " << this->_EnergyPoints << " Energy points left." << std::endl;
	std::cout << "   " << this->_AttackDamage << " Attack damage." << RESET << std::endl;
	std::cout << std::endl;
}

int	ClapTrap::GetHP(){
	return this->_HitPoints;
}

int	ClapTrap::GetEP(){
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
		std::cout << BOLD << RED << "ClapTrap " << UNDERLINE << GREEN << this->_name << RESET << BOLD << RED << " attacks " << target << ", causing " << this->_AttackDamage << " points of damage!" << RESET << std::endl;
	}
	ClapTrap::GetInfo();
}

void	ClapTrap::takeDamage(unsigned int amount){
	this->_HitPoints -= amount;
	std::cout << BOLD << RED << "Claptrap " << UNDERLINE << GREEN << this->_name << RESET << BOLD << RED << " took " << amount << " damage after being attacked!" << RESET << std::endl;
	ClapTrap::GetInfo();
}

void	ClapTrap::beRepaired(unsigned int amount){
	if (this->_EnergyPoints <= 0)
		std::cout << BOLD << MAGENTA  << "Claptrap " << this->_name << " can't be repaired without Energy Points." << RESET << std::endl;
	if (this->_HitPoints <= 0)
		std::cout << BOLD << MAGENTA << "Claptrap " << this->_name << " can't be repaired without Hit Points." << RESET << std::endl;
	else if (this->_EnergyPoints > 0 && this->_HitPoints > 0){
		this->_EnergyPoints--;
		this->_HitPoints += amount;
		std::cout << BOLD << GREEN <<  "ClapTrap " << this->_name << " got repaired for " << amount << " Hit Points." << RESET << std::endl;
	}
	ClapTrap::GetInfo();
}
