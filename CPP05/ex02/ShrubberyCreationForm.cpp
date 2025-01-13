/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frite <frite@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:03:23 by frite             #+#    #+#             */
/*   Updated: 2025/01/13 14:38:47 by frite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(){
    std::cout << "Shrubbery: Default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string name) : AForm::AForm("Shrubbery", 145, 137){
    this->_target = name;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src){
    std::cout << "Shrubbery: Copy constructor called" << std::endl;
    *this = src;
}

ShrubberyCreationForm   &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs){
    if (this != &rhs)
        _target = rhs._target;
    return *this;
}

// ShrubberyCreationForm::ShrubberyCreationForm()
// {

// }

// ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm::AForm("Shrubbery", 145, 137), _target(target) 
// {

// }

// ShrubberyCreationForm::~ShrubberyCreationForm() 
// {

// }

// ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) 
// {
// 	*this = src;
// }

// ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs) 
// {
// 	if (this != &rhs) 
// 		_target = rhs._target;
// 	return *this;
// }

// void	ShrubberyCreationForm::execute(const Bureaucrat &executor) const
// {
//     if (!getIs_Signed()) 
//     {
//         throw AForm::GradeTooLowException(); // Form must be signed first
//     }
//     if (executor.getGrade() > this->getExecGrade()) 
//     {
//         throw AForm::GradeTooLowException(); // Grade too low for execution
//     }
// 	std::string		outfile = this->_target + "_shrubbery";
// 	std::ofstream ofs(outfile.c_str());
// 	if (!ofs.is_open())
// 	{
// 		std::cout << "We had issue creating the outfile" << std::endl;
// 		return;
// 	}
// 	ofs <<"        	   ,@@@@@@@,				\n"
// 		  "       ,,,.   ,@@@@@@/@@,  .oo8888o.	\n"
// 		  "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o	\n"
// 		  "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'	\n"
// 		  "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'	\n"
// 		  "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'	\n"
// 		  "   `&%\\ ` /%&'    |.|        \\ '|8'	\n"
// 		  "       |o|        | |         | |		\n"
// 		  "       |.|        | |         | |		\n"
// 		  "	 \\/ ._\\//_/__/  ,\\_//___\\/.  \\_//__/_\n";
// 	ofs.close();
// 	std::cout << outfile << " created a forest" << std::endl;
//}