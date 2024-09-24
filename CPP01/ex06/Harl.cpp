/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabejani <yabejani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 20:24:16 by yabejani          #+#    #+#             */
/*   Updated: 2024/09/24 18:36:58 by yabejani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(){}

Harl::~Harl(){}

void	Harl::_debug()
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do !" << std::endl;
}

void	Harl::_info()
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger ! If you did, I wouldn't be asking for more !" << std::endl;
}

void	Harl::_warning()
{
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::_error()
{
	std::cout << "This is unacceptable ! I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level)
{
	void	(Harl::*ftptrtab[])() = {&Harl::_debug, &Harl::_info, &Harl::_warning,  &Harl::_error};
	std::string	levelComplain[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	int i = 0;
	for (; i < 4; i++)
	{
		if (levelComplain[i] == level)
			break;

	}
	switch(i)
	{
		case(0):
			(this->*ftptrtab[0])();
		case(1):
			(this->*ftptrtab[1])();
		case(2):
			(this->*ftptrtab[2])();
		case(3):
			(this->*ftptrtab[3])();
			break;
	default:
		std::cout << "No matching level detected." << std::endl;
		std::cout << "LEVEL = [DEBUG || INFO || WARNING || ERROR]" << std::endl;
		break;
	}
}
