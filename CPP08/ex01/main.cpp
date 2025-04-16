/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frite <frite@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 17:22:25 by frite             #+#    #+#             */
/*   Updated: 2025/04/16 17:23:14 by frite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>

#include "Span.hpp"

int main(void)
{
    
}

// #include <iostream>
// #include "Span.hpp"
// #include <cstdlib>

// int main() {
//     try {
//         Span sp(5);
//         sp.addNumber(6);
//         sp.addNumber(3);
//         sp.addNumber(17);
//         sp.addNumber(9);
//         sp.addNumber(11);

//         std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
//         std::cout << "Longest span: " << sp.longestSpan() << std::endl;

//         // Test bonus avec 10000 nombres aléatoires
//         Span bigSpan(10000);
//         std::vector<int> data;
//         for (int i = 0; i < 10000; ++i)
//             data.push_back(rand());

//         bigSpan.addRange(data.begin(), data.end());
//         std::cout << "Shortest (big): " << bigSpan.shortestSpan() << std::endl;
//         std::cout << "Longest (big): " << bigSpan.longestSpan() << std::endl;

//     } catch (std::exception& e) {
//         std::cerr << "Exception: " << e.what() << std::endl;
//     }

//     return 0;
// }
