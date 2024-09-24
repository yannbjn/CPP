/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabejani <yabejani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 18:41:30 by yabejani          #+#    #+#             */
/*   Updated: 2024/09/24 20:06:51 by yabejani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Fixed.hpp"

class Point
{
	private:
		const Fixed _x;
		const Fixed _y;

	public:
		Point(); // canonical
		Point(const Point &src); // copy constructor (canonical)
		Point(const float x, const float y);
		~Point();

		Point &operator=(const Point& rhs); // overload = operator (canonical)

		const Fixed &getX(void) const;
		const Fixed &getY(void) const;
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);
std::ostream	&operator<<(std::ostream &o, Point const point);
