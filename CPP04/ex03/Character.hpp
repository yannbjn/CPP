/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabejani <yabejani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 15:50:18 by frite             #+#    #+#             */
/*   Updated: 2024/10/25 16:03:35 by yabejani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ICharacter.hpp"
#include "AMateria.hpp"

#include <iomanip>

class Character : public ICharacter
{
private:
    std::string _name;
    AMateria    *_inventory[4];
    AMateria    *_stockunequiped[4];

public:
    Character();
    Character(std::string const &name);
    Character(Character const &other);
    Character &operator=(Character const &other);
    ~Character();

    std::string const &getName() const;
    void    equip(AMateria *m);
    void    unequip(int idx);
    void    use(int idx, ICharacter &target);
    void    del_unequiped();
    bool    checkempty(AMateria **_inventory);
    bool    checkfull(AMateria **_inventory);
    void    displayinvetory() const;
};
