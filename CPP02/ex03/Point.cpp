/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 21:20:29 by astein            #+#    #+#             */
/*   Updated: 2024/03/13 23:22:38 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0)
{
	// Nothing to do here
}

Point::Point(const float x, const float y) : _x(x), _y(y)
{
	// Nothing to do here
}

Point::Point(const Point &other) : _x(other._x), _y(other._y)
{
	// Nothing to do here
}

Point::~Point()
{
	// Nothing to do here
}

float	Point::get_x() const
{
	return _x.toFloat();
}

float	Point::get_y() const
{
	return _y.toFloat();
}

std::ostream 	&operator<<(std::ostream &os, const Point &point)
{
	os << "Point(" << point.get_x() << ", " << point.get_y() << ")";
	return os;
}