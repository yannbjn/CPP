/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabejani <yabejani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 19:10:53 by yabejani          #+#    #+#             */
/*   Updated: 2025/02/04 16:22:59 by yabejani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"



Form::Form() : _name("Empty"), _isSigned(false), _ReqGrade(0), _execGrade(0){
}

Form::~Form(){
}

Form::Form(std::string name, int signGrade, int execGrade) : _name(name), _isSigned(false), _ReqGrade(signGrade), _execGrade(execGrade)
{	
	if (signGrade < 1 || execGrade < 1){
		throw (Form::GradeTooHighException());
	}
	else if (signGrade > 150 || execGrade > 150){
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

bool	Form::getIsFormSigned() const 
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

bool	Form::CanSignForm(Bureaucrat bureaucrat) 
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

const char *Form::GradeTooLowException::what(void) const throw(){
	return ("Grade is too low");
}

const char *Form::GradeTooHighException::what(void) const throw(){
	return ("Grade is too high");
}

std::ostream	&operator<<(std::ostream &o, Form &Form)
{
	o << "Form: " << Form.getName() << std::endl;
	//o << "Signed: " << Form.getIsFormSigned() << std::endl;
	if (Form.getIsFormSigned())
		o << "Is Form Signed: True" << std::endl;
	else
		o << "Is Form Signed: False" << std::endl;
	o << "Required Grade to sign Form: " << Form.getReqGrade() << std::endl;
	o << "Required Grade to execute Form: " << Form.getexecGrade() << std::endl;
	return (o);
}
