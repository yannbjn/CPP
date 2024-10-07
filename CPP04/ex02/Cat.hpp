/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frite <frite@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 14:47:23 by frite             #+#    #+#             */
/*   Updated: 2024/10/01 17:49:04 by frite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Cat: public Animal
{
	private:
		Brain *_Brain;
	public:
		Cat();
		Cat(Cat const &src);
		~Cat();

		Cat	&operator=(Cat const &rhs);

		void	makeSound() const;
};

