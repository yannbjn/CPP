/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabejani <yabejani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:12:25 by frite             #+#    #+#             */
/*   Updated: 2025/01/22 18:17:43 by yabejani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"


AForm::AForm() : _name("Empty"), _isSigned(false), _ReqGrade(1), _execGrade(1){
}

AForm::~AForm(){
}

AForm::AForm(std::string name, int signGrade, int execGrade) : _name(name), _isSigned(false), _ReqGrade(signGrade), _execGrade(execGrade)
{	
	if (signGrade < 1 || execGrade < 1){
		throw (AForm::GradeTooHighException());
	}
	else if (signGrade > 150 || execGrade > 150){
		throw (AForm::GradeTooLowException());
	}
}

AForm::AForm(AForm const &src) : _name(src.getName()), _isSigned(false), _ReqGrade(src.getReqGrade()), _execGrade(src.getexecGrade())
{
	*this = src;
}

AForm	&AForm::operator=(AForm const &rhs) 
{
	if (this != &rhs) {
		_isSigned = rhs.getIsAFormSigned();
	}
	return *this;
}

std::string const	AForm::getName() const 
{
	return _name;
}

bool	AForm::getIsAFormSigned() const 
{
	if (_isSigned == true)
		return true;
	return false;
}

int	AForm::getReqGrade() const 
{
	return _ReqGrade;
}

int	AForm::getexecGrade() const 
{
	return _execGrade;
}

bool	AForm::CanSignAForm(Bureaucrat &bureaucrat) 
{
	if (bureaucrat.getGrade() <= this->_ReqGrade) 
	{
		_isSigned = true;
		return (true);
	}
	else 
	{
		throw AForm::GradeTooLowException();
	}
}

const char *AForm::GradeTooLowException::what(void) const throw(){
	return ("Grade is too low. Min grade is 150.");
}

const char *AForm::GradeTooHighException::what(void) const throw(){
	return ("Grade is too high. Max grade is 1.");
}

std::ostream	&operator<<(std::ostream &o, AForm &AForm)
{
	o << "AForm: " << AForm.getName() << std::endl;
	//o << "Signed: " << AForm.getIsAFormSigned() << std::endl;
	if (AForm.getIsAFormSigned())
		o << "Is AForm Signed: True" << std::endl;
	else
		o << "Is Form Signed: False" << std::endl;
	o << "Required Grade to sign AForm: " << AForm.getReqGrade() << std::endl;
	o << "Required Grade to execute AForm: " << AForm.getexecGrade() << std::endl;
	return (o);
}

