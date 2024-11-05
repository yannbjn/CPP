/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabejani <yabejani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 16:19:51 by frite             #+#    #+#             */
/*   Updated: 2024/11/05 15:55:03 by yabejani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

class Brain{
    public:
        std::string _idea[100];

        Brain();
        Brain(const Brain& other);
        Brain& operator=(const Brain& other);
        ~Brain();
        void setIdea(int index, const std::string  &idea);
        std::string getIdea(int index);
};
