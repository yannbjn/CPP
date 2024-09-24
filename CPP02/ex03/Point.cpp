/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabejani <yabejani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 19:03:17 by yabejani          #+#    #+#             */
/*   Updated: 2024/09/24 20:10:22 by yabejani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

//////////

Point::Point() : _x(0), _y(0){
	std::cout << "Point: Default constructor called." << std::endl;
}

Point::Point(const Point &src) : _x(src.getX()), _y(src.getY()){
	std::cout << "Point: Copy constructor called." << std::endl;
}

Point::Point(const float x, const float y) : _x(x), _y(y){
	std::cout << "Point: Constructor called." << std::endl;
}

Point::~Point(){
	std::cout << "Point: Default Destructor called." << std::endl;
}

//////////

Point &Point::operator=(const Point &src)
{
	// std::cout << "Point Assignation operator called" << std::endl;
	if (this == &src)
		return *this;

	/*CODE*/
	return *this;
}

//////////

const Fixed &Point::getX(void) const{
	return this->_x;
}

const Fixed &Point::getY(void) const{
	return this->_y;
}

//////////

std::ostream	&operator<<(std::ostream &o, Point const point){
	o << "_x: " << point.getX() << " / _y: " << point.getY() << std::endl;
	return (o);
}
