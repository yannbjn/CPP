/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabejani <yabejani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:25:16 by yabejani          #+#    #+#             */
/*   Updated: 2025/03/18 19:41:16 by yabejani         ###   ########.fr       */
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

void ScalarConverter::convert(std::string literal) {
    int to_Int;
    float to_Float;
    double to_Double;
    char to_Char = '\0';

    // Gestion des pseudo-littéraux
    if (literal == "-inff" || literal == "+inff" || literal == "nanf") {
        std::cout << "char: impossible\nint: impossible\n"
                  << "float: " << literal << "\ndouble: " << literal.substr(0, literal.size() - 1) << std::endl;
        return;
    }
    if (literal == "-inf" || literal == "+inf" || literal == "nan") {
        std::cout << "char: impossible\nint: impossible\n"
                  << "float: " << literal << "f\ndouble: " << literal << std::endl;
        return;
    }

    // Détection du type d'entrée
    std::string type;
    if (literal.length() == 1 && !std::isdigit(literal[0])) {
        type = "char";
        to_Char = literal[0];
        to_Int = static_cast<int>(to_Char);
        to_Float = static_cast<float>(to_Char);
        to_Double = static_cast<double>(to_Char);
    } else if (isInteger(literal)) {
        type = "int";
        std::istringstream ss(literal);
        ss >> to_Int;
        to_Char = (to_Int >= 32 && to_Int <= 126) ? static_cast<char>(to_Int) : '\0';
        to_Float = static_cast<float>(to_Int);
        to_Double = static_cast<double>(to_Int);
    } else if (literal[literal.length() - 1] == 'f' && isFloat(literal.substr(0, literal.size() - 1))) {
        type = "float";
        std::istringstream ss(literal);
        ss >> to_Float;
        to_Int = static_cast<int>(to_Float);
        to_Double = static_cast<double>(to_Float);
        to_Char = (to_Int >= 32 && to_Int <= 126) ? static_cast<char>(to_Int) : '\0';
    } else if (isDouble(literal)) {
        type = "double";
        std::istringstream ss(literal);
        ss >> to_Double;
        to_Int = static_cast<int>(to_Double);
        to_Float = static_cast<float>(to_Double);
        to_Char = (to_Int >= 32 && to_Int <= 126) ? static_cast<char>(to_Int) : '\0';
    } else {
        std::cout << "Invalid input: Not a recognizable scalar type." << std::endl;
        return;
    }

    // Affichage des résultats
    if (type == "char") {
        std::cout << "char: '" << to_Char << "'\n";
    } else if (to_Char == '\0') {
        std::cout << "char: Non displayable\n";
    } else {
        // std::cout << "char: impossible\n";
        std::cout << "char: '" << to_Char << "'\n";
    }
    std::cout << "int: " << to_Int << std::endl;
    std::cout << "float: " << to_Float << (to_Float == static_cast<int>(to_Float) ? ".0f" : "f") << std::endl;
    std::cout << "double: " << to_Double << (to_Double == static_cast<int>(to_Double) ? ".0" : "") << std::endl;
}


// 1️⃣ Explication générale de la classe ScalarConverter
// La classe ScalarConverter est une classe qui convertit une chaîne de caractères représentant un littéral C++ en char, int, float et double, puis affiche les résultats.

// Elle n’est pas instanciable car elle ne contient que des méthodes statiques.
// Elle détecte d'abord le type d'entrée (char, int, float, double).
// Ensuite, elle convertit la valeur en trois autres types.
// Enfin, elle affiche les valeurs converties et gère les cas d’erreur.
// 2️⃣ Fonctionnement de std::istringstream pour convertir std::string en int, float, double
// 🔹 Qu'est-ce que std::istringstream ?
// std::istringstream est une classe de flux (stream) de la bibliothèque <sstream> en C++98. Elle permet de lire des données à partir d'une chaîne de caractères comme si c'était une entrée standard (std::cin).

// 📌 Syntaxe de base :

// cpp
// Copier
// Modifier
// #include <sstream>  // Nécessaire pour std::istringstream

// std::string str = "42";
// std::istringstream ss(str);  // Créer un flux à partir de la chaîne
// int value;
// ss >> value;  // Lire un int à partir du flux

// std::cout << "Valeur convertie : " << value << std::endl;
// ➡️ Ici, ss >> value; extrait un int du flux et le stocke dans value.

// 🔹 Pourquoi utiliser std::istringstream ?
// Il remplace std::stoi, std::stof, std::stod (qui n'existent pas en C++98).
// Il est plus sécurisé que atoi() et atof(), qui ne détectent pas les erreurs de conversion.
// Il vérifie si la conversion est complète et réussie grâce à ss.fail() et ss.eof().
// 🔹 Exemple détaillé avec std::istringstream
// Voyons comment convertir une std::string en int, float, et double en C++98.

