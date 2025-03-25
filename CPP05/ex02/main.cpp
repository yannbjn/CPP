/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frite <frite@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 13:49:33 by frite             #+#    #+#             */
/*   Updated: 2025/03/25 16:12:50 by frite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <limits>
#include <sstream>

int main() {
    try {
        std::cout << BOLD << MAGENTA << "===== Création des Bureaucrates =====" << RESET << std::endl << std::endl;
        Bureaucrat bob("Bob", 50);
        Bureaucrat alice("Alice", 5);
        Bureaucrat noobBur("Noob", 142);
        
        std::cout << bob << std::endl;
        std::cout << alice << std::endl;
        std::cout << noobBur << std::endl;
        
        std::cout << BOLD << MAGENTA << "===== Création des Formulaires =====" << RESET << std::endl << std::endl;
        ShrubberyCreationForm shrubForm("ShrubForm");
        RobotomyRequestForm roboForm("RobForm");
        PresidentialPardonForm pardonForm("PresForm");
        PresidentialPardonForm noobPardonForm("noobPresForm");
        
        std::cout << shrubForm << std::endl;
        std::cout << roboForm << std::endl;
        std::cout << pardonForm << std::endl;
        std::cout << noobPardonForm << std::endl;
        
        std::cout << BOLD << MAGENTA << "===== Test Signature =====" << RESET << std::endl << std::endl;
        bob.SignForm(shrubForm);
        std::cout << shrubForm << std::endl;
        alice.SignForm(pardonForm);
        std::cout << pardonForm << std::endl;
        alice.SignForm(roboForm);
        std::cout << roboForm << std::endl;
        std::cout << noobPardonForm << std::endl;
        // try {
        //     alice.SignForm(roboForm);
        // } catch (const std::exception &e) {
        //     std::cerr << "Erreur lors du test Robotomy : " << e.what() << std::endl;
        // }
        std::cout << BOLD << MAGENTA << "===== Test Exécution =====" << RESET << std::endl << std::endl;
        bob.executeForm(shrubForm);
        alice.executeForm(pardonForm);
        alice.executeForm(roboForm);
        noobBur.executeForm(shrubForm);
        
        
        std::cout << BOLD << MAGENTA << "===== Test Robotomy (50% de chance d'échouer) =====" << RESET << std::endl << std::endl;
        alice.SignForm(roboForm);
        alice.executeForm(roboForm);
    }
    catch (std::exception &e) {
        std::cerr << "Exception attrapée: " << e.what() << std::endl;
    }
    
    return 0;
}
