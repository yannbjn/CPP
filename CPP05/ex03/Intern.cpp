/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frite <frite@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 18:48:33 by yabejani          #+#    #+#             */
/*   Updated: 2025/03/25 18:13:18 by frite            ###   ########.fr       */
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

// AForm* Intern::makeForm(std::string formName, std::string target){
//     AForm   *FormSave = NULL;
//     std::string formTypes[] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
//     AForm   *formCreator[] = {new ShrubberyCreationForm(target), new RobotomyRequestForm(target), new PresidentialPardonForm(target)};

//     for (int i = 0; i < 3; i++){
//         try (formExists(formName, ))
//         // if (formName == formTypes[i]){
//         //     std::cout << BOLD << BLUE << "Intern creates " << formName << " form." << RESET << std::endl;
//         //     FormSave =  formCreator[i];
//         // }
//         // else
//         //     delete formCreator[i];
//     }
//     if (!FormSave){
//         std::cout << BOLD << RED << "Intern couldn't find the rquested form type: " << formName << RESET << std::endl;
//     }
//     return FormSave;
// }

const char *Intern::NoExistFormException::what() const throw(){
    return ("This type of form doesn't exist");
}

void     formExists(std::string formName, std::string formType)
{
    if (formName != formType)
        throw Intern::NoExistFormException();
}

AForm* Intern::makeForm(std::string formName, std::string target){
    AForm   *FormSave = NULL;
    std::string formTypes[] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
    AForm   *formCreator[] = {new ShrubberyCreationForm(target), new RobotomyRequestForm(target), new PresidentialPardonForm(target)};

    for (int i = 0; i < 3; i++){
        try {
            formExists(formName, formTypes[i]);
            std::cout << BOLD << BLUE << "Intern creates " << formName << " form." << RESET << std::endl;
            FormSave =  formCreator[i];
        }
        catch (std::exception &e){
            delete formCreator[i];
            std::cout << "Intern couldn't find the rquested form type: " << e.what() << std::endl;
        }
    }
    return FormSave;
}
