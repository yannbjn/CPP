/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frite <frite@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:39:17 by frite             #+#    #+#             */
/*   Updated: 2024/10/01 16:19:15 by frite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
    public:
        WrongCat(); //canonical
        WrongCat(WrongCat const &src); //canonical
        ~WrongCat();

        WrongCat &operator=(WrongCat const &rhs); //canonical

        void    makeSound() const;
};
