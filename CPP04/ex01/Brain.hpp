/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabejani <yabejani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 16:19:51 by frite             #+#    #+#             */
/*   Updated: 2024/10/07 16:32:24 by yabejani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <iomanip>

class Brain
{
    protected:
        std::string _ideas[100];

    public:
        Brain(); //canonical
        Brain(Brain const &src); //canonical
        virtual ~Brain();

        Brain &operator=(const Brain &rhs);
};
