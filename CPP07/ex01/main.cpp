/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frite <frite@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:18:28 by yabejani          #+#    #+#             */
/*   Updated: 2025/04/16 14:37:17 by frite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "iter.hpp"

// template<typename T>
// void printElem(T &x){
// 	std::cout << x << std::endl;
// }

template<typename T>
void printElem(T& x){
	std::cout << x << std::endl;
}

template<typename T>
void minusss(T& x){
	x = x - 32;
}

int main(void){
	char arr[] = {'b', 'o', 'n', 'j', 'o', 'u', 'r'};

	iter(arr, 7, printElem);
	std::cout << "------------------" << std::endl;
	iter(arr, 7, minusss);
	iter(arr, 7, printElem);
	int tab[] = {12, 23 , 345, 3, 42, 24};
	std::cout << "------------------" << std::endl;
  iter(tab, 6, printElem);
	std::cout << "------------------" << std::endl;
	iter(tab, 6, minusss);
  iter(tab, 6, printElem);
}

