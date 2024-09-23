/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabejani <yabejani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 18:27:31 by yabejani          #+#    #+#             */
/*   Updated: 2024/09/23 18:55:44 by yabejani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		std::string _name;

	public:
		DiamondTrap(); //canonical
		DiamondTrap(DiamondTrap const &src); //canonical
		DiamondTrap(std::string _name);
		~DiamondTrap();
		DiamondTrap	&operator=(DiamondTrap const &rhs); //canonical

		using ScavTrap::attack;
		void	whoAmI();
};
