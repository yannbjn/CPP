/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabejani <yabejani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 15:03:36 by yabejani          #+#    #+#             */
/*   Updated: 2024/09/20 16:51:10 by yabejani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

////////////CONSTRUCTORS/////////////

ClapTrap::ClapTrap(){
	std::cout << "ClatTrap: Default constructor called." << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &src){
	std::cout << "ClatTrap: Copy constructor called." << std::endl;
	*this = src;
}
