/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabejani <yabejani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:19:04 by yabejani          #+#    #+#             */
/*   Updated: 2024/09/25 15:09:03 by yabejani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

//setters

void	Contact::setfirstname(std::string &firstname)
{
	this->_firstname = firstname;
}

void	Contact::setlastname(std::string &lastname)
{
	this->_lastname = lastname;
}

void	Contact::setnickname(std::string &nickname)
{
	this->_nickname = nickname;
}

void	Contact::setphonenumber(std::string &phonenumber)
{
	this->_phonenumber = phonenumber;
}

void	Contact::setdarkestsecret(std::string &darkestsecret)
{
	this->_darkestsecret = darkestsecret;
}



std::string Contact::getfirstname() const
{
    return this->_firstname;
}

std::string Contact::getlastname() const
{
	return this->_lastname;
}

std::string Contact::getnickname() const
{
	return this->_nickname;
}

std::string Contact::getphonenumber() const
{
	return this->_phonenumber;
}

std::string Contact::getdarkestsecret() const
{
	return this->_darkestsecret;
}
