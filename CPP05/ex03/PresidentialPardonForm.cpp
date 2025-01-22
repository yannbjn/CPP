/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frite <frite@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 13:14:47 by frite             #+#    #+#             */
/*   Updated: 2025/01/16 15:31:29 by frite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(){
    //std::cout << "Presidential: Default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string name) : AForm::AForm("Presidential", 25, 5){
    this->_target = name;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) : AForm::AForm("Presidential", 25, 5){
    //std::cout << "Presidential: Copy constructor called" << std::endl;
    *this = src;
}

PresidentialPardonForm::~PresidentialPardonForm(){
    //std:;cout << "Presidential: Default destructor called" << std::endl;
}

PresidentialPardonForm   &PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs){
    if (this != &rhs)
        _target = rhs._target;
    return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const{
    if (!getIsAFormSigned()){
        throw AForm::GradeTooLowException();
    }
    if (this->getexecGrade() < executor.getGrade()){
        throw AForm::GradeTooHighException();
    }
    std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
