/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabejani <yabejani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:33:02 by frite             #+#    #+#             */
/*   Updated: 2025/03/19 16:26:16 by yabejani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <exception>
#include <iostream>
#include <iomanip>

#include "Form.hpp"
#include "colors.hpp"

class Form;

class Bureaucrat
{
    private:
        std::string const _name;
        int _grade;
    
    public:
        Bureaucrat(); //canonical
        Bureaucrat(std::string const name, int grade);
        Bureaucrat(Bureaucrat const &src); //canonical

        ~Bureaucrat();
        
        Bureaucrat &operator=(Bureaucrat const &rhs); //canonical

        std::string getName();
        int getGrade();

        void    incrGrade();
        void    decrGrade();
        void    SignForm(Form &form);
        
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
