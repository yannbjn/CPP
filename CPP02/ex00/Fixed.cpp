/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabejani <yabejani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 14:34:06 by yabejani          #+#    #+#             */
/*   Updated: 2024/09/18 14:56:38 by yabejani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_nbBits = 8;

Fixed::Fixed() : _valueFixed(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int		Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_valueFixed);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_valueFixed = raw;
}

Fixed	&Fixed::operator=(Fixed const &rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this-> _valueFixed = rhs.getRawBits();
	return (*this); //dereference pointeur this to return a reference
}
