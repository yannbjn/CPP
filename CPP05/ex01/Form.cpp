/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabejani <yabejani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 19:10:53 by yabejani          #+#    #+#             */
/*   Updated: 2024/12/02 19:16:05 by yabejani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("Empty"), _isSigned(false), _ReqGrade(0), _execGrade(0) 
{

}

Form::~Form() 
{

}

Form::Form(std::string name, int signGrade, int execGrade) : _name(name), _isSigned(false), _ReqGrade(signGrade), _execGrade(execGrade)
{	
	if (signGrade < 1 || execGrade < 1) {
		throw (Form::GradeTooHighException());
	} else if (signGrade > 150 || execGrade > 150) {
		throw (Form::GradeTooLowException());
	}
}

Form::Form(Form const &src) : _name(src.getName()), _isSigned(false), _ReqGrade(src.getReqGrade()), _execGrade(src.getexecGrade())
{
	*this = src;
}

Form	&Form::operator=(Form const &rhs) 
{
	if (this != &rhs) {
		Form tmp(rhs);
		*this = tmp;
	}
	return *this;
}

std::string const	Form::getName() const 
{
	return _name;
}

bool	Form::getIsGradeSigned() const 
{
	if (_isSigned == true)
		return true;
	return false;
}

int	Form::getReqGrade() const 
{
	return _ReqGrade;
}

int	Form::getexecGrade() const 
{
	return _execGrade;
}

bool	Form::SignGrade(Bureaucrat bureaucrat) 
{
	if (bureaucrat.getGrade() <= this->_ReqGrade) 
	{
		_isSigned = true;
		return (true);
	}
	else 
	{
		throw Form::GradeTooLowException();
	}
}

std::ostream	&operator<<(std::ostream &out, Form const &form) {
	out << "Form : " << form.getName() << std::endl;
	out << "Signed : " << form.getIsGradeSigned() << std::endl;
	out << "Required Grade : " << form.getReqGrade() << std::endl;
	out << "Executable Grade : " << form.getexecGrade() << std::endl;
	return (out);
}
