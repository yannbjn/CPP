/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabejani <yabejani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:19:04 by yabejani          #+#    #+#             */
/*   Updated: 2024/09/10 19:44:04 by yabejani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

//setters

void	Contact::setfirstname(std::string &firstname)
{
	this->firstname = firstname;
}

void	Contact::setlastname(std::string &lastname)
{
	this->lastname = lastname;
}

void	Contact::setnickname(std::string &nickname)
{
	this->nickname = nickname;
}

void	Contact::setphonenumber(std::string &phonenumber)
{
	this->phonenumber = phonenumber;
}

void	Contact::setdarkestsecret(std::string &darkestsecret)
{
	this->darkestsecret = darkestsecret;
}



std::string Contact::getfirstname() const
{
    return this->firstname;
}

std::string Contact::getlastname() const
{
	return this->lastname;
}

std::string Contact::getnickname() const
{
	return this->nickname;
}

std::string Contact::getphonenumber() const
{
	return this->phonenumber;
}

std::string Contact::getdarkestsecret() const
{
	return this->darkestsecret;
}
