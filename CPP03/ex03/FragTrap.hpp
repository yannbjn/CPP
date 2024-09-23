/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabejani <yabejani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 18:08:08 by yabejani          #+#    #+#             */
/*   Updated: 2024/09/23 18:43:58 by yabejani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	public:
		FragTrap(); //canonical
		FragTrap(std::string name);
		FragTrap(FragTrap const &src); // copy constuctor (canonical)
		~FragTrap();
		FragTrap	&operator=(FragTrap const &rhs); // = op overload (canonical)

		int		getAP();
		void	attack(const std::string &target);
		void	highFiveGuys(void);
};
