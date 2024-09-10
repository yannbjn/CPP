/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabejani <yabejani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:48:41 by yabejani          #+#    #+#             */
/*   Updated: 2024/09/10 15:44:19 by yabejani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{
  private:
	std::string firstname;
	std::string lastname;
	std::string nickname;
	std::string phonenumber;
	std::string darkestsecret;

  public:
	void setfirstname(std::string &firstname);
	void setlastname(std::string &lastname);
	void setnickname(std::string &nickname);
	void setphonenumber(std::string &phonenumber);
	void setdarkestsecret(std::string &darkestsecret);

	std::string getfirstname() const;
	std::string getlastname() const;
	std::string getnickname() const;
	std::string getphonenumber() const;
	std::string getdarkestsecret() const;
};

#endif