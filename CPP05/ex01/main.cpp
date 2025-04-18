/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frite <frite@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:38:02 by frite             #+#    #+#             */
/*   Updated: 2025/03/25 18:16:20 by frite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(){
    Bureaucrat noobBur("Noob", 140);
    Bureaucrat OgBur("Og", 5);
    Form Form1("Contract", 139, 50);

    std::cout << noobBur;
    std::cout << OgBur;
    std::cout << Form1;

    //should fail
    try{
        noobBur.signForm(Form1);
    }
    catch(Form::GradeTooLowException &e){
        std::cout << noobBur.getName() << " can't sign the form: \"" << Form1.getName() << "\" " << e.what() << std::endl;
    }
    std::cout << Form1; //checks if Form has been signed

    //should be able to sign
    try{
        OgBur.signForm(Form1);
    }
    catch(Form::GradeTooLowException &e){
        std::cout << OgBur.getName() << " can't sign the form: \"" << Form1.getName() << "\" " << e.what() << std::endl;
    }
    std::cout << Form1;
}
