/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frite <frite@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:49:19 by frite             #+#    #+#             */
/*   Updated: 2024/10/08 14:49:27 by frite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"

class Cure : public AMateria
{
public:
    Cure();
    Cure(Cure const &other);
    Cure &operator=(Cure const &other);
    ~Cure();

    AMateria *clone() const;
    void use(ICharacter &target);
};
