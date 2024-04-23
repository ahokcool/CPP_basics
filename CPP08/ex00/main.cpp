/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:16:57 by astein            #+#    #+#             */
/*   Updated: 2024/04/23 16:52:04 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>

int main()
{
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
	

	
	return 0;
}

