/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabejani <yabejani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 18:37:28 by yabejani          #+#    #+#             */
/*   Updated: 2025/01/22 18:59:18 by yabejani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#include <string>


class Intern
{
    private:
        
    public:
        Intern();
        Intern(Intern const &src);

        ~Intern();

        Intern &operator=(Intern const &rhs);

        AForm *makeForm(std::string FormName, std::string target);
};