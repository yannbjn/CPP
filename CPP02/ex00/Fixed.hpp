/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabejani <yabejani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:28:30 by yabejani          #+#    #+#             */
/*   Updated: 2024/09/18 14:52:32 by yabejani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <iomanip>

class Fixed
{
	private:
		int					_valueFixed;
		static int const	_nbBits;

	public:
		Fixed();				//canonical default constructor
		Fixed(Fixed const &src); //canonical	copy constructor
		~Fixed();
		Fixed	&operator=(Fixed const &rhs); //canonical = overload
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};
