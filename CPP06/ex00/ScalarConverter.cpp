/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frite <frite@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:25:16 by yabejani          #+#    #+#             */
/*   Updated: 2025/04/02 16:01:32 by frite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "ScalarConverter.hpp"

// void    ScalarConverter::convert(std::string const &literal){
//     char    c;
//     int     i;
//     float   f;
//     double  d;

//     if (literal == "-inf" || literal == "+inf" || literal == "nan"){
//         std::cout << UNDERLINE << MAGENTA << "char: " << BOLD << RED << "conversion of " << literal << " in char impossible!" << RESET << std::endl;
//         std::cout << UNDERLINE << MAGENTA << "int: " << BOLD << RED << "conversion of " << literal << " in int impossible!" << RESET << std::endl;
//         std::cout << UNDERLINE << MAGENTA << "float: " << BOLD << RED << "conversion of " << literal << " in float impossible!" << RESET << std::endl;
//         std::cout << UNDERLINE << MAGENTA << "double: " << BOLD << RED << "conversion of " << literal << " in double impossible!" << RESET << std::endl;
//         return ;
//     }

//     std::istringstream iss(literal);
// }

#include "ScalarConverter.hpp"
#include <iostream>
#include <sstream>
#include <limits>
#include <cstdlib>
#include <cctype>
#include <iomanip>

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &src) {
    *this = src;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &rhs) {
    (void)rhs;
    return *this;
}

bool ScalarConverter::isInteger(const std::string &literal) {
    if (literal.empty()) return false;
    std::string::const_iterator it = literal.begin();
    if (*it == '+' || *it == '-') ++it;
    for (; it != literal.end(); ++it) {
        if (!std::isdigit(*it)) return false;
    }
    return true;
}

bool ScalarConverter::isFloat(const std::string &literal) {
    std::istringstream ss(literal);
    float f;
    ss >> f;
    return !ss.fail() && ss.eof();
}

bool ScalarConverter::isDouble(const std::string &literal) {
    std::istringstream ss(literal);
    double d;
    ss >> d;
    return !ss.fail() && ss.eof();
}

#include <cerrno>
#include <climits>
#include <cfloat>
#include <cmath>

void ScalarConverter::convert(std::string literal) {
    int to_Int = 0;
    float to_Float = 0.0f;
    double to_Double = 0.0;
    char to_Char = '\0';
    char *endptr = NULL;

    // Handle pseudo-literals
    if (literal == "-inff" || literal == "+inff" || literal == "nanf") {
        std::cout << "char: impossible\nint: impossible\n"
                  << "float: " << literal << "\n"
                  << "double: " << literal.substr(0, literal.size() - 1) << std::endl;
        return;
    }
    if (literal == "-inf" || literal == "+inf" || literal == "nan") {
        std::cout << "char: impossible\nint: impossible\n"
                  << "float: " << literal << "f\n"
                  << "double: " << literal << std::endl;
        return;
    }

    // Special case: single non-digit char like 'a'
    if (literal.length() == 1 && !std::isdigit(literal[0])){
        to_Char = literal[0];
        to_Int = static_cast<int>(to_Char);
        to_Float = static_cast<float>(to_Char);
        to_Double = static_cast<double>(to_Char);
    }
    else{
        // Convert using strtod (works for float, int, double parsing)
        errno = 0;
        to_Double = std::strtod(literal.c_str(), &endptr);
        if (errno == ERANGE || *endptr != '\0') {
            std::cout << "Invalid input: not a number" << std::endl;
            return;
        }

        to_Float = static_cast<float>(to_Double);

        // Only convert to int if within bounds
        if (to_Double >= static_cast<double>(INT_MIN) &&
            to_Double <= static_cast<double>(INT_MAX)) {
            to_Int = static_cast<int>(to_Double);
        } else {
            to_Int = INT_MIN; // placeholder to skip conversion
        }

        // Only convert to char if in displayable ASCII range
        if (to_Double >= 0 && to_Double <= 127) {
            char c = static_cast<char>(to_Double);
            if (std::isprint(c))
                to_Char = c;
        }
    }

    // Print char
    std::cout << "char: ";
    if (to_Char == '\0')
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << to_Char << "'" << std::endl;

    // Print int
    std::cout << "int: ";
    if (to_Double >= static_cast<double>(INT_MIN) &&
        to_Double <= static_cast<double>(INT_MAX))
        std::cout << to_Int << std::endl;
    else
        std::cout << "impossible" << std::endl;

    // Print float
    std::cout << "float: ";
    if (errno == ERANGE || fabs(to_Double) > FLT_MAX)
        std::cout << "impossible" << std::endl;
    else
        std::cout << std::fixed << std::setprecision(1) << to_Float << "f" << std::endl;

    // Print double
    std::cout << "double: ";
    if (errno == ERANGE || fabs(to_Double) > DBL_MAX)
        std::cout << "impossible" << std::endl;
    else
        std::cout << std::fixed << std::setprecision(1) << to_Double << std::endl;
}



// void ScalarConverter::convert(std::string literal) {
//     int to_Int;
//     float to_Float;
//     double to_Double;
//     char to_Char = '\0';

//     // Gestion des pseudo-littéraux
//     if (literal == "-inff" || literal == "+inff" || literal == "nanf"){
//         std::cout << "char: impossible\nint: impossible\n"
//                   << "float: " << literal << "\ndouble: " << literal.substr(0, literal.size() - 1) << std::endl;
//         return;
//     }
//     if (literal == "-inf" || literal == "+inf" || literal == "nan"){
//         std::cout << "char: impossible\nint: impossible\n"
//                   << "float: " << literal << "f\ndouble: " << literal << std::endl;
//         return;
//     }

//     // Détection du type d'entrée
//     std::string type;
//     if (literal.length() == 1 && !std::isdigit(literal[0])){
//         type = "char";
//         to_Char = literal[0];
//         to_Int = static_cast<int>(to_Char);
//         to_Float = static_cast<float>(to_Char);
//         to_Double = static_cast<double>(to_Char);
//     }
//     else if (isInteger(literal)){
//         type = "int";
//         std::istringstream ss(literal);
//         ss >> to_Int;
//         to_Char = (to_Int >= 32 && to_Int <= 126) ? static_cast<char>(to_Int) : '\0';
//         to_Float = static_cast<float>(to_Int);
//         to_Double = static_cast<double>(to_Int);
//     }
//     else if (literal[literal.length() - 1] == 'f' && isFloat(literal.substr(0, literal.size() - 1))) {
//         type = "float";
//         std::istringstream ss(literal);
//         ss >> to_Float;
//         to_Int = static_cast<int>(to_Float);
//         to_Double = static_cast<double>(to_Float);
//         to_Char = (to_Int >= 32 && to_Int <= 126) ? static_cast<char>(to_Int) : '\0';
//     }
//     else if (isDouble(literal)){
//         type = "double";
//         std::istringstream ss(literal);
//         ss >> to_Double;
//         to_Int = static_cast<int>(to_Double);
//         to_Float = static_cast<float>(to_Double);
//         to_Char = (to_Int >= 32 && to_Int <= 126) ? static_cast<char>(to_Int) : '\0';
//     } else {
//         std::cout << "Invalid input: Not a recognizable scalar type." << std::endl;
//         return;
//     }

//     // Affichage des résultats
//     if (type == "char"){
//         std::cout << "char: '" << to_Char << "'\n";
//     }
//     else if (to_Char == '\0') {
//         std::cout << "char: Non displayable\n";
//     } else {
//         // std::cout << "char: impossible\n";
//         std::cout << "char: '" << to_Char << "'\n";
//     }

//     std::cout << "int: " << to_Int << std::endl;
//     std::cout << "float: " << to_Float << (to_Float == static_cast<int>(to_Float) ? ".0f" : "f") << std::endl;
//     std::cout << "double: " << to_Double << (to_Double == static_cast<int>(to_Double) ? ".0" : "") << std::endl;
// }
