/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabejani <yabejani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:36:01 by yabejani          #+#    #+#             */
/*   Updated: 2025/03/26 15:33:15 by yabejani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

int	main(void)
{
	Intern	intern_jack;
	AForm	*form;
	std::string formArr[] = {"RandomForm", "shrubbery creation", "robotomy request","presidential pardon", "non existent form"};
	for (int i = 0; i <= 4; i++)
	{
		form = intern_jack.makeForm(formArr[i], "Bender");
		if (form)
		{
			Bureaucrat Ajax("Ajax", 1);
			try
			{	
				Ajax.signForm(*form);
				Ajax.executeForm(*form);
				std::cout << *form << std::endl;
			}
			catch (std::exception &e)
			{
				std::cout << e.what() << std::endl;
			}
		}
		else
		{
			std::cout << BOLD << RED << "Form creation failed." << RESET << std::endl;
		}
		delete form;
	}
		return (0);
}

