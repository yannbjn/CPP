/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frite <frite@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:21:46 by frite             #+#    #+#             */
/*   Updated: 2025/03/25 18:16:20 by frite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/*Le rôle du constructeur : Le constructeur est responsable d'initialiser l'objet. 
S'il y a une erreur (par exemple, un grade invalide), il est préférable d'arrêter 
la création de l'objet en lançant une exception plutôt que de tenter de corriger 
l'erreur à l'intérieur du constructeur. Le constructeur ne devrait pas gérer lui-même 
ses propres erreurs, mais plutôt signaler ces erreurs pour que le code appelant puisse les gérer.

Le principe de propagation des exceptions : 
Si une exception est lancée dans un constructeur ou une méthode, 
elle est propagée vers l'appelant. Ce dernier pourra attraper cette exception et la traiter correctement 
dans un bloc try-catch. La gestion des exceptions se fait donc à un niveau supérieur (comme dans le main), 
là où l'objet est utilisé.*/

Bureaucrat::Bureaucrat() : _name("no name"), _grade(0){
    std::cout << "Bureaucrat: Default constructor called." << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade){
    if (grade < 1)
        throw Bureaucrat::GradeTooLowException();
    if (grade > 150)
        throw Bureaucrat::GradeTooHighException();
}

Bureaucrat::Bureaucrat(Bureaucrat const &src) : _name(src._name), _grade(src._grade){
    //std::cout << "Bureaucrat: Copy constructor called." << std::endl;
}

Bureaucrat::~Bureaucrat(){
    //std::cout << YELLOW << "Bureaucrat " << this->_name << ": Destructor called." << RESET << std::endl;
}

std::string const Bureaucrat::getName() const{
    return this->_name;
}

int Bureaucrat::getGrade() const{
    return this->_grade;
}

void Bureaucrat::incrGrade(){
    this->_grade--;
    if (this->_grade < 1)
        throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::decrGrade(){
    this->_grade++;
    if (this->_grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs){
    //std::cout << "Bureaucrat Assignation operator overload called" << std::endl;
    if (this == &rhs)
        return *this;
    this->_grade = rhs._grade;
    return *this;
}

const char *Bureaucrat::GradeTooHighException::what() const throw(){
    return ("Grade is too High.");
}

const char *Bureaucrat::GradeTooLowException::what() const throw(){
    return ("Grade is too Low.");
}

std::ostream &operator<<(std::ostream &o, Bureaucrat &bureaucrat){
    o << "Bureaucrat named \"" << bureaucrat.getName() << "\" current grade is " << bureaucrat.getGrade() << "." << std::endl;
    return (o);
}

void    Bureaucrat::signForm(AForm &form){
    // if (form.beSigned(*this) == true){
    //     std::cout << this->getName() << " signed " << form.getName() << std::endl;
    // }
    // else{
    //     std::cout << this->getName() << " couldn't sign " << form.getName() << " because his grade is " << this->getGrade() << " while we need a Bureaucrat of rank " << form.getReqGrade() << std::endl;
    // }
    try {
        form.beSigned(*this);
        std::cout << GREEN << this->getName() << " signed " << form.getName() << RESET << std::endl;
    }
    catch (std::exception &e){
        std::cerr << RED << this->getName() << " couldn't sign " << form.getName() << " because " << e.what() << RESET << std::endl;
    }
}

void    Bureaucrat::executeForm(AForm const &form){
    try{
        form.execute(*this);
        std::cout << GREEN << getName() << " executed " << form.getName() << " form." << RESET << std::endl;
    }
    catch (std::exception &e){
        std::cerr << RED << getName() << " couldn't execute " << form.getName() << " because " << e.what() << RESET << std::endl;
    }
}
