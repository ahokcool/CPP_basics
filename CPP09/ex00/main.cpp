/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 17:56:21 by astein            #+#    #+#             */
/*   Updated: 2024/04/27 22:25:05 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	bool	print_info = false;

	title ("Bitcoin Exchange", true, false);
	if (argc != 2)
	{
		if (argc == 3 && std::string(argv[2]) == "-info")
			print_info = true;
		else
		{
			info("Usage: ./btc <filename> [-info]", CLR_RED);
			return 1;
		}
	}
	
	BitcoinExchange exchange(print_info);
	exchange.calculate(argv[1]);
	return 0;
}
