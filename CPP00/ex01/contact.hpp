/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabejani <yabejani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:48:41 by yabejani          #+#    #+#             */
/*   Updated: 2024/09/02 17:30:23 by yabejani         ###   ########.fr       */
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
	void setfirstname(const std::string &firstname);
	void setlastname(const std::string &lastname);
	void setnickname(const std::string &nickname);
	void setphonenumber(const std::string &phonenumber);
	void setdarkestsecret(const std::string &darkestsecret);

	std::string getfirstname() const;
	std::string getlastname() const;
	std::string getnickname() const;
	std::string getphonenumber() const;
	std::string getdarkestsecret() const;
};

#endif