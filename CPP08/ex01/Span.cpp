/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:49:40 by astein            #+#    #+#             */
/*   Updated: 2024/04/23 18:53:41 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int N) : _N(N), _n(0), _shortestSpan(-1)
{

}

Span::~Span()
{

}


// Member functions
void	Span::addNumber(const int i)	throw (std::exception)
{
		
}

int 	Span::shortestSpan()			throw (std::exception)
{

}

int 	Span::longestSpan() 			throw (std::exception)
{

}


// private:
Span::Span()
{
	// Private - never called
}

Span::Span(const Span &other)
{
	(void)other;
	// Private - never called
}

Span &Span::operator=(const Span &other)
{
	// Private - never called
	(void) other;
	return *this;
}
