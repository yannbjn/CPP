/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frite <frite@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:57:22 by frite             #+#    #+#             */
/*   Updated: 2024/09/11 17:29:02 by frite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	int	N;

	N = 20;
	Zombie *horde = zombieHorde(N, "Foo");
	for (int i = 0; i < N; i++)
		horde[i].announce();
	Zombie::num -= 1;
	delete [] horde;
}
