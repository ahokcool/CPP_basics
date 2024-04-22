/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 15:13:38 by astein            #+#    #+#             */
/*   Updated: 2024/04/22 16:34:50 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include "Data.hpp"

	// // COLORS
	// # define CLR_RED "\033[31m"
	// # define CLR_GRN "\033[32m"
	// # define CLR_YLW "\033[33m"
	// # define CLR_BLU "\033[34m"
	// # define CLR_ORN "\033[38;5;202m"
	// # define CLR_BLD "\033[1m"
	// # define CLR_RST "\033[0m"

	// void	title(std::string str, bool newline_before, bool newline_after)
	// {
	// 	if (newline_before)
	// 		std::cout << std::endl;
	// 	std::cout << CLR_ORN <<
	// 		">>> " << str << " <<<" <<
	// 		CLR_RST << std::endl;
	// 	if (newline_after)
	// 		std::cout << std::endl;
	// }

	// void	info(std::string str, std::string clr)
	// {
	// 	std::cout <<
	// 		clr <<
	// 		" >> " << str <<
	// 		CLR_RST << std::endl;
	// }

	// // Test for calling a function on each Data instance
	// void printData(Data& d) {
	// 	d.printData();
	// }

	// int	main()
	// {
	// 	info("Test with integer array", CLR_GRN);
	// 	int ia[] = {1,2,4,6,8};
	// 	size_t len = sizeof(ia) / sizeof(ia[0]);
	// 	::iter(ia, len, ::put);	
	// 	::iter(ia, len, ::add42);	
	// 	std::cout << std::endl << "Added 42 to each element:" << std::endl;
	// 	::iter(ia, len, ::put);	

	// 	info("Test with string array", CLR_GRN);
	// 	std::string sa[] = {"Hello", "World!", "Hello", "42"};
	// 	len = sizeof(sa) / sizeof(sa[0]);
	// 	::iter(sa, len, ::put);	
	// 	::iter(sa, len, ::add42);	
	// 	std::cout << std::endl << "Added 42 to each element:" << std::endl;
	// 	::iter(sa, len, ::put);	

	// 	info("Test with float array", CLR_GRN);
	// 	float fa[] = {0.42f, 0.0001f, 42.42f};
	// 	len = sizeof(fa) / sizeof(fa[0]);
	// 	::iter(fa, len, ::put);
	// 	::iter(fa, len, ::add42);	
	// 	std::cout << std::endl << "Added 42 to each element:" << std::endl;
	// 	::iter(fa, len, ::put);

	// 	info("Test with Data Instances", CLR_GRN);
	// 	Data da[] = {Data("Alexander", 1), Data("astein", 2), Data("FooBar", 3)};
	// 	len = sizeof(da) / sizeof(da[0]);
	// 	::iter(da, len, printData);

	// 	return 0;
	// }

// 42 Main doesnt work somehow...
class Awesome
{
  public:
    Awesome( void ) : _n( 42 ) { return; }
    int get( void ) const { return this->_n; }
  private:
    int _n;
};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs )
{
  o << rhs.get();
  return o;
}

template< typename T >
void print( T& x )
{
  std::cout << x << std::endl;
  return;
}

int main() {
  int tab[] = { 0, 1, 2, 3, 4 };
  Awesome tab2[5];

  iter( tab, 5, print<const int> );
  iter( tab2, 5, print<Awesome> );

  return 0;
}

