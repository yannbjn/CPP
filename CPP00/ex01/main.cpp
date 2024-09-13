/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabejani <yabejani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:50:23 by yabejani          #+#    #+#             */
/*   Updated: 2024/09/13 19:20:31 by yabejani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>

void menu() {
    std::cout << BOLD << BLUE << "+-----------------------------+" << RESET << std::endl;
    std::cout << BOLD << BLUE << "|          " << INVERSE << RED << "PHONEBOOK" << RESET << BOLD << BLUE << "          |" << RESET << std::endl;
    std::cout << BOLD << BLUE << "+-----------------------------+" << RESET << std::endl;
    std::cout << BOLD << BLUE << "| " << GREEN << "ADD" << RESET << BOLD << BLUE << "    = " << YELLOW << "Add a new contact" << RESET << BOLD << BLUE << "  |" << RESET << std::endl;
    std::cout << BOLD << BLUE << "| " << GREEN << "SEARCH" << RESET << BOLD << BLUE << " = " << YELLOW << "Search contacts" << RESET << BOLD << BLUE << "    |" << RESET << std::endl;
    std::cout << BOLD << BLUE << "| " << GREEN << "EXIT" << RESET << BOLD << BLUE << "   = " << YELLOW << "Exit the program" << RESET << BLUE << "   |" << RESET << std::endl;
    std::cout << BOLD << BLUE << "+-----------------------------+\n\n" << RESET << std::endl;
}

int main()
{
    PhoneBook PhoneBook;
    std::string command;

    //system("clear");
    menu();
    while (true)
    {
        if (std::cin.eof()){
            std::cout << std::endl;
            break ; 
        }
        std::cout << BOLD << BLUE << "Enter a command: " << RESET;
        std::getline(std::cin, command);
        if (command == "ADD"){
            PhoneBook.addcontact();
        }
        else if (command == "SEARCH"){
            PhoneBook.searchcontacts();
        }
        else if (command == "EXIT"){
            break;
        }
        else if (command == ""){
            std::cout << BOLD << RED << "You must enter a command." << RESET << std::endl;
        }
        else{
            std::cout << BOLD << RED << "Unknown command." << RESET << std::endl;
            menu();
        }
    }
    return 0;
}
