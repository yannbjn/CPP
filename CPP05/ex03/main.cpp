/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabejani <yabejani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:36:01 by yabejani          #+#    #+#             */
/*   Updated: 2025/03/17 16:39:57 by yabejani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

int	main(void)
{
	Intern	intern_jack;
	AForm	*form;
	std::string formArr[] = {"RandomForm", "ShrubberyCreationForm", "RobotomyRequestForm","PresidentialPardonForm"};
	for (int i = 0; i <= 3; i++)
	{
		form = intern_jack.makeForm(formArr[i], "Bender");
		if (form)
		{
			Bureaucrat Ajax("Ajax", 1);
			try
			{	
				Ajax.SignForm(*form);
				Ajax.executeForm(*form);
			}
			catch (std::exception &e)
			{
				std::cout << e.what() << std::endl;
			}
		}
		else
		{
			std::cout << "Form creation failed." << std::endl;
		}
		delete form;
	}
		return (0);
}

// int main(void){
//     Intern RandomIntern;
//     AForm *Form;

//     std::string FormTab[] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm", "UknownForm"};

//     for (int i = 0; i < 4; i++){
//         Form = RandomIntern.makeForm(FormTab[i], "Bender");
//         if (Form){
//             Bureaucrat Bob("Bob", 1);
//             try{
//                 Bob.SignForm(*Form);
//                 Bob.executeForm(*Form);
//             }
//             catch (std::exception &e){
//                 std::cout << e.what() << std::endl;
//             }
//         }
//         else{
//             std::cout << "Form creation failed." << std::endl;
//         }
//         delete Form;
//     }
//     return (0);
// }


// int main(){
//     try {
//         Intern someRandomIntern;
//         AForm* form;

//         std::cout << "===== Test Intern Form Creation =====" << std::endl;
//         form = someRandomIntern.makeForm("robotomy request", "Bender");
//         if (form)
//             std::cout << "Form created: " << *form << std::endl;
//         delete form;

//         form = someRandomIntern.makeForm("shrubbery creation", "Home");
//         if (form)
//             std::cout << "Form created: " << *form << std::endl;
//         delete form;

//         form = someRandomIntern.makeForm("presidential pardon", "Marvin");
//         if (form)
//             std::cout << "Form created: " << *form << std::endl;
//         delete form;

//         std::cout << "===== Test Unknown Form =====" << std::endl;
//         form = someRandomIntern.makeForm("unknown form", "Target");
//         if (!form)
//             std::cout << "Failed to create unknown form." << std::endl;
//         delete form;
//     }
//     catch (std::exception &e) {
//         std::cerr << "Exception attrapée: " << e.what() << std::endl;
//     }
    
//     return 0;
// }
