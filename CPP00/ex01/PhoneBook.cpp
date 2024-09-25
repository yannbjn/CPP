/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabejani <yabejani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:54:08 by yabejani          #+#    #+#             */
/*   Updated: 2024/09/25 15:08:16 by yabejani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <limits>

PhoneBook::PhoneBook() : _contactindex(0), _contactcount(0){}

PhoneBook::~PhoneBook(){
    std::cout << BOLD << GREEN << "PhoneBook closed, bye bye." << RESET << std::endl;
}

void	PhoneBook::addcontact() 
{
    Contact newContact;
    std::string input = "";

    while (!std::cin.eof() && input == ""){
        std::cout << BOLD << GREEN << "Enter First Name: " << RESET;
        std::getline(std::cin, input);
        if (input == ""){
            std::cout << BOLD << RED << "First Name can't be empty" << std::endl << RESET;
        }
    }
    newContact.setfirstname(input);

    input = "";
    while (!std::cin.eof() && input == ""){
        std::cout << BOLD << GREEN << "Enter Last Name: " << RESET;
        std::getline(std::cin, input);
        if (input == ""){
            std::cout << BOLD << RED << "Last Name can't be empty" << std::endl << RESET;
        }
    }
    newContact.setlastname(input);

    
    input = "";
    while (!std::cin.eof() && input == ""){
        std::cout << BOLD << GREEN << "Enter Nickname: " << RESET;
        std::getline(std::cin, input);
        if (input == ""){
            std::cout << BOLD << RED << "Nickname can't be empty" << std::endl << RESET;
        }
    }
    newContact.setnickname(input);

    input = "";
    while (!std::cin.eof() && input == ""){
        std::cout << BOLD << GREEN << "Enter Phonenumber: " << RESET;
        std::getline(std::cin, input);
        if (input == ""){
            std::cout << BOLD << RED << "Phonenumber can't be empty" << std::endl << RESET;
        }
        while (!ft_isdigit(input)){
            std::cout << BOLD << RED << "Phonenumber can only contain numbers!" << std::endl << RESET;
            input = "";
            continue ;
        }
    }
    newContact.setphonenumber(input);

    input = "";
    while (!std::cin.eof() && input == ""){
        std::cout << BOLD << GREEN << "Enter Darkest Secret: " << RESET;
        std::getline(std::cin, input);
        if (input == ""){
            std::cout << BOLD << RED << "Darkest Secret can't be empty" << std::endl << RESET;
        }
    }
    newContact.setdarkestsecret(input);

    this->contacts[this->_contactindex] = newContact;
    this->_contactindex = (this->_contactindex + 1) % 8;
    if (this->_contactcount < 8)
        this->_contactcount++;
}

void	PhoneBook::searchcontacts() const
{
	if (this->_contactcount == 0)
	{
        std::cout << BOLD << RED << "PhoneBook is empty." << RESET << std::endl;
        return;
    }
    std::cout << BOLD << BLUE << "+----------+----------+----------+----------+" << std::endl;
    std::cout << "|" << std::setw(10) << "Index"
              << "|" << std::setw(10) << "First Name"
              << "|" << std::setw(10) << "Last Name"
              << "|" << std::setw(10) << "Nickname" << "|" << std::endl;
    std::cout << "+----------+----------+----------+----------+" << RESET << std::endl;

    for (int i = 0; i < this->_contactcount; i++)
	{
        std::cout << BOLD << BLUE << "|" << BOLD << GREEN << std::setw(10) << i << BOLD << BLUE << "|" << RESET;
        std::cout << YELLOW << std::setw(10) << (this->contacts[i].getfirstname().length() > 10 ? this->contacts[i].getfirstname().substr(0, 9) + "." : this->contacts[i].getfirstname()) << BOLD << BLUE << "|" << RESET;
        std::cout << YELLOW << std::setw(10) << (this->contacts[i].getlastname().length() > 10 ? this->contacts[i].getlastname().substr(0, 9) + "." : this->contacts[i].getlastname()) << BOLD << BLUE << "|" << RESET;
        std::cout << YELLOW << std::setw(10) << (this->contacts[i].getnickname().length() > 10 ? this->contacts[i].getnickname().substr(0, 9) + "." : this->contacts[i].getnickname()) << BOLD << BLUE << "|" << RESET << std::endl;
        std::cout << BOLD << BLUE << "+----------+----------+----------+----------+" << RESET << std::endl;
    }

    int flag = 0;
    while (!flag){
        int index;
        std::string test;
        std::cout << BOLD << BLUE << "Enter index to display details: " << RESET;
        std::cin >> test;
        index = stringToInt(test);
        if (std::cin.eof())
            break ;
        std::cin.ignore();
        if (!ft_isdigit(test)){
            std::cout << BOLD << RED << "Invalid index." << std::endl << RESET;
            continue ;
        }
        if (index < 0 || index >= this->_contactcount)
	    {
            std::cout << BOLD << RED << "Invalid index." << std::endl << RESET;
        }
	    else
	    {
            flag = 1;
            this->displaycontact(index);
        }
    }
}

void PhoneBook::displaycontact(int index) const
{
    std::cout << BOLD << BLUE << "First Name: " << YELLOW << this->contacts[index].getfirstname() << std::endl;
    std::cout << BOLD << BLUE << "Last Name: " << YELLOW << this->contacts[index].getlastname() << std::endl;
    std::cout << BOLD << BLUE << "Nickname: " << YELLOW << this->contacts[index].getnickname() << std::endl;
    std::cout << BOLD << BLUE << "Phone Number: " << YELLOW << this->contacts[index].getphonenumber() << std::endl;
    std::cout << BOLD << BLUE << "Darkest Secret: " << YELLOW << this->contacts[index].getdarkestsecret() << std::endl << RESET;
}
