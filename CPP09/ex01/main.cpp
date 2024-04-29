/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:28:38 by astein            #+#    #+#             */
/*   Updated: 2024/04/29 18:13:16 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <map>

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

void	putTestMsg(std::string myResult, std::string correctResult)
{
	if (myResult == correctResult)
		info ("  [OK]\n", CLR_GRN);
	else
	{
		std::string msg =
	    	std::string("  [KO]\n") +
	    	std::string("       mine:\t") + myResult +
	    	std::string("\n       correct:\t") + correctResult + "\n";
		info (msg, CLR_RED);	
	}
}

void	tests()
{
	title ("Start testing", true, false);

	// Create all tests here
	std::map<std::string, std::string> tests;
	tests["1 1 +"] = "2";
	tests["1 1 -"] = "0";
	tests["2 2 *"] = "4";
	tests["4 2 /"] = "2";
	tests["4 0 /"] = "Error";	// Division by 0
	tests[""] = "Error";		// Empty string
	tests["8 9 * 9 - 9 - 9 - 4 - 1 +"] = "42";
	tests["7 7 * 7 -"] = "42";
	tests["1 2 * 2 / 2 * 2 4 - +"] = "0";
	tests["(1 + 1)"] = "Error";
	tests["8 9 * 9 - 9 - 9 - 4 - 1 +"] = "42";
	tests["9 8 * 4 * 4 / 2 + 9 - 8 - 8 - 1 - 6 -"] = "42";
	tests["1 2 * 2 / 2 + 5 * 6 - 1 3 * - 4 5 * * 8 /"] = "15";
		
	// Test all cases
	for (std::map<std::string, std::string>::iterator it = tests.begin(); it != tests.end(); it++)
	{
		info (" Test: '" + it->first + "'", CLR_ORN);
		putTestMsg(RPN::rpn(it->first), it->second.c_str());
	}
}

int	main(int arc, char **argv)
{
	if (arc != 2)
	{
		title ("RPN", false, true);
		info ("Usage: ./RPN \"expression\"", CLR_RED);
		tests();
	}
	else
		RPN::rpn(argv[1]);
	return (0);
}
