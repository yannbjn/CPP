/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frite <frite@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:28:30 by yabejani          #+#    #+#             */
/*   Updated: 2024/09/19 16:58:41 by frite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

class Fixed
{
	private:
		int					_valueFixed;
		static int const	_nbBits;

	public:
		Fixed();				 //canonical default constructor
		Fixed(Fixed const &src); //canonical	copy constructor
		Fixed(int const inttoFixed);
		Fixed(float const floattoFixed);
		~Fixed();
		Fixed	&operator=(Fixed const &rhs); //canonical = overload
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

		//comparison operator overload
		bool	operator>(Fixed const &rhs) const;
		bool	operator<(Fixed const &rhs) const;
		bool	operator>=(Fixed const &rhs) const;
		bool	operator<=(Fixed const &rhs) const;
		bool	operator==(Fixed const &rhs) const;
		bool	operator!=(Fixed const &rhs) const;

		//arithmetic operator overload
		Fixed operator+(Fixed const &rhs);
		Fixed operator-(Fixed const &rhs);
		Fixed operator*(Fixed const &rhs);
		Fixed operator/(Fixed const &rhs);

		//++ -- operator overload
		Fixed	&operator++(); //pre incr
		Fixed	&operator--(); //pre decr
		Fixed	operator++(int); //post incr
		Fixed	operator--(int); //post decr

		//
		static Fixed		&min(Fixed &n1, Fixed &n2);
		static Fixed const	&min(Fixed const &n1, Fixed const &n2);
		static Fixed		&max(Fixed &n1, Fixed &n2);
		static Fixed const	&max(Fixed const &n1, Fixed const &n2);

};

std::ostream	&operator<<(std::ostream &o, Fixed const &rhs);
