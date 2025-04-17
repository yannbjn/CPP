/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabejani <yabejani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:50:37 by yabejani          #+#    #+#             */
/*   Updated: 2025/04/17 15:09:48 by yabejani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main(void)
{
    try 
    {
        Array<int> arr(5);
        Array<char> charr(10);

        char content = 'a';

        for (unsigned int i = 0; i < arr.size(); i++)
            arr[i] = i * 10;
        for (unsigned int i = 0; i < arr.size(); i++)
        charr[i] = content++;

        std::cout << "Int Array contents: ";
        for (unsigned int i = 0; i < arr.size(); i++)
            std::cout << arr[i] << " ";
        std::cout << std::endl;

        std::cout << "Char Array contents: ";
        for (unsigned int i = 0; i < arr.size(); i++)
            std::cout << charr[i] << " ";
        std::cout << std::endl;

        Array<int> arrCopy = arr;
        arrCopy[0] = 999;

        std::cout << "Original arr[0]: " << arr[0] << std::endl;
        std::cout << "Copy arr[0]: " << arrCopy[0] << std::endl;

        std::cout << arr[10] << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}

// #include "Array.hpp"

// #include <iostream>
// #include <string>

// int main() {
// 	try {
// 		Array<int> b = Array<int>(5);
// 		(b)[0] = 42;
// 		std::cout << "a _size  = " << b.size() << std::endl;
// 		std::cout << "a[0]     = " << (b)[0] << std::endl;
// 		std::cout << "a[10]    = " << (b)[10] << std::endl;
// 	} catch (const std::exception& e) {
// 		std::cerr << e.what() << std::endl;
// 	}

// 	Array<std::string> stringArray(3);
// 	std::cout << "\nstringArray size: " << stringArray.size() << std::endl;
// 	for (std::size_t i = 0; i < stringArray.size(); ++i)
// 		stringArray[i] = 65 + i;
// 	for (std::size_t i = 0; i < stringArray.size(); ++i)
// 		std::cout << "a[" << i << "] = " << stringArray[i] << std::endl;

// 	Array<std::string> copystrArray(stringArray);
// 	std::cout << "\ncopystrArray : "  << std::endl;	
// 	for (std::size_t i = 0; i < copystrArray.size(); ++i) 
// 		std::cout << copystrArray[i] << std::endl;

// 	copystrArray[0] = "AAAAAA";
// 	stringArray = copystrArray;
// 	for (std::size_t i = 0; i < stringArray.size(); ++i)
// 		std::cout << "a[" << i << "] = " << stringArray[i] << std::endl;

// 	return 0;
// }
