/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frite <frite@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 14:43:35 by frite             #+#    #+#             */
/*   Updated: 2024/10/01 17:49:08 by frite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Dog: public Animal
{
	private:
		Brain *_Brain;
	public:
		Dog();
		Dog(Dog const &src);
		~Dog();

		Dog	&operator=(Dog const &rhs);

		void	makeSound() const;
};
