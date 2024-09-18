/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabejani <yabejani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 14:34:06 by yabejani          #+#    #+#             */
/*   Updated: 2024/09/18 15:30:26 by yabejani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_nbBits = 8;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Fixed::Fixed() : _valueFixed(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::Fixed(int const inttoFixed)
{
	std::cout << "Int constructor called" << std::endl;
	this->_valueFixed = inttoFixed * (1 << _nbBits);
}

Fixed::Fixed(float const floattoFixed)
{
	std::cout << "Float constructor called" << std::endl;
	this->_valueFixed = floattoFixed * (1 << _nbBits);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int	Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_valueFixed);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_valueFixed = raw;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int	Fixed::toInt() const
{
	return this->_valueFixed / (1 << _nbBits);
}

float	Fixed::toFloat() const
{
	return static_cast<float>(this->_valueFixed) / (1 << _nbBits);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Fixed	&Fixed::operator=(Fixed const &rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this-> _valueFixed = rhs.getRawBits();
	return (*this); //dereference pointeur this to return a reference
}

std::ostream &operator<<(std::ostream &o, Fixed const &rhs)
{
	o << rhs.toFloat();
	return o;
}
