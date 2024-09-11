/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frite <frite@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:09:13 by frite             #+#    #+#             */
/*   Updated: 2024/09/11 17:22:59 by frite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name)
{
	Zombie *horde = new Zombie[N];
	for (int i = 0; i < N; i++)
		horde[i].setName(name);
	return (horde);
}
