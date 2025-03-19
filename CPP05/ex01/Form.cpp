/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabejani <yabejani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 19:10:53 by yabejani          #+#    #+#             */
/*   Updated: 2025/03/19 17:07:56 by yabejani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"



Form::Form() : _name("Empty"), _isSigned(false), _reqGrade(0), _execGrade(0){
}

Form::~Form(){
}

Form::Form(std::string name, int signGrade, int execGrade) : _name(name), _isSigned(false), _reqGrade(signGrade), _execGrade(execGrade)
{	
	if (signGrade < 1 || execGrade < 1){
		throw (Form::GradeTooHighException());
	}
	else if (signGrade > 150 || execGrade > 150){
		throw (Form::GradeTooLowException());
	}
}

Form::Form(Form const &src) : _name(src.getName()), _isSigned(false), _reqGrade(src.getReqGrade()), _execGrade(src.getexecGrade())
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
	return _reqGrade;
}

int	Form::getexecGrade() const 
{
	return _execGrade;
}

bool	Form::beSigned(Bureaucrat bureaucrat) 
{
	if (bureaucrat.getGrade() <= this->_reqGrade) 
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
	o << std::endl;
	o << "----------------------------------------" << std::endl;
	o << "Form name: " << Form.getName() << std::endl;
	//o << "Signed: " << Form.getIsFormSigned() << std::endl;
	if (Form.getIsFormSigned())
		o << BLUE << "Is Form Signed: True" << RESET << std::endl;
	else
		o << YELLOW << "Is Form Signed: False" << RESET << std::endl;
	o << "Required Grade to sign Form: " << Form.getReqGrade() << std::endl;
	o << "Required Grade to execute Form: " << Form.getexecGrade() << std::endl;
	o << "----------------------------------------" << std::endl;
	o << std::endl;
	return (o);
}
