/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frite <frite@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 13:49:33 by frite             #+#    #+#             */
/*   Updated: 2025/01/16 17:25:23 by frite            ###   ########.fr       */
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

bool	check_name(const std::string &name)
{
	for (std::string::const_iterator it = name.begin(); it != name.end(); ++it)
	{
		if (!isalpha(*it))
			return (false);
	}
	return (true);
}

int main(void){
    std::cout << BLUE << "Presidential Form tests:" << RESET << std::endl;
    Bureaucrat employee("Pres", 1);
    PresidentialPardonForm PresidentialForm("Need pardon");
    try{
        employee.SignForm(PresidentialForm);
    }
}

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