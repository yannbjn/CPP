/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabejani <yabejani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 20:21:05 by yabejani          #+#    #+#             */
/*   Updated: 2024/09/13 20:44:25 by yabejani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>


int	main(int argc, char **argv)
{
	if (argc != 2) 
	{
		std::cout << "Error." << std::endl;
		std::cout << "Usage: ./harl [LEVEL]" << std::endl;
		std::cout  << "LEVEL = [DEBUG || INFO || WARNING || ERROR]" << std::endl;
		return (1);
	}
	Harl	harl;
	harl.complain(argv[1]);
	return (0);
}
