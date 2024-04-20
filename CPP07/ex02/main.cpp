/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 19:40:24 by astein            #+#    #+#             */
/*   Updated: 2024/04/20 20:43:32 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"
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

int main(int, char**)
{
	{
		title("START: Basic test with int array", true, false);
		Array<int> a;
		Array<int> b(42);
		std::cout << "SIZE of a: " << a.size() << std::endl;
		std::cout << "SIZE of b: " << b.size() << std::endl;
	
		try
		{
			std::cout << "VALUE of a[11]: ";
			std::cout << a[11] << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "Exception caught!" << std::endl;
		}
		std::cout << "VALUE of b[11]: " << b[11] << std::endl;

		info("Try to change value at index 11 in the array b...", CLR_GRN);
		b[11] = 11;
		std::cout << b[11] << std::endl;
		info("Try to set value at index 12 to value at index 11...", CLR_GRN);
		std::cout << b[11] << std::endl;
		std::cout << b[12] << std::endl;
		b[12] = b[11];
		std::cout << b[11] << std::endl;
		std::cout << b[12] << std::endl;

		info("Try equal constructor", CLR_GRN);
		Array<int> c(12); //So the equal operator has to delete the array of 12...
		c = b;
		std::cout << "VALUE of b[5]: " << b[5] << std::endl;
		std::cout << "VALUE of c[5]: " << c[5] << std::endl;
				
		std::cout << "VALUE of b[11]: " << b[11] << std::endl;
		std::cout << "VALUE of c[11]: " << c[11] << std::endl;
		
		std::cout << "VALUE of b[21]: " << b[21] << std::endl;
		std::cout << "VALUE of c[21]: " << c[21] << std::endl;

		info("Try copy constructor", CLR_GRN);
		Array<int> d(b);
		std::cout << "VALUE of b[5]: " << b[5] << std::endl;
		std::cout << "VALUE of d[5]: " << d[5] << std::endl;
		
		std::cout << "VALUE of b[11]: " << b[11] << std::endl;
		std::cout << "VALUE of d[11]: " << d[11] << std::endl;

		std::cout << "VALUE of b[21]: " << b[21] << std::endl;
		std::cout << "VALUE of d[21]: " << d[21] << std::endl;

		info("Change values in b to 42 - shouldn't affect c and d...", CLR_GRN);
		b[11] = 42;
		std::cout << "VALUE of b[11]: " << b[11] << std::endl;
		std::cout << "VALUE of c[11]: " << c[11] << std::endl;
		std::cout << "VALUE of d[11]: " << d[11] << std::endl;


		title("END: Basic test with int array", true, false);
	}

	{
		std::cout << "TEST WITH DATA CLASS" << std::endl;
		Array<Data> dArr1(5);
		info("Try copy constructor", CLR_GRN);
		Array<Data> dArr2(dArr1);
		info("Try equal constructor", CLR_GRN);
		Array<Data> dArr3 = dArr1;
		info("Change first instance of dArr1...", CLR_GRN);
		std::cout << "VALUE of dArr1[0]:\t";
		dArr1[0].printData();
		dArr1[0].setName("astein");
		info("Change name in dArr1[0] to astein - shouldn't affect dArr2[0] and dArr3[0]...", CLR_GRN);
		std::cout << "VALUE of dArr1[0]:\t";
		dArr1[0].printData();
		std::cout << "VALUE of dArr2[0]:\t";
		dArr2[0].printData();
		std::cout << "VALUE of dArr3[0]:\t";
		dArr3[0].printData();
		std::cout << std::endl;		
	}
}
