/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabejani <yabejani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 18:48:33 by yabejani          #+#    #+#             */
/*   Updated: 2025/02/04 16:04:40 by yabejani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(){
    
}

Intern::Intern(const Intern &other){
    (void)other;
}

Intern &Intern::operator=(const Intern &other){
    (void)other;
    return *this;
}

Intern::~Intern(){
}

AForm* Intern::makeForm(std::string formName, std::string target){
    AForm   *FormSave = NULL;
    std::string formTypes[] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
    AForm   *formCreator[] = {new ShrubberyCreationForm(target), new RobotomyRequestForm(target), new PresidentialPardonForm(target)};

    for (int i = 0; i < 3; i++){
        if (formName == formTypes[i]){
            std::cout << "Intern creates " << formName << " form." << std::endl;
            FormSave =  formCreator[i];
        }
        else
            delete formCreator[i];
    }
    if (!FormSave){
        std::cout << "Intern couldn't find the rquested form type: " << formName << std::endl;
    }
    return FormSave;
}
