/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabejani <yabejani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 14:26:52 by frite             #+#    #+#             */
/*   Updated: 2024/11/05 17:42:58 by yabejani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include "Brain.hpp"

class Animal
{
    protected:
		std::string _type;

	public:
		Animal(); //canonical
		Animal(Animal const &src); // canonical
		virtual ~Animal();

		Animal	&operator=(Animal const &rhs); // canonical

		std::string		getType() const;
		virtual void	makeSound() const = 0; // mot cle virtual permet de dire que cette methode peut etre redefinie dans une classe derivee
	
};
