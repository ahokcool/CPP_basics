/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 21:20:55 by astein            #+#    #+#             */
/*   Updated: 2024/03/13 23:26:14 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

bool bsp(const Point a, const Point b, const Point c, const Point point);

// Draw the triangle and the point in the following link:
// https://www.geogebra.org/graphing?lang=de

int	main()
{
	
	Point a(1.0f, 1.0f);
	Point b(4.0f, 1.0f);
	Point c(1.0f, 4.0f);
	Point p1(1.03125f, 1.1f);	// Inside the triangle
	Point p2(5.0f, 5.0f);	// Outside the triangle
	Point p3(1.0f, 3.0f);	// On the edge of the triangle
	Point p4(1.0f, 1.0f);	// On the vertex of the triangle
	Point a2(1.0f, 2.0f);
	Point a3(1.0f, 3.0f);
	Point p5(1.0f, 15.0f);

	if (bsp(a, b, c, p1))
		std::cout << "|X| The point " << p1 << " is inside the triangle" << std::endl;
	else
		std::cout << "|O| The point " << p1 << " is outside the triangle" << std::endl;

	if (bsp(a, b, c, p2))
		std::cout << "|X| The point " << p2 << " is inside the triangle" << std::endl;
	else
		std::cout << "|O| The point " << p2 << " is outside the triangle" << std::endl;

	if (bsp(a, b, c, p3))
		std::cout << "|X| The point " << p3 << " is inside the triangle" << std::endl;
	else
		std::cout << "|O| The point " << p3 << " is outside the triangle" << std::endl;
	
	if (bsp(a, b, c, p4))
		std::cout << "|X| The point " << p4 << " is inside the triangle" << std::endl;
	else
		std::cout << "|O| The point " << p4 << " is outside the triangle" << std::endl;

	// Strange Triangle 1
	if (bsp(a, a, a, p1))
		std::cout << "|X| The point " << p1 << " is inside the 1. STRANGE triangle" << std::endl;
	else
		std::cout << "|O| The point " << p1 << " is outside the 1. STRANGE triangle" << std::endl;

	// Strange Triangle 2
	if (bsp(a, a2, a3, p1))
		std::cout << "|X| The point " << p1 << " is inside the 2. STRANGE triangle" << std::endl;
	else
		std::cout << "|O| The point " << p1 << " is outside the 2. STRANGE triangle" << std::endl;
	
	if (bsp(a, a2, a3, p5))
		std::cout << "|X| The point " << p5 << " is inside the 2. STRANGE triangle" << std::endl;
	else
		std::cout << "|O| The point " << p5 << " is outside the 2. STRANGE triangle" << std::endl;
	
	return 0;
}
