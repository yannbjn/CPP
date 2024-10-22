/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frite <frite@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:44:23 by frite             #+#    #+#             */
/*   Updated: 2024/10/22 17:30:11 by frite            ###   ########.fr       */
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
        int const           _signGrade;
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
        bool                getboolisSigned(void) const;
        int                 getsignGrade(void) const;
        int                 getexecGrade(void) const;
        
        /// MEMBER FT ///
        
};

std::ostream    &operator<<(std::ostream &o, Form &Form);
