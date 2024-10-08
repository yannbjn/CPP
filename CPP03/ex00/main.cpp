/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabejani <yabejani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 15:03:30 by yabejani          #+#    #+#             */
/*   Updated: 2024/09/23 17:46:39 by yabejani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap ClapA("ClapA");
	ClapTrap ClapB("ClapB");
	ClapTrap ClapC("ClapC");
	ClapTrap ClapD("ClapD");

	ClapA.setAD(10);
	ClapA.attack("ClapC");
	if (ClapA.getHP() > 0 && ClapA.getEP() > 0)
		ClapC.takeDamage(10);
	ClapC.beRepaired(10);
	ClapD.setAD(2);
	for (int i = 0; i < 10; i++){
		ClapD.attack("ClapB");
		if (ClapD.getHP() > 0 && ClapD.getEP() > 0)
			ClapB.takeDamage(2);
		ClapB.beRepaired(1);
	}
}
