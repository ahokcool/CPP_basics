/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 21:22:26 by astein            #+#    #+#             */
/*   Updated: 2024/03/29 23:18:22 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

// Set static const member
const int Fixed::_fractionalBits = 8;

// Constructors and destructor
// -----------------------------------------------------------------------------
Fixed::Fixed()
{
	_value = 0;
}

Fixed::Fixed(const int value)
{
	_value = value << _fractionalBits;
}

Fixed::Fixed(const float value)
{
	_value = roundf(value * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed &other)
{
	*this = other;
}

Fixed::~Fixed()
{
	// Nothing to do here
}

// Copy assignment operator
Fixed &Fixed::operator=(const Fixed &other)
{
	if (this != &other)
		_value = other.getRawBits();
	return *this;
}

// Basic arithmetic operator overloads
// -----------------------------------------------------------------------------
Fixed		Fixed::operator+(const Fixed &other) const
{
	Fixed result;
	result.setRawBits(this->getRawBits() + other.getRawBits());
	return result;
}

Fixed		Fixed::operator-(const Fixed &other) const
{
	Fixed result;
	result.setRawBits(this->getRawBits() - other.getRawBits());
	return result;	
}

Fixed		Fixed::operator*(const Fixed &other) const
{
	Fixed result;
	result.setRawBits((this->getRawBits() * other.getRawBits()) >> _fractionalBits);
	return result;
}

Fixed		Fixed::operator/(const Fixed &other) const
{
	Fixed result;
	result.setRawBits((this->getRawBits() << _fractionalBits) / other.getRawBits());
	return result;
}

// Increment and decrement operators overloads
// -----------------------------------------------------------------------------
Fixed		Fixed::operator++()
{
	this->setRawBits(this->getRawBits() + 1);
	return *this;
}

Fixed		Fixed::operator--()
{
	this->setRawBits(this->getRawBits() - 1);
	return *this;
}

Fixed		Fixed::operator++(int)
{
	Fixed temp(*this);
	this->setRawBits(this->getRawBits() + 1);
	return temp;
}

Fixed		Fixed::operator--(int)
{
	Fixed temp(*this);
	this->setRawBits(this->getRawBits() - 1);
	return temp;
}

// Comparison operators overloads
// -----------------------------------------------------------------------------
bool		Fixed::operator>(const Fixed &other) const
{
	return this->getRawBits() > other.getRawBits();
}

bool		Fixed::operator<(const Fixed &other) const
{
	return this->getRawBits() < other.getRawBits();
}

bool		Fixed::operator>=(const Fixed &other) const
{
	return this->getRawBits() >= other.getRawBits();
}

bool		Fixed::operator<=(const Fixed &other) const
{
	return this->getRawBits() <= other.getRawBits();
}

// Additional comparison operators overloads
// -----------------------------------------------------------------------------
Fixed		&Fixed::min(Fixed &a, Fixed &b)
{
	return a < b ? a : b;
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	return a < b ? a : b;
}

Fixed		&Fixed::max(Fixed &a, Fixed &b)
{
	return a > b ? a : b;
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	return a > b ? a : b;
}

// Getters and Setters
// -----------------------------------------------------------------------------
int Fixed::getRawBits() const
{
	return _value;
}

void Fixed::setRawBits(const int raw)
{
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
