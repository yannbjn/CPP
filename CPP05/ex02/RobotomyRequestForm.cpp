/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frite <frite@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 13:16:40 by frite             #+#    #+#             */
/*   Updated: 2025/03/25 16:08:30 by frite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(){
    //std::cout << "Robotomy: Default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string name) : AForm::AForm("Robotomy", 72, 45){
    this->_target = name;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) : AForm::AForm("Robotomy", 72, 45){
    //std::cout << "Robotomy: Copy constructor called" << std::endl;
    *this = src;
}

RobotomyRequestForm::~RobotomyRequestForm(){
    //std::cout << "Robotomy: Default destructor called" << std::endl;
}


RobotomyRequestForm   &RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs){
    if (this != &rhs)
        _target = rhs._target;
    return *this;
}

void    RobotomyRequestForm::execute(Bureaucrat const &executor) const{
    std::srand(std::time(0)); //setting rand generator on actual time
    // if (!getIsAFormSigned()){
    //     throw AForm::GradeTooLowException();
    // }
    try {
        getIsAFormSigned();
    }
    catch (std::exception &e) {
        std::cerr << "DEBUG" << e.what() << std::endl;
        // throw AForm::GradeTooLowException();
    }
    if (this->getexecGrade() < executor.getGrade()){
        throw AForm::GradeTooLowException();
    }
    if (std::rand() % 2 == 0){
        std::cout << GREEN << _target << " robotomized succesfully!" << RESET << std::endl; 
    }
    else {
        std::cout << RED << "Failed to robotomize " << _target << " !" << RESET << std::endl;
    }
}