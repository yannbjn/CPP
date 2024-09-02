/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabejani <yabejani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:50:23 by yabejani          #+#    #+#             */
/*   Updated: 2024/09/02 19:28:02 by yabejani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
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
    Phonebook phonebook;
    std::string command;

    system("clear");
    menu();
    while (true)
    {
        std::cout << BOLD << BLUE << "Enter a command: " << MAGENTA;
        std::getline(std::cin, command);

        if (command == "ADD")
        {
            phonebook.addcontact();
        }
        else if (command == "SEARCH")
        {
            phonebook.searchcontacts();
        }
        else if (command == "EXIT")
        {
            break;
        }
        else
        {
            std::cout << BOLD << RED << "Unknown command." << RESET << std::endl;
        }
    }
    return 0;
}
