/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frite <frite@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:57:36 by frite             #+#    #+#             */
/*   Updated: 2024/09/11 16:24:56 by frite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie
{
    private:
        std::string _name;

	public:
		Zombie(std::string name);
		~Zombie(void);
        void announce(void);
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

#endif