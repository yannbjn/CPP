/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabejani <yabejani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:57:48 by frite             #+#    #+#             */
/*   Updated: 2024/09/13 19:12:59 by yabejani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{
    std::cout << "Zombie nb " << Zombie::num << " has been created" << std::endl;
    Zombie::num += 1;
}

Zombie::~Zombie()
{
    std::cout << "Zombie named " << this->_name << " (nb "<< Zombie::num << ")" << " has been destroyed" << std::endl;
    Zombie::num -= 1;
}

void    Zombie::announce(void)
{
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void    Zombie::setName(std::string name)
{
    this->_name = name;
}

int Zombie::num = 1;
