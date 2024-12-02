/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabejani <yabejani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:44:23 by frite             #+#    #+#             */
/*   Updated: 2024/12/02 19:20:45 by yabejani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Form
{
    private:
        std::string const   _name;
        bool                _isSigned;
        int const           _ReqGrade;
        int const           _execGrade;

    public:
        Form(); //canonical
        Form(std::string const name, int const _signGrade, int const _execGrade);
        Form(Form const &src); //canonical

        ~Form();

        Form &operator=(Form const &rhs); //canonical

        
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
        bool                getIsGradeSigned(void) const;
        int                 getReqGrade(void) const;
        int                 getexecGrade(void) const;
        
        /// MEMBER FT ///
        bool				SignGrade(Bureaucrat bureaucrat);
};

std::ostream    &operator<<(std::ostream &o, Form &Form);
