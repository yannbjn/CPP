/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabejani <yabejani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 15:03:06 by yabejani          #+#    #+#             */
/*   Updated: 2024/09/20 16:46:19 by yabejani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

class ClapTrap
{
	private:
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

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};
