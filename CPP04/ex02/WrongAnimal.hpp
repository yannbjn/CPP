/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frite <frite@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:06:24 by frite             #+#    #+#             */
/*   Updated: 2024/10/01 15:29:43 by frite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

class WrongAnimal
{
    protected:
        std::string _type;
    
    public:
        WrongAnimal(); // canonical
        WrongAnimal(WrongAnimal const &src); // canonical
        virtual ~WrongAnimal();

        WrongAnimal &operator=(WrongAnimal const &rhs); // canonical

        std::string     getType() const;
        virtual void    makeSound() const; // mot cle virtual permet de dire que cette methode peut etre redefinie dans une classe derivee
};
