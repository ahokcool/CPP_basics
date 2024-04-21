/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 18:27:16 by astein            #+#    #+#             */
/*   Updated: 2024/04/21 14:11:50 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include "Data.hpp"

// COLORS
# define CLR_RED "\033[31m"
# define CLR_GRN "\033[32m"
# define CLR_YLW "\033[33m"
# define CLR_BLU "\033[34m"
# define CLR_ORN "\033[38;5;202m"
# define CLR_BLD "\033[1m"
# define CLR_RST "\033[0m"

void	title(std::string str, bool newline_before, bool newline_after)
{
	if (newline_before)
		std::cout << std::endl;
	std::cout << CLR_ORN <<
		">>> " << str << " <<<" <<
		CLR_RST << std::endl;
	if (newline_after)
		std::cout << std::endl;
}

void	info(std::string str, std::string clr)
{
	std::cout <<
		clr <<
		" >> " << str <<
		CLR_RST << std::endl;
}


int	main( void )
{
	
	title("START: 42 EXAMPLE", true, false);
	int a = 2;
	int a2 = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	std::cout << "c = " << c << ", d = " << d << std::endl;
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	std::cout << "min( a, a2 ) = " << ::min( a, a2 ) << std::endl;
	std::cout << "max( a, a2 ) = " << ::max( a, a2 ) << std::endl;
	title("END: 42 EXAMPLE", false, true);

	title("START: MY EXAMPLE", true, false);
	info("TEST SWAP", CLR_GRN);
	std::cout << "a = " << a << ", b = " << b << std::endl;
	int x = 3000000;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "x = " << x << std::endl;
	::swap(a, x);
	std::cout << "x = " << x << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;

	info("TEST WITH STRINGS", CLR_GRN);
	std::string s1 ("Hello!");
	std::string s2 ("Helli!");
	std::string s3 ("Hell!");
	std::cout << "min( " << s1 << ", " << s2 << " ) = " << ::min( s1, s2 ) << std::endl;
	std::cout << "max( " << s1 << ", " << s2 << " ) = " << ::max( s1, s2 ) << std::endl;
	std::cout << "min( " << s1 << ", " << s3 << " ) = " << ::min( s1, s3 ) << std::endl;
	std::cout << "max( " << s1 << ", " << s3 << " ) = " << ::max( s1, s3 ) << std::endl;

	info("TEST WITH POINTER", CLR_GRN);
	std::string *p1 = &s1;
	std::string *p2 = &s2;
	std::string *p3 = &s3;
	std::cout << "min( " << *p1 << ", " << *p2 << " ) = " << *::min( p1, p2 ) << std::endl;
	std::cout << "max( " << *p1 << ", " << *p2 << " ) = " << *::max( p1, p2 ) << std::endl;
	std::cout << "min( " << *p1 << ", " << *p3 << " ) = " << *::min( p1, p3 ) << std::endl;
	std::cout << "max( " << *p1 << ", " << *p3 << " ) = " << *::max( p1, p3 ) << std::endl;
	::swap(c, d);
	std::cout << "min( " << *p1 << ", " << *p2 << " ) = " << *::min( p1, p2 ) << std::endl;
	std::cout << "max( " << *p1 << ", " << *p2 << " ) = " << *::max( p1, p2 ) << std::endl;
	std::cout << "min( " << *p1 << ", " << *p3 << " ) = " << *::min( p1, p3 ) << std::endl;
	std::cout << "max( " << *p1 << ", " << *p3 << " ) = " << *::max( p1, p3 ) << std::endl;
	title("END: MY EXAMPLE", false, true);
	{
		title("START: TEST WITH INSTANCES OF CLASS", true, false);
		Data d1("Alex", 42);
		Data d2("John1", 24);
		Data d3("John2", 24);
		d1.printData();
		d2.printData();
		info("TEST SWAP", CLR_GRN);
		::swap(d1, d2);
		d1.printData();
		d2.printData();
		info("TEST MIN", CLR_GRN);
		::min(d1, d2).printData();
		info("TEST MAX", CLR_GRN);
		::max(d1, d2).printData();
		info("TEST MIN/MAX with same values (should return the second argument!)", CLR_GRN);
		::swap(d1, d2);
		::min(d2, d3).printData();
		::max(d2, d3).printData();
		::min(d3, d2).printData();
		::max(d3, d2).printData();
	}
	return 0;
}