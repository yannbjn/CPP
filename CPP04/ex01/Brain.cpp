/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabejani <yabejani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 16:23:28 by frite             #+#    #+#             */
/*   Updated: 2024/11/05 16:24:08 by yabejani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(){
    std::cout << "Brain: Default constructor called." << std::endl;
    for (int i = 0; i < 100; i++){
        _idea[i] = "default idea.";
    }
}

Brain::Brain(const Brain& other){
    std::cout << "Brain: Copy constructor called." << std::endl;
    for (int i = 0; i < 100; i++) {
        _idea[i] = other._idea[i];
    }
}

Brain& Brain::operator=(const Brain& other){
    if (this != &other) {
        for (int i = 0; i < 100; i++) {
            _idea[i] = other._idea[i];
        }
    }
    return *this;
}

Brain::~Brain(){
    std::cout << "Brain: Destructor called" << std::endl;
}

void Brain::setIdea(int index, const std::string  &idea){
    if (index >= 0 && index < 100)  
        this->_idea[index] = idea;
    else
        std::cout << "Idea must be in range of [0 - 99] included!" << std::endl;
}

std::string Brain::getIdea(int index){
    if (index >= 0 && index < 100)  
        return this->_idea[index];
    else
        return "Idea must be in range of [0 - 99] included!";
}
