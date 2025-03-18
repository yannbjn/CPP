/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabejani <yabejani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 13:49:33 by frite             #+#    #+#             */
/*   Updated: 2025/03/18 14:15:37 by yabejani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "colors.hpp"
#include <limits>
#include <sstream>

int main() {
    try {
        std::cout << "===== Création des Bureaucrates =====" << std::endl;
        Bureaucrat bob("Bob", 50);
        Bureaucrat alice("Alice", 5);
        
        std::cout << bob << std::endl;
        std::cout << alice << std::endl;
        
        std::cout << "===== Création des Formulaires =====" << std::endl;
        ShrubberyCreationForm shrubForm("Garden");
        RobotomyRequestForm roboForm("Bender");
        PresidentialPardonForm pardonForm("Marvin");
        
        std::cout << shrubForm << std::endl;
        std::cout << roboForm << std::endl;
        std::cout << pardonForm << std::endl;
        
        std::cout << "===== Test Signature =====" << std::endl;
        bob.SignForm(shrubForm);
        alice.SignForm(pardonForm);
        
        std::cout << "===== Test Exécution =====" << std::endl;
        bob.executeForm(shrubForm);
        alice.executeForm(pardonForm);
        alice.executeForm(roboForm); // Alice ne l'a pas signé
        
        std::cout << "===== Test Robotomy (50% de chance d'échouer) =====" << std::endl;
        alice.SignForm(roboForm);
        alice.executeForm(roboForm);
    }
    catch (std::exception &e) {
        std::cerr << "Exception attrapée: " << e.what() << std::endl;
    }
    
    return 0;
}


// int main(void){
//     std::cout << BLUE << "Presidential Form tests:" << RESET << std::endl;
//     Bureaucrat employee("Pres", 6);
//     PresidentialPardonForm PresidentialForm("Need pardon");
//     try{
//         employee.SignForm(PresidentialForm);
//         employee.executeForm(PresidentialForm);
//     }
//     catch (std::exception &e){
//         std::cout << BOLD << RED << e.what() << RESET << std::endl;
//     }
// }

// int	main(void)
// {
// 	std::cout << std::endl;
// 	try
// 	{
// 		Bureaucrat employee("Ajax", 1);
// 		// PRESIDENTIAL PARDON FORM
// 		std::cout << "Presidential Form: " << std::endl;
// 		PresidentialPardonForm presForm("Bad guy");
// 		try
// 		{
// 			employee.SignForm(presForm);
// 			employee.executeForm(presForm);
// 		}
// 		catch (std::exception &e)
// 		{
// 			std::cout << e.what() << std::endl;
// 		}
// 		// ROBOTOMY REQUEST FORM
// 		std::cout << "Robotomy Form:" << std::endl;
// 		RobotomyRequestForm robotForm("Human");
// 		try
// 		{
// 			employee.SignForm(robotForm);
// 			employee.executeForm(robotForm);
// 		}
// 		catch (std::exception &e)
// 		{
// 			std::cout << e.what() << std::endl;
// 		}
// 		// SHRUBBERY CREATION FORM
// 		std::cout << "Shrubbery Form" << std::endl;
// 		ShrubberyCreationForm shrubForm("cool");
// 		try
// 		{
// 			employee.SignForm(shrubForm);
// 			employee.executeForm(shrubForm);
// 		}
// 		catch (std::exception &e)
// 		{
// 			std::cout << e.what() << std::endl;
// 		}
// 	}
// 	catch (const std::exception &e)
// 	{
// 		std::cerr << e.what() << '\n';
// 	}
// }