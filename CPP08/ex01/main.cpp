/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:06:33 by astein            #+#    #+#             */
/*   Updated: 2024/04/25 15:27:40 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <cstdlib>
#include <climits>
#include <ctime>

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

void	test_max_rng()
{
	title("START MAX RANGE TEST", true, false);
	Span sp = Span(2);
	sp.addNumber(int(INT_MIN));
	sp.addNumber(int(INT_MAX));
	sp.print();
	std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "longest span: " << sp.longestSpan() << std::endl;
	title("END MAX RANGE TEST", false, true);
}

void	big_test()
{
	title("START BIG TEST", true, false);
	Span sp = Span(42000);
	srand(static_cast<unsigned int>(time(0)));

	
	std::vector<int> randomNumbers;
	info("generate 1.000 random numbers between 0 and 9999", CLR_BLU);
    for (int i = 0; i < 1000; ++i)
	{
		// Random numbers between 0 and 9999
        randomNumbers.push_back(rand() % 10000);
    }
	sp.addRange(randomNumbers.begin(), randomNumbers.end());
	// sp.print();
	std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "longest span: " << sp.longestSpan() << std::endl;
	std::vector<int> randomNumbers2;
	info("generate 40.000 random numbers of full integer range and add them...", CLR_BLU);
	for (int i = 0; i < 40000; ++i)
	{
 		int randomNum = rand();  // First get a random number
    	int sign = rand() % 2;   // Determine the sign, 0 for negative, 1 for positive

    	// If sign is 0, we invert the number using two's complement (i.e., -number - 1)
    	if (sign == 0) {
	        randomNum = -randomNum - 1;
	    }

	    // Adjust the range from 0...RAND_MAX (or its negative) to INT_MIN...INT_MAX
	    long long fullRangeRandom = static_cast<long long>(randomNum) * (static_cast<long long>(INT_MAX) - INT_MIN) / RAND_MAX + INT_MIN;

	    // Ensure the random number is within the int range
	    int finalRandomNumber = static_cast<int>(fullRangeRandom);
        randomNumbers2.push_back(finalRandomNumber);
    }
	sp.addRange(randomNumbers2.begin(), randomNumbers2.end());
	std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "longest span: " << sp.longestSpan() << std::endl;
	// sp.print();
	title("END BIG TEST", false, true);
}

int	main()
{
	{
		title("START 42 MAIN", true, false);
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		title("END 42 MAIN", false, true);		
	}

	title("START SPAN TEST", true, false);
	info("Default constructor is private", CLR_BLU);
	// Span sp = Span(); // Error: 'Span::Span()' is private within this context
	info("Constructor with unsigned int size of 5", CLR_BLU);
	Span sp = Span(5);
	info("shortestSpan and longestSpan are not working yet:", CLR_BLU);
	try
	{
		sp.shortestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << CLR_RED << e.what() << CLR_RST << '\n';
	}
	try
	{
		sp.longestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << CLR_RED << e.what() << CLR_RST << '\n';
	}
	
	info("Adding number 42 to the span", CLR_BLU);
	sp.addNumber(42);
	info("shortestSpan and longestSpan are still not working", CLR_BLU);
	try
	{
		sp.shortestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << CLR_RED << e.what() << CLR_RST << '\n';
	}
	try
	{
		sp.longestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << CLR_RED << e.what() << CLR_RST << '\n';
	}
	
	info("Adding number 21 to the span", CLR_BLU);
	sp.addNumber(21);
	info("shortestSpan and longestSpan are now working...", CLR_BLU);
	std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "longest span: " << sp.longestSpan() << std::endl;

	info("adding numbers until the vector is 'full'...", CLR_BLU);
	int i = 100;
	while (true)
	{
		try
		{
			sp.addNumber(i);
			std::cout << "added number " << i << std::endl;
			i++;
		}
		catch(const std::exception& e)
		{
			std::cerr << CLR_RED << e.what() << CLR_RST << '\n';
			break;
		}
	}
	sp.print();
	info("shortestSpan and longestSpan are now working...", CLR_BLU);
	std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "longest span: " << sp.longestSpan() << std::endl;
	info("try copy constructor", CLR_BLU);
	Span sp2 = sp;
	sp2.print();
	info("create empty span and add twice the number 0", CLR_BLU);
	Span sp3 = Span(42);
	sp3.print();
	sp3.addNumber(0);
	sp3.addNumber(0);
	info("duplicates are kept and span is 0...", CLR_BLU);
	sp3.print();
	std::cout << "shortest span: " << sp3.shortestSpan() << std::endl;
	std::cout << "longest span: " << sp3.longestSpan() << std::endl;
	// Since N is const, we can't change it! So this wont work
	// Span sp4(12);
	// sp4 = sp3;
	
	info("use the addRange to add numbers...", CLR_BLU);
	 std::vector<int> v(5);
    v[0] = 1;
    v[1] = 2;
    v[2] = 3;
    v[3] = 4;
    v[4] = 5;
	Span sp5 = Span(10);
	sp5.print();	
	sp5.addRange(v.begin(), v.end());
	sp5.print();
	sp5.addRange(v.begin(), v.end());
	sp5.print();
	try
	{
		sp5.addRange(v.begin(), v.end());
	}
	catch(const std::exception& e)
	{
		std::cerr << CLR_RED << e.what() << CLR_RST << '\n';
	}
		
	title("END SPAN TEST", false, true);
	test_max_rng();
	big_test();
	return 0;	
}
