/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 21:20:29 by astein            #+#    #+#             */
/*   Updated: 2024/03/29 23:37:57 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// Default constructor
Point::Point() : _x(0), _y(0)
{
	// Nothing to do here
}

// Parameterized constructor
Point::Point(const float x, const float y) : _x(x), _y(y)
{
	// Nothing to do here
}

// Copy constructor
Point::Point(const Point &other) : _x(other._x), _y(other._y)
{
	// Nothing to do here
}

// Destructor
Point::~Point()
{
	// Nothing to do here
}

// Member functions
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