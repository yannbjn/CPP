/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabejani <yabejani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:25:16 by yabejani          #+#    #+#             */
/*   Updated: 2025/04/07 17:50:49 by yabejani         ###   ########.fr       */
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

// ScalarConverter::ScalarConverter() {}

// ScalarConverter::~ScalarConverter() {}

// ScalarConverter::ScalarConverter(const ScalarConverter &src) {
//     *this = src;
// }

// ScalarConverter &ScalarConverter::operator=(const ScalarConverter &rhs) {
//     (void)rhs;
//     return *this;
// }

// bool ScalarConverter::isInteger(const std::string &literal) {
//     if (literal.empty()) return false;
//     std::string::const_iterator it = literal.begin();
//     if (*it == '+' || *it == '-') ++it;
//     for (; it != literal.end(); ++it) {
//         if (!std::isdigit(*it)) return false;
//     }
//     return true;
// }

// bool ScalarConverter::isFloat(const std::string &literal) {
//     std::istringstream ss(literal);
//     float f;
//     ss >> f;
//     return !ss.fail() && ss.eof();
// }

// bool ScalarConverter::isDouble(const std::string &literal) {
//     std::istringstream ss(literal);
//     double d;
//     ss >> d;
//     return !ss.fail() && ss.eof();
// }

// #include <cerrno>
// #include <climits>
// #include <cfloat>
// #include <cmath>



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
//     }
//     else{
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


void ScalarConverter::convert(std::string literal){

    char *end;
    
    long to_Int;
    float to_Float;
    double to_Double;
    char to_Char = '\0';

    // Gestion des pseudo-littéraux
    if (literal == "-inff" || literal == "+inff" || literal == "nanf"){
        std::cout << "char: impossible\nint: impossible\n"
                  << "float: " << literal << "\ndouble: " << literal.substr(0, literal.size() - 1) << std::endl;
        return;
    }
    if (literal == "-inf" || literal == "+inf" || literal == "nan"){
        std::cout << "char: impossible\nint: impossible\n"
                  << "float: " << literal << "f\ndouble: " << literal << std::endl;
        return;
    }

    // Détection du type d'entrée
    std::string type;
    if (literal.length() == 1 && !std::isdigit(literal[0])){
        type = "char";
        to_Char = literal[0];
        to_Int = static_cast<int>(to_Char);
        to_Float = static_cast<float>(to_Char);
        to_Double = static_cast<double>(to_Char);
    }
    else if (isInteger(literal)){
        type = "int";
        errno = 0;
        to_Int = std::strtol(literal.c_str(), &end, 10);
        if (errno == ERANGE || (to_Int < std::numeric_limits<int>::min() || to_Int > std::numeric_limits<int>::max())){
            std::cerr << BOLD << RED << "POSSIBLE INT OVER OR UNDERFLOW, STOPPING EXECUTION HERE" << RESET << std::endl;
            return ;
        }
        to_Char = (to_Int >= 32 && to_Int <= 126) ? static_cast<char>(to_Int) : '\0';
        to_Float = static_cast<float>(to_Int);
        to_Double = static_cast<double>(to_Int);
    }
    else if (literal[literal.length() - 1] == 'f' && isFloat(literal.substr(0, literal.size() - 1))){
        type = "float";
        errno = 0;
        to_Float = std::strtof(literal.c_str(), &end);
        if (errno == ERANGE){
            std::cerr << BOLD << RED << "POSSIBLE FLOAT OVER OR UNDERFLOW, STOPPING EXECUTION HERE" << RESET << std::endl;
            return ;
        }
        to_Int = static_cast<int>(to_Float);
        to_Double = static_cast<double>(to_Float);
        to_Char = (to_Int >= 32 && to_Int <= 126) ? static_cast<char>(to_Int) : '\0';
    }
    else if (isDouble(literal)){
        type = "double";
        errno = 0;
        to_Double = std::strtod(literal.c_str(), &end);
        if (errno == ERANGE){
            std::cerr << BOLD << RED << "POSSIBLE INT OVER OR UNDERFLOW, STOPPING EXECUTION HERE" << RESET << std::endl;
            return ;
        }
        to_Int = static_cast<int>(to_Double);
        to_Float = static_cast<float>(to_Double);
        to_Char = (to_Int >= 32 && to_Int <= 126) ? static_cast<char>(to_Int) : '\0';
    }
    else{
        std::cout << "Invalid input: Not a recognizable scalar type." << std::endl;
        return;
    }

    // Affichage des résultats
    if (type == "char"){
        std::cout << "char: '" << to_Char << "'\n";
    }
    else if (to_Char == '\0'){
        std::cout << RED << "char: Non displayable" << RESET << std::endl;
    }
    else{
        // std::cout << "char: impossible\n";
        std::cout << "char: '" << to_Char << "'\n";
    }

    if (to_Float < std::numeric_limits<int>::min() || to_Float > std::numeric_limits<int>::max() || to_Double < std::numeric_limits<int>::min() || to_Double > std::numeric_limits<int>::max()){
        std::cerr << RED << "int: over or underflow" << RESET << std::endl;
    }
    else
        std::cout << "int: " << to_Int << std::endl;
    std::cout << "float: " << to_Float << (to_Float == static_cast<int>(to_Float) ? ".0f" : "f") << std::endl;
    std::cout << "double: " << to_Double << (to_Double == static_cast<int>(to_Double) ? ".0" : "") << std::endl;
}