/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabejani <yabejani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 18:28:16 by yabejani          #+#    #+#             */
/*   Updated: 2024/09/23 19:56:31 by yabejani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(){
	std::cout << "DiamondTrap: Default constructor called." << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const &src){
	std::cout << "DiamondTrap: Copy constructor called." << std::endl;
	*this = src;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name) {
    this->_name = name;
    this->ClapTrap::_name = name + "_clap_name";
    
    // The initialization is done automatically based on ScavTrap and FragTrap constructors
	std::cout << "DiamondTrap: Constructor of " << BOLD << GREEN << this->_name << RESET << " called." << std::endl;    DiamondTrap::getInfo();
}


// DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"){
//     this->_name = name;  // DiamondTrap's own name (not the ClapTrap name)
//     this->ClapTrap::_name = name + "_clap_name";  // ClapTrap's name (with _clap_name suffix)

//     // Set attributes explicitly after all parent constructors have been called
//     this->_HitPoints = FragTrap::_HitPoints;  // 100 from FragTrap
//     this->_EnergyPoints = ScavTrap::_EnergyPoints;  // 50 from ScavTrap
//     this->_AttackDamage = FragTrap::_AttackDamage;  // 30 from FragTrap

//     // Output information about the created DiamondTrap
//     std::cout << "DiamondTrap: Constructor of " << BOLD << GREEN << this->_name << RESET << " called." << std::endl;
//     DiamondTrap::getInfo();
// }



// DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), ScavTrap(name), FragTrap(name){
// 	this->_name = name;
// 	this->ClapTrap::_name = name + "_clap_name";
// 	this->_HitPoints = FragTrap::_HitPoints;
// 	this->_EnergyPoints = ScavTrap::_EnergyPoints;
// 	//std::cout << "baSBAHbj = " << ScavTrap::_EnergyPoints << std::endl;
// 	this->_AttackDamage = FragTrap::_AttackDamage;
// 	std::cout << "DiamondTrap: Constructor of " << BOLD << GREEN << this->_name << RESET << " called." << std::endl;
// 	DiamondTrap::getInfo();
// }

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
