/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 18:25:33 by astein            #+#    #+#             */
/*   Updated: 2024/04/29 21:35:32 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"


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

void	doTests()
{
	title("Test 1", true, false);
	info("Test 1", CLR_BLU);
}

int	main(int arc, const char **argv)
{
	if (arc < 2)
	{
		info ("Error\nUsage: ./PmergeMe \"1 5 3 7 6\"", CLR_RED);
		doTests();
		return 0;
	}
	
	try
	{
		PmergeMe pm(argv);
		pm.run();
	}
	catch (std::exception &e)
	{
		// std::cerr << e.what() << std::endl;
	}
	return (0);
}
