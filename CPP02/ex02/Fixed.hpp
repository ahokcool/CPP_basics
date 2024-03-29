/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 21:22:36 by astein            #+#    #+#             */
/*   Updated: 2024/03/29 23:35:16 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	public:
		// Constructors and destructor
		Fixed();
		Fixed(const Fixed &other);
		Fixed(const int value);
		Fixed(const float value);
		~Fixed();

		// Copy assignment operator
		Fixed 		&operator=(const Fixed &other);
		
		// Basic arithmetic operator overloads
		Fixed		operator+(const Fixed &other) const;
		Fixed		operator-(const Fixed &other) const;
		Fixed		operator*(const Fixed &other) const;
		Fixed		operator/(const Fixed &other) const;

		// Increment and decrement operators overloads
		Fixed		operator++();		// prefix
		Fixed		operator--();		// prefix
		Fixed		operator++(int);	// int is a dummy parameter to differentiate from the prefix version
		Fixed		operator--(int);	// int is a dummy parameter to differentiate from the prefix version
		
		// Comparison operators overloads
		bool		operator>(const Fixed &other) const;
		bool		operator<(const Fixed &other) const;
		bool		operator>=(const Fixed &other) const;
		bool		operator<=(const Fixed &other) const;
		
		// Additional comparison operators overloads
		static Fixed		&min(Fixed &a, Fixed &b);
		static const Fixed	&min(const Fixed &a, const Fixed &b);
		static Fixed		&max(Fixed &a, Fixed &b);
		static const Fixed	&max(const Fixed &a, const Fixed &b);
		
		// Getters and Setters
		int						getRawBits() const;
		void					setRawBits(const int raw);
		float					toFloat() const;
		int						toInt() const;
		
	private:
		int					_value;
		static const int	_fractionalBits;
};

	std::ostream 	&operator<<(std::ostream &os, const Fixed &fixed);
#endif