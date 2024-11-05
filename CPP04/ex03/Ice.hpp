/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frite <frite@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 18:27:24 by yabejani          #+#    #+#             */
/*   Updated: 2024/10/08 14:53:47 by frite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"

class Ice : public AMateria
{
public:
    Ice();
    Ice(Ice const &other);
    Ice &operator=(Ice const &other);
    ~Ice();

    AMateria *clone() const;
    void use(ICharacter &target);
};
