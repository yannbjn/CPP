/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frite <frite@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:57:22 by frite             #+#    #+#             */
/*   Updated: 2024/09/11 16:02:03 by frite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    Zombie *newZ = newZombie("I'm newZombie in heappp");
    newZ->announce();
    randomChump("I'm rdZ in stackk");
    delete (newZ);
}
