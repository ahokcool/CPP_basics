/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 18:27:16 by astein            #+#    #+#             */
/*   Updated: 2024/04/19 18:49:37 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.tpp"

int	main( void )
{
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

	std::cout << "TEST SWAP" << std::endl;
	std::cout << "a = " << a << ", b = " << b << std::endl;
	int x = 3000000;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "x = " << x << std::endl;
	std::cout << "TEST SWAP" << std::endl;
	::swap(a, x);
	std::cout << "x = " << x << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;

	std::cout << "TEST WITH STRINGS" << std::endl;
	std::string s1 ("Hello!");
	std::string s2 ("Helli!");
	std::string s3 ("Hell!");
	std::cout << "min( " << s1 << ", " << s2 << " ) = " << ::min( s1, s2 ) << std::endl;
	std::cout << "max( " << s1 << ", " << s2 << " ) = " << ::max( s1, s2 ) << std::endl;
	std::cout << "min( " << s1 << ", " << s3 << " ) = " << ::min( s1, s3 ) << std::endl;
	std::cout << "max( " << s1 << ", " << s3 << " ) = " << ::max( s1, s3 ) << std::endl;

	std::cout << "TEST WITH POINTER" << std::endl;
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
	return 0;
}