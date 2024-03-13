/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 21:21:02 by astein            #+#    #+#             */
/*   Updated: 2024/03/13 23:18:42 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// TRANSLATION
// DE		EN
// Eckpunkt	corner
// Kante	edge

static float crossProduct(const Point& corner1, const Point& corner2, const Point& point)
{
    return 	(corner2.get_x() - corner1.get_x()) * (point.get_y() - corner1.get_y()) - 
			(corner2.get_y() - corner1.get_y()) * (point.get_x() - corner1.get_x());
}

bool bsp(const Point a, const Point b, const Point c, const Point point)
{
    float cross_ab = crossProduct(a, b, point);
    float cross_bc = crossProduct(b, c, point);
    float cross_ca = crossProduct(c, a, point);

    if ((cross_ab > 0 && cross_bc > 0 && cross_ca > 0) || (cross_ab < 0 && cross_bc < 0 && cross_ca < 0))
        return true;
    return false;
}
