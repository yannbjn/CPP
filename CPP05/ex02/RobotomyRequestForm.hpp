/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frite <frite@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:04:25 by frite             #+#    #+#             */
/*   Updated: 2025/01/16 14:50:09 by frite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    private:
        std::string _target;

    public:
        RobotomyRequestForm(); //canonical
        RobotomyRequestForm(std::string name);
        RobotomyRequestForm(RobotomyRequestForm const &src); //canonical

        ~RobotomyRequestForm();

        RobotomyRequestForm &operator=(RobotomyRequestForm const &rhs);
        void execute(Bureaucrat const &executor) const;
};
