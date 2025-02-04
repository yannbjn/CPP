/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabejani <yabejani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:02:00 by frite             #+#    #+#             */
/*   Updated: 2025/02/04 16:02:43 by yabejani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        std::string const   _name;
        bool                _isSigned;
        int const           _ReqGrade;
        int const           _execGrade;

    public:
        AForm(); //canonical
        AForm(std::string const name, int const _signGrade, int const _execGrade);
        AForm(AForm const &src); //canonical

        virtual ~AForm();

        AForm &operator=(AForm const &rhs); //canonical

        
        /// EXCEPTIONS ///
        class GradeTooLowException : public std::exception{
            public:
                virtual const char *what() const throw();
        };
        
        class GradeTooHighException : public std::exception{
            public:
                virtual const char *what() const throw();
        };

        /// GETTERS ///
        const std::string   getName(void) const;
        bool                getIsAFormSigned(void) const;
        int                 getReqGrade(void) const;
        int                 getexecGrade(void) const;
        
        bool				CanSignAForm(Bureaucrat &bureaucrat);
        virtual void        execute(Bureaucrat const &executor) const = 0;
};

std::ostream    &operator<<(std::ostream &o, AForm &AForm);