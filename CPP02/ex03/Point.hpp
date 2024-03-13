/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 21:20:26 by astein            #+#    #+#             */
/*   Updated: 2024/03/13 22:51:04 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP
# include "Fixed.hpp"

class Point
{

	public:
		Point();
		Point(const float x, const float y);
		Point(const Point &other);
		~Point();

		float	get_x() const;
		float	get_y() const;

	private:
		Fixed const _x;
		Fixed const _y;		
		
		// Copy assignment operator is private to prevent copy
		Point& operator=(const Point& other);
};

std::ostream 	&operator<<(std::ostream &os, const Point &point);

#endif