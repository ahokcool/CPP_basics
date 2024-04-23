/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:16:57 by astein            #+#    #+#             */
/*   Updated: 2024/04/23 17:03:04 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>

// COLORS
# define CLR_RED "\033[31m"
# define CLR_GRN "\033[32m"
# define CLR_YLW "\033[33m"
# define CLR_BLU "\033[34m"
# define CLR_ORN "\033[38;5;202m"
# define CLR_BLD "\033[1m"
# define CLR_RST "\033[0m"

int main()
{
	std::cout << "TEST WITH VECTOR CONTAINER" << std::endl;

	std::vector<int> vi;
	vi.push_back(42);
	vi.push_back(1);
	vi.push_back(2);
	vi.push_back(3);
	vi.push_back(42);
	
	// Try with a vector
	std::cout << "Find 1 in vector: " << ::easyfind(vi, 1) << std::endl;
	std::cout << "Find 2 in vector: " << ::easyfind(vi, 2) << std::endl;
	try
	{
		std::cout << "Find 420 in vector: " << ::easyfind(vi, 420) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << "TEST WITH LIST CONTAINER" << std::endl;

	std::list<int> list;

    list.push_back(1);
    list.push_back(5);
    list.push_back(12);
    list.push_back(23);
    list.push_back(23);
    list.push_back(30);

    std::list<int>::iterator it;

    for (it = list.begin(); it != list.end(); ++it)
        std::cout << &(*it) << std::endl;
    

    for (int i = 0; i <= 30; i++)
    {
		try
		{
            std::cout <<
				"does value '" << i << "' exists on the container? " << CLR_GRN <<
				::easyfind(list, i) <<
				std::endl << CLR_RST;
		}
		catch(const std::exception& e)
		{
			std::cout << CLR_RED <<
				"Exception cought: couldn't find: " <<
				i << 
				std::endl << CLR_RST;
		}            
    }
	return 0;
}

