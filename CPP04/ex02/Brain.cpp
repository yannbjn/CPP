/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frite <frite@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 16:23:28 by frite             #+#    #+#             */
/*   Updated: 2024/10/01 17:44:18 by frite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(){
    std::cout << "Brain: Constructor called." << std::endl;
}

Brain::Brain(Brain const &src){
    std::cout << "Brain: Copy constructor called." << std::endl;
    *this = src;
}

Brain::~Brain(){
    std::cout << "Brain: Destructor called." << std::endl;
}

Brain &Brain::operator=(const Brain &rhs){
    std::cout << "Brain Assignation operator called" << std::endl;
    if (this == &rhs)
        return *this;
    for (int i = 0; i < 100; i++){
        if (rhs._ideas[i].length() > 0)
            this->_ideas[i].assign(rhs._ideas[i]);
    }
    return *this;
}
