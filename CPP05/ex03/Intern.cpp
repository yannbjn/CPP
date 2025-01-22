/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabejani <yabejani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 18:48:33 by yabejani          #+#    #+#             */
/*   Updated: 2025/01/22 19:25:30 by yabejani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "colors.hpp"

Intern::Intern(){
    
}

Intern::Intern(Intern const &src){
    *this = src;
}

Intern::~Intern(){
    
}

Intern  &Intern::operator=(Intern const &rhs){
    (void)rhs;
    return *this;
}

AForm   *Intern::makeForm(std::string FormName, std::string target){
    std::string TypeofForm[3] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};
    AForm*   (*CreateForms[3])(std::string) = {
        [](std::string target) {return new PresidentialPardonForm(target);},
        [](std::string target) {return new RobotomyRequestForm(target);},
        [](std::string target) {return new ShrubberyCreationForm(target);}
    };
    
    for (int i = 0; i < 3; i++){
        if (FormName == TypeofForm[i]){
            std::cout << "Intern creates " << FormName << " form." << std::endl;
            return CreateForms[i](target);
        }
    }
    
    std::cout << BOLD << RED << "Intern Faild finding the requested form type: " << FormName << std::endl;
    return NULL;
}
