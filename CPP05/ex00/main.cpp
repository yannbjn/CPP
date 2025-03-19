/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabejani <yabejani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:38:02 by frite             #+#    #+#             */
/*   Updated: 2025/03/19 16:06:15 by yabejani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(){
    try
    {
        Bureaucrat john("John", 2);
        std::cout << john << std::endl;
        john.incrGrade();
        std::cout << john << std::endl;
        john.incrGrade();
        std::cout << john << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << BOLD << RED << "Bureaucrat John: " << e.what() << RESET << std::endl;
    }

    try
    {
        Bureaucrat jack("Jack", 149);
        std::cout << jack << std::endl;

        jack.decrGrade();
        std::cout << jack << std::endl;

        jack.decrGrade();
    }
    catch (std::exception &e)
    {
        std::cerr << BOLD << RED << "Bureaucrat Jack: " << e.what() << RESET << std::endl;
    }

    try
    {
        Bureaucrat invalid("Invalid", 0);
    }
    catch (std::exception &e)
    {
        std::cerr << BOLD << RED << "Bureaucrat Invalid: " << e.what() << RESET << std::endl;
    }

    return 0;
}
