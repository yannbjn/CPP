/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabejani <yabejani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 18:08:17 by yabejani          #+#    #+#             */
/*   Updated: 2024/09/23 19:55:54 by yabejani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(){
	// this->_HitPoints = 100;
	// this->_EnergyPoints = 100;
	// this->_AttackDamage = 30;
	std::cout << "FragTrap: Default constructor called." << std::endl;
}

FragTrap::FragTrap(FragTrap const &src){
	std::cout << "FragTrap: Copy constructor called." << std::endl;
	*this = src;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    this->initializeAttributes(100, 100, 30);  // FragTrap-specific values
    std::cout << "FragTrap: Constructor of " << BOLD << GREEN << this->_name << RESET << " called." << std::endl;
}


// FragTrap::FragTrap(std::string name) : ClapTrap(name){
// 	//this->_name = name;
// 	this->_HitPoints = 100;
// 	this->_EnergyPoints = 100;
// 	this->_AttackDamage = 30;
// 	std::cout << "FragTrap: Constructor of " << BOLD << GREEN << this->_name << RESET << " called." << std::endl;
// 	FragTrap::getInfo();
// }

////////////DESTRUCTOR/////////////

FragTrap::~FragTrap(){
	std::cout << "FragTrap: Destructor of " << BOLD << GREEN << this->_name << RESET << " called." << std::endl;
}

////////////OP_OVERLOAD////////////

FragTrap	&FragTrap::operator=(FragTrap const &rhs) {
	this->_name = rhs._name;
	this->_HitPoints = rhs._HitPoints;
	this->_EnergyPoints = rhs._EnergyPoints;
	this->_AttackDamage = rhs._AttackDamage;
	return (*this);
}

////////////////////////////////////

int		FragTrap::getAP(){
	return this->_AttackDamage;
}

void	FragTrap::attack(const std::string &target){
	if (this->_EnergyPoints <= 0)
		std::cout << BOLD << MAGENTA << "FragTrap " << this->_name << " can't attack without Energy Points." << RESET << std::endl;
	if (this->_HitPoints <= 0)
		std::cout << BOLD << MAGENTA << "FragTrap " << this->_name << " can't attack without Hit Points." << RESET << std::endl;
	else if (this->_EnergyPoints > 0 && this->_HitPoints > 0){
		this->_EnergyPoints--;
		std::cout << BOLD << RED << "FragTrap " << BOLD << GREEN << this->_name << RESET << BOLD << RED << " attacks " << target << ", causing " << this->_AttackDamage << " points of damage!" << RESET << std::endl;
	}
	FragTrap::getInfo();
}

void	FragTrap::highFiveGuys(void){
	std::cout << BOLD << BLUE << "Hi I'm " << RESET << BOLD << GREEN << this->_name << RESET << BOLD << BLUE << " give me a high five! :)" << RESET << std::endl;
}
