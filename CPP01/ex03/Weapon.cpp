/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabejani <yabejani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 15:45:15 by yabejani          #+#    #+#             */
/*   Updated: 2024/09/12 16:58:47 by yabejani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string &type) : _type(type) {}

Weapon::~Weapon() {}

std::string const &Weapon::getType() const {return _type;}

void	Weapon::setType(const std::string &type) {_type = type;}