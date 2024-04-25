/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:49:40 by astein            #+#    #+#             */
/*   Updated: 2024/04/25 15:26:49 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int N) : _N(N)
{
	// Nothing to do here
}

Span::Span(const Span &other) : _N(other._N), _v(other._v)
{
	// Nothing to do here
}

Span::~Span()
{
	// Nothing to do here
}

// Member functions
void	Span::addNumber(const int i)	throw (std::overflow_error)
{
	if (_v.size() >= _N)
		throw std::overflow_error("Span is full.");
	_v.push_back(i);
}

// THE BIGGEST POSSIBLE SPAN (between int min and int max)
// 	-> FITS IN UNSIGNED INT
unsigned int	Span::shortestSpan()			throw (std::invalid_argument)
{
	if (_v.size() < 2)
		throw std::invalid_argument("Need at least 2 numbers to calculate shortest span.");
	std::sort(_v.begin(), _v.end());
	unsigned int min = static_cast<unsigned int>(_v[1]) - static_cast<unsigned int>(_v[0]);
	for (std::vector<int>::iterator it = _v.begin(); it != _v.end() - 1; it++)
	{
		unsigned int diff = static_cast<unsigned int>(*(it + 1)) - static_cast<unsigned int>(*it);
		if (diff == 0)
			return (0);
		if (diff < min)
			min = diff;
	}
	return min;
}

// THE BIGGEST POSSIBLE SPAN (between int min and int max)
// 	-> FITS IN UNSIGNED INT
unsigned int 	Span::longestSpan() 			throw (std::invalid_argument)
{
	if (_v.size() < 2)
		throw std::invalid_argument("Need at least 2 numbers to calculate longest span.");

	std::sort(_v.begin(), _v.end());
	return static_cast<unsigned int>(_v.back()) - static_cast<unsigned int>(_v.front());
}

void	Span::print() const
{
	std::cout << "Span of size " << _N << " with " << _v.size() << " numbers:" << std::endl;
	for (std::vector<int>::const_iterator it = _v.begin(); it != _v.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void	Span::addRange(const std::vector<int>::iterator &begin, const std::vector<int>::iterator &end) throw (std::overflow_error)
{
	if (_v.size() + std::distance(begin, end) > _N)
		throw std::overflow_error("Can't add range; span would overflow.");
	_v.insert(_v.end(), begin, end);
}

// private:
Span::Span() : _N(0)
{
	// Private - never called
}

Span &Span::operator=(const Span &other)
{
	// Private - never called
	// Since N is const, we can't change it!
	(void) other;
	return *this;
}