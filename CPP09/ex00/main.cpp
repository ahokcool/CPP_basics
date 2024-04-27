/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 17:56:21 by astein            #+#    #+#             */
/*   Updated: 2024/04/27 18:07:28 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>

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


int main(int argc, char **argv)
{
	title ("Bitcoin Exchange", true, false);
	if (argc != 2)
	{
		info("Usage: ./bitcoin [filename]", CLR_RED);
		return 1;
	}
	info ("Database stored in file:\t" + std::string(CSV_FILE), CLR_GRN);
	info ("Reading data from file:\t" + std::string(argv[1]), CLR_GRN);
	
	// BitcoinExchange exchange;
	// exchange.readData(argv[1]);
	// exchange.display();
	return 0;
}
