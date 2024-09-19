/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabejani <yabejani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 15:29:36 by yabejani          #+#    #+#             */
/*   Updated: 2024/09/19 19:32:57 by yabejani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <iostream>
int main( void )
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	std::cout << "//////////////////////////////////////////////" << std::endl;
	Fixed const c( Fixed(30) / Fixed (10));
	int i = c.toInt();
	std::cout << i << std::endl;
	Fixed const d( Fixed(30) / Fixed (1));
	i = d.toInt();
	std::cout << i << std::endl;
	std::cout << Fixed::min 

	return 0;
}
