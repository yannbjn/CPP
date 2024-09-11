/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frite <frite@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:57:36 by frite             #+#    #+#             */
/*   Updated: 2024/09/11 17:36:37 by frite            ###   ########.fr       */
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
        Zombie(void);
		~Zombie(void);
        void    announce(void);
        void    setName(std::string name);
        static int num;
};

Zombie *zombieHorde(int N, std::string name);

#endif