/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabejani <yabejani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:48:47 by yabejani          #+#    #+#             */
/*   Updated: 2024/09/25 15:07:21 by yabejani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include "colors.hpp"
#include "utils.hpp"

class PhoneBook 
{
	public:
		PhoneBook();
		~PhoneBook();
		void addcontact();
		void searchcontacts() const;
		void displaycontact(int index) const;
	private:
		Contact contacts[8];
		int _contactindex;
		int _contactcount;
};

#endif
