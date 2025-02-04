/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabejani <yabejani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:25:16 by yabejani          #+#    #+#             */
/*   Updated: 2025/02/04 17:44:27 by yabejani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void    ScalarConverter::convert(std::string const &literal){
    char    c;
    int     i;
    float   f;
    double  d;

    if (literal == "-inf" || literal == "+inf" || literal == "nan"){
        std::cout << UNDERLINE << MAGENTA << "char: " << BOLD << RED << "conversion of " << literal << " in char impossible!" << RESET << std::endl;
        std::cout << UNDERLINE << MAGENTA << "int: " << BOLD << RED << "conversion of " << literal << " in int impossible!" << RESET << std::endl;
        std::cout << UNDERLINE << MAGENTA << "float: " << BOLD << RED << "conversion of " << literal << " in float impossible!" << RESET << std::endl;
        std::cout << UNDERLINE << MAGENTA << "double: " << BOLD << RED << "conversion of " << literal << " in double impossible!" << RESET << std::endl;
        return ;
    }

    std::istringstream iss(literal);
}
