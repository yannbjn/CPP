/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabejani <yabejani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:33:02 by frite             #+#    #+#             */
/*   Updated: 2025/04/07 15:16:56 by yabejani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <exception>
#include <iostream>
#include <iomanip>

#include "AForm.hpp"               
#include "colors.hpp"

class AForm;

class Bureaucrat
{
    private:
        std::string const _name;
        int _grade; //higher grade is 1, lowest grade is 150
    
    public:
        Bureaucrat(); //canonical
        Bureaucrat(std::string const name, int grade);
        Bureaucrat(Bureaucrat const &src); //canonical

        ~Bureaucrat();
        
        Bureaucrat &operator=(Bureaucrat const &rhs); //canonical

        std::string const getName() const;
        int getGrade() const;

        void    incrGrade();
        void    decrGrade();
        void    signForm(AForm &form);
        void    executeForm(AForm const &form);
        
        
        class GradeTooHighException : public std::exception{
            public:
                virtual const char *what() const throw();
                
        };
        class GradeTooLowException : public std::exception{
            public:
                virtual const char *what() const throw();
        };
        
};

std::ostream    &operator<<(std::ostream &o, Bureaucrat &bureaucrat);
