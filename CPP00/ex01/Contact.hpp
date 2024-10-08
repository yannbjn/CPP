/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabejani <yabejani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:48:41 by yabejani          #+#    #+#             */
/*   Updated: 2024/09/25 15:07:09 by yabejani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{
  private:
	std::string _firstname;
	std::string _lastname;
	std::string _nickname;
	std::string _phonenumber;
	std::string _darkestsecret;

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
