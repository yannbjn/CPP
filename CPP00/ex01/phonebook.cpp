/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabejani <yabejani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:54:08 by yabejani          #+#    #+#             */
/*   Updated: 2024/09/02 20:17:52 by yabejani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include <iostream>
#include <iomanip>

Phonebook::Phonebook() : contactindex(0), contactcount(0){}


void	Phonebook::addcontact() 
{
    Contact newContact;
    std::string input;

    std::cout << BOLD << YELLOW << "Enter First Name: " << RESET << MAGENTA;
    std::getline(std::cin, input);
    newContact.setfirstname(input);

    std::cout << BOLD << YELLOW << "Enter Last Name: " << RESET << MAGENTA;
    std::getline(std::cin, input);
    newContact.setlastname(input);

    std::cout << BOLD << YELLOW << "Enter Nickname: " << RESET << MAGENTA;
    std::getline(std::cin, input);
    newContact.setnickname(input);

    std::cout << BOLD << YELLOW << "Enter Phone Number: " << RESET << MAGENTA;
    std::getline(std::cin, input);
    newContact.setphonenumber(input);

    std::cout << BOLD << YELLOW << "Enter Darkest Secret: " << RESET << MAGENTA;
    std::getline(std::cin, input);
    newContact.setdarkestsecret(input);

    this->contacts[this->contactindex] = newContact;
    this->contactindex = (this->contactindex + 1) % 8;
    if (this->contactcount < 8)
        this->contactcount++;
}

void	Phonebook::searchcontacts() const
{
	if (this->contactcount == 0)
	{
        std::cout << "\033[1;31mPhoneBook is empty.\033[0m" << std::endl;
        return;
    }

    std::cout << std::setw(10) << "Index" << " | ";
    std::cout << std::setw(10) << "First Name" << " |";
    std::cout << std::setw(10) << "Last Name" << " |";
    std::cout << std::setw(10) << "Nickname" << std::endl;

    for (int i = 0; i < this->contactcount; i++)
	{
        std::cout << std::setw(10) << i << "|";
        std::cout << std::setw(10) << (this->contacts[i].getfirstname().length() > 10 ? this->contacts[i].getfirstname().substr(0, 9) + "." : this->contacts[i].getfirstname()) << "|";
        std::cout << std::setw(10) << (this->contacts[i].getlastname().length() > 10 ? this->contacts[i].getlastname().substr(0, 9) + "." : this->contacts[i].getlastname()) << "|";
        std::cout << std::setw(10) << (this->contacts[i].getnickname().length() > 10 ? this->contacts[i].getnickname().substr(0, 9) + "." : this->contacts[i].getnickname()) << std::endl;
    }

    int index;
    std::cout << "Enter index to display details: ";
    std::cin >> index;
    std::cin.ignore();// Ignore leftover newline in the input buffer

    if (index < 0 || index >= this->contactcount)
	{
        std::cout << "\033[1;31mInvalid index.\033[0m" << std::endl;
    }
	else
	{
        this->displaycontact(index);
    }
}

std::string truncateString(const std::string &text, std::size_t width)
{
    if (text.length() > width)
	{
        return text.substr(0, width - 1) + '.';
    }
    return text;
}

// void Phonebook::displaycontact() const
// {
//     std::cout << BOLD << BLUE << "+-------+------------+------------+------------+" << std::endl;
//     std::cout << "| " << BLUE << std::setw(2) << "Index" << RESET
//               << " | " << BLUE << std::setw(10) << "First Name" << RESET
//               << " | " << BLUE << std::setw(10) << "Last Name" << RESET
//               << " | " << BLUE << std::setw(10) << "Nickname" << RESET << " |" << std::endl;
//     std::cout << "+-------+------------+------------+------------+" << std::endl;

// 	for (int i = 0; i < 8; ++i)
// 	{
// 		if (!contacts[i].getfirstname().empty()) {
// 			std::cout << "| " << std::setw(5) << i + 1 << " | "
// 						<< std::setw(10) << truncateString(contacts[i].getfirstname(), 10) << " | "
// 						<< std::setw(10) << truncateString(contacts[i].getlastname(), 10) << " | "
// 						<< std::setw(10) << truncateString(contacts[i].getnickname(), 10) << " |" << std::endl;
// 		}
//     }

//         std::cout << "+-------+------------+------------+------------+" << std::endl;
// }

void Phonebook::displaycontact(int index) const
{
    std::cout << "First Name: " << this->contacts[index].getfirstname() << std::endl;
    std::cout << "Last Name: " << this->contacts[index].getlastname() << std::endl;
    std::cout << "Nickname: " << this->contacts[index].getnickname() << std::endl;
    std::cout << "Phone Number: " << this->contacts[index].getphonenumber() << std::endl;
    std::cout << "Darkest Secret: " << this->contacts[index].getdarkestsecret() << std::endl;
}
