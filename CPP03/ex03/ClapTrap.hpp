/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frite <frite@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 15:03:06 by yabejani          #+#    #+#             */
/*   Updated: 2024/09/24 14:29:46 by frite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

const std::string RESET = "\033[0m";
const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string YELLOW = "\033[33m";
const std::string BLUE = "\033[34m";
const std::string MAGENTA = "\033[35m";
const std::string CYAN = "\033[36m";
const std::string WHITE = "\033[37m";
const std::string BOLD = "\033[1m";
const std::string UNDERLINE = "\033[4m";
const std::string INVERSE = "\033[7m";

class ClapTrap
{
	protected:
		std::string _name;
		int	_HitPoints;
		int	_EnergyPoints;
		int	_AttackDamage;

	public:
		ClapTrap(); //canonical
		ClapTrap(ClapTrap const &src); //canonical
		ClapTrap(std::string _name);
		~ClapTrap();
		ClapTrap	&operator=(ClapTrap const &rhs); //canonical
		void	getInfo();
		void	setAD(int AttackDamage);
		int		getHP(void);
		int		getEP(void);

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};
