/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabejani <yabejani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 19:03:05 by yabejani          #+#    #+#             */
/*   Updated: 2025/04/07 19:06:48 by yabejani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main(void)
{
	for (int i = 0; i < 10; i++)
	{
		std::srand(std::time(NULL) + std::clock());

		//identify pointer
		Base *object = generate();
		identify(object);

		//identify reference
		identify(*object);

		std::cout << "-----------------------" << std::endl;
		delete(object);
	}
	return (0);
}