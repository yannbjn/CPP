/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frite <frite@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 18:09:48 by yabejani          #+#    #+#             */
/*   Updated: 2024/10/24 14:23:30 by frite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Pourquoi une interface ? : Une interface permet de définir un comportement
// sans en fournir l'implémentation. Cela garantit que toutes les classes qui 
// implémentent ICharacter auront les méthodes equip(), unequip(), et use().

#pragma once

#include <iostream>
#include <string>

class AMateria;

class ICharacter
{
    public:
        virtual ~ICharacter() {}
        virtual std::string const &getName() const = 0;
        virtual void equip(AMateria *m) = 0;
        virtual void unequip(int idx) = 0;
        virtual void use(int idx, ICharacter &target) = 0;
};
