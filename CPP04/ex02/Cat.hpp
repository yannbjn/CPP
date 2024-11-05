/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabejani <yabejani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 14:47:23 by frite             #+#    #+#             */
/*   Updated: 2024/11/05 15:54:45 by yabejani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal{
    private:
        Brain* _brain;

    public:
        Cat();
        Cat(const Cat& other);
        Cat& operator=(const Cat& other);
        virtual ~Cat();
        void makeSound() const;
        void setIdea(int index,const std::string  &idea);
        std::string  getIdea(int index)const;
};
