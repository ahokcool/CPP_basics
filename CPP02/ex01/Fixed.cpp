/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 21:22:26 by astein            #+#    #+#             */
/*   Updated: 2024/03/13 16:42:56 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

// Set static const member
const int Fixed::_fractionalBits = 8;

// Constructor
Fixed::Fixed()
{
	_value = 0;
	std::cout << "Default constructor called" << std::endl;
}

// Constructor with int
Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	_value = value << _fractionalBits;
}

// Constructor with float
Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	_value = roundf(value * (1 << _fractionalBits));
}

// Copy constructor
Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

// Copy assignment operator
Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	_value = other.getRawBits();
	return *this;
}

// Destructor
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return _value;
}

void Fixed::setRawBits(const int raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	_value = raw;
}

float	Fixed::toFloat() const
{
	return (float)_value / (1 << _fractionalBits);
}

int		Fixed::toInt() const
{
	return _value >> _fractionalBits;
}

std::ostream 	&operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return os;
}
