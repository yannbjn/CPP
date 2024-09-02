/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabejani <yabejani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:48:47 by yabejani          #+#    #+#             */
/*   Updated: 2024/09/02 20:17:37 by yabejani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "contact.hpp"
#include "colors.hpp"

class Phonebook 
{
	private:
		Contact contacts[8];
		int contactindex;
		int contactcount;

	public:
		Phonebook();
		void addcontact();
		void searchcontacts() const;
		void displaycontact(int index) const;

};

#endif