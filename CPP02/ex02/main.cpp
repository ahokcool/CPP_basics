/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:46:21 by astein            #+#    #+#             */
/*   Updated: 2024/03/29 23:29:03 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int	main( void )
{
	Fixed		a;
	Fixed const	b(Fixed(5.05f) * Fixed(2));
	
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	// More tests
	a = 42;
	std::cout << a << std::endl;
	a = a - 1;
	std::cout << a << std::endl;
	a = a + 1;
	std::cout << a << std::endl;
	a = a * 2;
	std::cout << a << std::endl;
	a = a / 2;
	std::cout << a << std::endl;
	
	// Comparison operators
	Fixed c(41);
	Fixed d(42);
	std::cout << "c = " << c << std::endl;
	std::cout << "d = " << d << std::endl;
	std::cout << "c > d: " << (c > d) << std::endl;
	std::cout << "c < d: " << (c < d) << std::endl;
	std::cout << "c >= d: " << (c >= d) << std::endl;
	std::cout << "c <= d: " << (c <= d) << std::endl;
	
	// Min and Max
	std::cout << "min(c, d) = " << Fixed::min(c, d) << std::endl;
	std::cout << "max(c, d) = " << Fixed::max(c, d) << std::endl;
	const Fixed e(41);
	const Fixed f(42);
	std::cout << "e = " << e << std::endl;
	std::cout << "f = " << f << std::endl;
	std::cout << "min(e, f) = " << Fixed::min(e, f) << std::endl;
	std::cout << "max(e, f) = " << Fixed::max(e, f) << std::endl;
	
	// ToInt and ToFloat
	Fixed g(12.3456789f);
	std::cout << "g = " << g << std::endl;
	std::cout << "g.toInt() = " << g.toInt() << std::endl;
	std::cout << "g.toFloat() = " << g.toFloat() << std::endl;
	
	return 0;
}
