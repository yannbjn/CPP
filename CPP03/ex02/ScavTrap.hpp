/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabejani <yabejani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:51:43 by yabejani          #+#    #+#             */
/*   Updated: 2024/09/23 17:45:15 by yabejani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap(); //canonical
		ScavTrap(std::string name);
		ScavTrap(ScavTrap const &src); // copy constuctor (canonical)
		~ScavTrap();
		ScavTrap	&operator=(ScavTrap const &rhs); // = op overload (canonical)

		int		getAP();
		void	attack(const std::string &target);
		void	guardGate();
};
