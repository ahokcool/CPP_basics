/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 09:33:02 by astein            #+#    #+#             */
/*   Updated: 2024/04/18 12:38:14 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <limits>
#include <sstream>
#include "ScalarConverter.hpp"

// COLORS -  I also have them in the ScalarConverter.hpp file but to be able to
// use my main in evaluations I need to define them here as well
# define CLR_RED "\033[31m"
# define CLR_GRN "\033[32m"
# define CLR_YLW "\033[33m"
# define CLR_BLU "\033[34m"
# define CLR_ORN "\033[38;5;202m"
# define CLR_BLD "\033[1m"
# define CLR_RST "\033[0m"

// Prints a simple title to the console
void	title(const std::string &str, bool newline_before, bool newline_after)
{
	if (newline_before)
		std::cout << std::endl;
	std::cout << CLR_ORN <<
		">>> " << str << " <<<" <<
		CLR_RST << std::endl;
	if (newline_after)
		std::cout << std::endl;
}

// Prints a simple info to the console
void	info(const std::string &str,const std::string &clr)
{
	std::cout <<
		clr <<
		" >> " << str <<
		CLR_RST << std::endl;
}

// Prints a simple banner and waits for return key
void	wait_banner(const std::string &str,const std::string &clr)
{
	title("------------------------------------", true, false);
	info(str, clr);
	title("------------------------------------", false, true);
	std::cin.get();	
}

void test_42()
{
	title("SCALAR CONVERTER SUBJECT TESTS START", true, false);
	info ("Test: ./convert 0", CLR_BLU);
	ScalarConverter::convert("0");
	info ("Expected:", CLR_GRN);
	info ("\tchar:\tnon displayable", CLR_GRN);
	info ("\tint:\t0", CLR_GRN);
	info ("\tfloat:\t0.0f", CLR_GRN);
	info ("\tdouble:\t0.0", CLR_GRN);
	info ("\t--------------", CLR_BLU);
	
	info ("Test: ./convert nan", CLR_BLU);
	ScalarConverter::convert("nan");
	info ("\tchar:\timpossible", CLR_GRN);
	info ("\tint:\timpossible", CLR_GRN);
	info ("\tfloat:\tnanf", CLR_GRN);
	info ("\tdouble:\tnan", CLR_GRN);
	info ("\t--------------", CLR_BLU);

	info ("Test: ./convert 42.0f", CLR_BLU);
	ScalarConverter::convert("42.0f");
	info ("\tchar:\t'*'", CLR_GRN);
	info ("\tint:\t42", CLR_GRN);
	info ("\tfloat:\t42.0f", CLR_GRN);
	info ("\tdouble:\t42.0", CLR_GRN);
	info ("\t--------------", CLR_BLU);

	title("SCALAR CONVERTER SUBJECT TESTS END", false, true);
	std::cin.get();
}

// All my tests
void 	myTests()
{
	test_42();

	title("SCALAR CONVERTER MY TESTS START", true, false);
	info("Creating a ScalarConverter object doesn't work!", CLR_RED);
	// ScalarConverter sc;
	
	
	// TEST CHARS
	{
		wait_banner("TESTING VALID CHARS:", CLR_GRN);
		ScalarConverter::convert("F");	
		ScalarConverter::convert("M");	
		ScalarConverter::convert("L");	
		ScalarConverter::convert("!");
		ScalarConverter::convert("L");
		ScalarConverter::convert("O");
		ScalarConverter::convert("L");
		ScalarConverter::convert("+");
		ScalarConverter::convert("-");
		ScalarConverter::convert(".");
		ScalarConverter::convert(",");

		wait_banner("TESTING INVALID CHARS:", CLR_RED);
		ScalarConverter::convert(std::string (1, char(1)));
		ScalarConverter::convert(std::string (1, char(2)));
		ScalarConverter::convert(std::string (1, char(3)));
		ScalarConverter::convert(std::string (1, char(17)));
		ScalarConverter::convert(std::string (1, char(18)));
		ScalarConverter::convert(std::string (1, char(19)));
	}

	// TEST INTS
	{
		wait_banner("TESTING VALID INTS:", CLR_GRN);
		// Creating the min and max int strings
		std::stringstream ss;
		ss << std::numeric_limits<int>::min();
		std::string minIntString = ss.str();
		ss.str("");       // Clears the content
		ss.clear();       // Clears any error flags
		ss << std::numeric_limits<int>::max();
		std::string maxIntString = ss.str();
		
		ScalarConverter::convert(minIntString);
		ScalarConverter::convert("-1234");
		ScalarConverter::convert("-42");
		ScalarConverter::convert("0");
		ScalarConverter::convert("00000");
		ScalarConverter::convert("+00000");
		ScalarConverter::convert("42");
		ScalarConverter::convert("+1234");
		ScalarConverter::convert(maxIntString);
		
		wait_banner("TESTING INVALID INTS:", CLR_RED);
		ScalarConverter::convert("--42");
		ScalarConverter::convert("++42");
		ScalarConverter::convert("123456789123456789");
		ScalarConverter::convert("-123456789123456789");
	}

	// TEST FLOATS
	{
		wait_banner("TESTING VALID FLOATS:", CLR_GRN);
		
		// Creating the min and max int strings
		std::stringstream ss;
		ss << std::fixed << -std::numeric_limits<float>::max();
    	std::string minFloatString = ss.str();
    	ss.str("");
    	ss.clear();
    	ss << std::fixed << std::numeric_limits<float>::max();
    	std::string maxFloatString = ss.str();
		std::cout << "minFloatString: " << minFloatString << std::endl;
		std::cout << "maxFloatString: " << maxFloatString << std::endl;

		
		ScalarConverter::convert("-inff");
		ScalarConverter::convert(minFloatString);
		ScalarConverter::convert("-1234.1234f");
		ScalarConverter::convert("-42.42f");
		ScalarConverter::convert("-0.0f");
		ScalarConverter::convert("0.0f");
		ScalarConverter::convert("+0.0f");
		ScalarConverter::convert("42.42f");
		ScalarConverter::convert("+1234.1234f");
		ScalarConverter::convert(maxFloatString);
		ScalarConverter::convert("+inff");
		ScalarConverter::convert("nanf");

		wait_banner("TESTING INVALID FLOATS:", CLR_RED);
		ScalarConverter::convert("--42.42f");
		ScalarConverter::convert("++42.42f");
		ScalarConverter::convert("123.123ff");
		ScalarConverter::convert("123.123.123f");
		ScalarConverter::convert("10000000000000000000000000000000000000000");
		ScalarConverter::convert("-10000000000000000000000000000000000000000");
	}
	
// TEST DOUBLES
	{
		wait_banner("TESTING VALID DOUBLES:", CLR_GRN);
		// Creating the min and max int strings
		std::stringstream ss;
		 ss << std::fixed << -std::numeric_limits<double>::max();
    	std::string minDoubleString = ss.str();
    	ss.str("");
    	ss.clear();
    	ss << std::fixed << std::numeric_limits<double>::max();
    	std::string maxDoubleString = ss.str();
		std::cout << "minDoubleString: " << minDoubleString << std::endl;
		std::cout << "maxDoubleString: " << maxDoubleString << std::endl;

		ScalarConverter::convert("-inf");
		ScalarConverter::convert(minDoubleString);
		ScalarConverter::convert("-1234.1234");
		ScalarConverter::convert("-42.42");
		ScalarConverter::convert("-0.0");
		ScalarConverter::convert("0.0");
		ScalarConverter::convert("+0.0");
		ScalarConverter::convert("42.42");
		ScalarConverter::convert("+1234.1234");
		ScalarConverter::convert(maxDoubleString);
		ScalarConverter::convert("+inf");
		ScalarConverter::convert("nan");

		wait_banner("TESTING INVALID DOUBLES:", CLR_RED);
		ScalarConverter::convert("--42.42");
		ScalarConverter::convert("++42.42");
		ScalarConverter::convert("123.123.123");
		ScalarConverter::convert("90000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000");
		ScalarConverter::convert("-90000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000");
	}
	
// TEST STRINGS
	{
		wait_banner("TESTING RANDOM INVALID STRINGS:", CLR_RED);
		ScalarConverter::convert("\0");
		// The following doesn't work because it's a NULL pointer
		// and the function is expecting a string reference
		// which can't be NULL!
		// std::string *str = NULL;
		// ScalarConverter::convert(*str);
		ScalarConverter::convert("Hello");
		ScalarConverter::convert("World");
		ScalarConverter::convert("42 is the answer");
		ScalarConverter::convert("42.42 is the answer");
		ScalarConverter::convert("++");
		ScalarConverter::convert("--");
		ScalarConverter::convert("+-");
		ScalarConverter::convert("-+");
		ScalarConverter::convert(".0");
		ScalarConverter::convert("0.");
		ScalarConverter::convert("0.0.0");
		ScalarConverter::convert("nand");
		ScalarConverter::convert("infff");
	}
	title("SCALAR CONVERTER MY TESTS END", false, true);
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		title("SCALAR CONVERTER", true, false);
		info("Usage: ./scalar_converter <string>", CLR_RED);
		info("----------------------------------", CLR_RED);
		info("Now starting tests....", CLR_BLU);
		myTests();
	}
	else
	{
		title("SCALAR CONVERTER", true, false);
		// Check if the string is empty aka NULL
		// This is NOT neccessary because C++ ensures that argv[1] is never NULL
		if (argv[1] == NULL)
		{
			info("SPECIAL CASE NULL", CLR_BLU);
			std::cout <<
				"\tchar: non displayable" << std::endl <<
				"\tint: 0" << std::endl <<
				"\tfloat: 0.0f" << std::endl <<
				"\tdouble: 0.0" << std::endl;
			return 0;
		}
		// Safe conversion from char* to std::string (since it can't be NULL)
		const std::string str = argv[1];
		ScalarConverter::convert(str);
	}
	return 0;
}