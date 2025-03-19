/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabejani <yabejani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:04:25 by frite             #+#    #+#             */
/*   Updated: 2025/03/19 11:51:49 by yabejani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include "Bureaucrat.hpp"

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