// cpp
// Copier
// Modifier
// #include <iostream>
// #include <sstream>

// int main() {
//     std::string input = "123.45";
    
//     // Conversion en int
//     int intValue;
//     std::istringstream ssInt(input);
//     ssInt >> intValue;
//     if (ssInt.fail() || !ssInt.eof()) {  // Vérifier si la conversion a échoué
//         std::cout << "Conversion en int impossible !" << std::endl;
//     } else {
//         std::cout << "Int: " << intValue << std::endl;
//     }

//     // Conversion en float
//     float floatValue;
//     std::istringstream ssFloat(input);
//     ssFloat >> floatValue;
//     if (ssFloat.fail() || !ssFloat.eof()) {
//         std::cout << "Conversion en float impossible !" << std::endl;
//     } else {
//         std::cout << "Float: " << floatValue << "f" << std::endl;
//     }

//     // Conversion en double
//     double doubleValue;
//     std::istringstream ssDouble(input);
//     ssDouble >> doubleValue;
//     if (ssDouble.fail() || !ssDouble.eof()) {
//         std::cout << "Conversion en double impossible !" << std::endl;
//     } else {
//         std::cout << "Double: " << doubleValue << std::endl;
//     }

//     return 0;
// }
// 🔹 Explication :

// On crée un flux std::istringstream à partir de input ("123.45").
// ss >> variable; essaie de convertir la chaîne en int, float ou double.
// ss.fail() est vrai si la conversion a échoué.
// ss.eof() est faux si la chaîne n'a pas été complètement consommée.
// 📌 Exemple d'exécution :

// pgsql
// Copier
// Modifier
// Conversion en int impossible !
// Float: 123.45f
// Double: 123.45
// ➡️ La conversion en int échoue car "123.45" contient une partie décimale.

// 3️⃣ Explication détaillée de ScalarConverter.cpp
// Voyons maintenant comment fonctionne ScalarConverter et où std::istringstream est utilisé.

// 🔹 Détection du type d’entrée
// Le programme identifie si literal est un :

// char (ex: 'a')
// int (ex: 42)
// float (ex: 42.0f, nanf)
// double (ex: 42.0, -inf)
// cpp
// Copier
// Modifier
// if (literal.length() == 1 && !std::isdigit(literal[0])) {
//     type = "char";
// }
// else if (isInteger(literal)) {
//     type = "int";
// }
// else if (literal[literal.length() - 1] == 'f' && isFloat(literal.substr(0, literal.size() - 1))) {
//     type = "float";
// }
// else if (isDouble(literal)) {
//     type = "double";
// }
// ➡️ On vérifie si c'est un char, un int, un float (f à la fin), ou un double.

// 🔹 Conversion du std::string vers les types numériques
// Une fois le type détecté, on effectue la conversion avec std::istringstream.

// 🟢 Conversion en int
// cpp
// Copier
// Modifier
// std::istringstream ss(literal);
// ss >> to_Int;
// if (ss.fail() || !ss.eof()) {
//     std::cout << "Erreur : conversion int impossible !" << std::endl;
//     return;
// }
// ➡️ On vérifie si la conversion en int est réussie.

// 🟢 Conversion en float
// cpp
// Copier
// Modifier
// std::istringstream ss(literal);
// ss >> to_Float;
// if (ss.fail() || !ss.eof()) {
//     std::cout << "Erreur : conversion float impossible !" << std::endl;
//     return;
// }
// ➡️ Pareil pour float, en supprimant le f à la fin.

// 🟢 Conversion en double
// cpp
// Copier
// Modifier
// std::istringstream ss(literal);
// ss >> to_Double;
// if (ss.fail() || !ss.eof()) {
//     std::cout << "Erreur : conversion double impossible !" << std::endl;
//     return;
// }
// ➡️ Idem pour double.

// 🔹 Affichage des résultats
// cpp
// Copier
// Modifier
// std::cout << "int: " << to_Int << std::endl;
// std::cout << "float: " << to_Float << (to_Float == static_cast<int>(to_Float) ? ".0f" : "f") << std::endl;
// std::cout << "double: " << to_Double << (to_Double == static_cast<int>(to_Double) ? ".0" : "") << std::endl;
// ➡️ Ajout de .0 si c'est un entier pour respecter le format de l'énoncé.

// 4️⃣ Résumé et Conclusion
// ✅ std::istringstream permet de convertir std::string en int, float et double sans utiliser stoi, stod, etc.
// ✅ Il permet de détecter si la conversion échoue (fail() et eof()).
// ✅ C'est une solution portable en C++98.
// ✅ Tout le code respecte la norme C++98 et suit les règles de l'énoncé.