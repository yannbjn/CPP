/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frite <frite@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:11:55 by frite             #+#    #+#             */
/*   Updated: 2025/01/16 14:57:05 by frite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    private:
        std::string _target;
    
    public:
        PresidentialPardonForm(); //canonical
        PresidentialPardonForm(std::string name);
        PresidentialPardonForm(const PresidentialPardonForm &src); //canonical

        ~PresidentialPardonForm();

        PresidentialPardonForm &operator=(PresidentialPardonForm const &rhs); //canonical
        void    execute(Bureaucrat const &executor) const;
};
