/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabejani <yabejani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 19:49:35 by yabejani          #+#    #+#             */
/*   Updated: 2024/09/24 20:10:36 by yabejani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static float getArea(const Point p1, const Point p2, const Point p3){
	return (
		   ( p1.getX().toFloat() * ( p2.getY().toFloat() - p3.getY().toFloat() ) )
		   + ( p2.getX().toFloat() * ( p3.getY().toFloat() - p1.getY().toFloat() ) )
		   + ( p3.getX().toFloat() * ( p1.getY().toFloat() - p2.getY().toFloat() ) )
		   )
		   / 2;
}


bool	bsp(Point const a, Point const b, Point const c, Point const point){
	float a0, a1, a2, a3;

	a0 = getArea(a, b, c);
	if (a0 < 0)
		a0 *= -1;
	a1 = getArea(a, b, point);
	if (a1 < 0)
		a1 *= -1;
	a2 = getArea(a, c, point);
	if (a2 < 0)
		a2 *= -1;
	a3 = getArea(b, c, point);
	if (a3 < 0)
		a3 *= -1;

	if (a1 == 0 || a2 == 0 || a3 == 0)
		return (false);
	if (a0 == a1 + a2 + a3)
		return (true);
	else
		return (false);
}
