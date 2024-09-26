/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frite <frite@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 14:26:52 by frite             #+#    #+#             */
/*   Updated: 2024/09/26 17:07:39 by frite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>



class Animal
{
    protected:
		std::string _type;

	public:
		Animal(); //canonical
		Animal(Animal const &src); // canonical
		virtual ~Animal();

		Animal	&operator=(Animal const &rhs); // canonical

		std::string	getType() const;
		virtual void	makeSound() const; // mot cle virtual permet de dire que cette methode peut etre redefinie dans une classe derivee
	
};
