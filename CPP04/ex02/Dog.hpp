/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabejani <yabejani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 14:43:35 by frite             #+#    #+#             */
/*   Updated: 2024/11/05 15:54:35 by yabejani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal{
    private:
        Brain* _brain;

    public:
        Dog();
        Dog(const Dog& other);
        Dog& operator=(const Dog& other);
        virtual ~Dog();
        void makeSound() const;
        void setIdea(int index,const std::string  &idea);
        std::string  getIdea(int index)const ;
};
