/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabejani <yabejani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:38:02 by frite             #+#    #+#             */
/*   Updated: 2024/12/02 18:10:10 by yabejani         ###   ########.fr       */
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
        std::cout << "Bureaucrat John: " << e.what() << std::endl;
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
        std::cout << "Bureaucrat Jack: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat invalid("Invalid", 0);
    }
    catch (std::exception &e)
    {
        std::cout << "Bureaucrat Invalid: " << e.what() << std::endl;
    }

    return 0;
}
