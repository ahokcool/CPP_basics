/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 18:25:33 by astein            #+#    #+#             */
/*   Updated: 2024/04/30 00:52:30 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// COLORS
# define CLR_RED "\033[31m"
# define CLR_RST "\033[0m"

void	info(std::string str, std::string clr)
{
	std::cout <<
		clr <<
		" >> " << str <<
		CLR_RST << std::endl;
}

int	main(int arc, const char **argv)
{
	if (arc < 2)
	{
		info ("Error\nUsage: ./PmergeMe \"1 5 3 7 6\"", CLR_RED);
		return 1;
	}
	
	try
	{
		PmergeMe pm(argv, false);
		pm.run();
	}
	catch (std::exception &e)
	{
		return 1;
	}
	return 0;
}
