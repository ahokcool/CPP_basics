/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:09:36 by astein            #+#    #+#             */
/*   Updated: 2024/04/01 13:49:03 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "clapTrapUtils.hpp"

int	main()
{
	{	
		std::cout << std::endl << "First test the OCCF functions for ClapTrap" << std::endl << std::endl;
		// Test the default constructor
		// ClapTrap c1; // This is not allowed since the default constructor is private
		// std::cout << "c1 = " << c1.getName() << std::endl;
		
		// Create a ClapTrap object
		ClapTrap c1("Clappy 1");
		print_all_status();
		std::cout << std::endl;
		
		// Test the parameterized constructor
		ClapTrap *c2 = new ClapTrap("Clappy 2");
		print_all_status();
		std::cout << std::endl;

		// Test the copy constructor
		ClapTrap c3(c1);
		print_all_status();
		std::cout << std::endl;

		// Test the copy assignment operator
		ClapTrap c4("Clappy 4");
		print_all_status();
		c4 = c1;
		print_status(c4);
	
		delete c2;
		std::cout << std::endl << "End of OCCF functions test for ClapTrap" << std::endl << std::endl;
	}
	
	{
		// Initialize 3 ClapTrap objects
		std::cout << std::endl << "Test of the member functions of ClapTrap" << std::endl << std::endl;
		ClapTrap	c1("c1");
		ClapTrap	c2("c2");
		ClapTrap	c3("c3");
	
		print_all_status();
		c1.attack("c2");
		c1.attack("c42");
		print_all_status();
		c2 = c1;
		print_all_status();
		// This is not allowed
		// c1 = c1;
		print_all_status();
		c1.attack("c2");
		print_all_status();
		c1.attack("c3");
		print_all_status();
	}
	return (0);
}
