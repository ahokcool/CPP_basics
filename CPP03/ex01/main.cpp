/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:09:36 by astein            #+#    #+#             */
/*   Updated: 2024/04/01 14:38:41 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "clapTrapUtils.hpp"

int	main()
{
	{	
		std::cout << std::endl << "First test the OCCF functions for ScavTrap" << std::endl << std::endl;
		// Test the default constructor
		// ScavTrap c1; // This is not allowed since the default constructor is private
		// std::cout << "c1 = " << c1.getName() << std::endl;
		
		// Create a ScavTrap object
		ScavTrap c1("Scavvy 1");
		print_all_status();
		std::cout << std::endl;
		
		// This is not allowed
		// c1 = c1;
		
		// Test the parameterized constructor
		ScavTrap *c2 = new ScavTrap("Scavvy 2");
		print_all_status();
		std::cout << std::endl;

		// Test the copy constructor
		ScavTrap c3(c1);
		print_all_status();
		std::cout << std::endl;

		// Test the copy assignment operator
		ScavTrap c4("Scavvy 4");
		print_all_status();
		c4 = c1;
		print_status(c4);
	
		delete c2;
		std::cout << std::endl << "End of OCCF functions test for ScavTrap" << std::endl << std::endl;
	}

	{
		std::cout << std::endl << "Test of the member functions of ScavTrap" << std::endl << std::endl;
		
		ClapTrap	c1("c1");
		print_all_status();
	
		// Initialize 3 ScavTrap objects
		std::cout << std::endl << std::endl << "Initializing ScavTrap objects..." << std::endl;
		ScavTrap	s1("s1");
		ScavTrap	s2("s2");
		print_all_status();
		s1.attack("s2");
		print_all_status();
		s1.attack("s2");
		print_all_status();
		s1.attack("s2");
		print_all_status();
		s1.attack("s2");
		print_all_status();
		s1.attack("s2");
		print_all_status();
		s1.attack("s2");
		print_all_status();
		s2.beRepaired(10);
		print_all_status();
		s2.beRepaired(5);
		print_all_status();
		s1.attack("s2");
		print_all_status();
		s1.attack("s2");
		print_all_status();
		s1.guardGate();
		std::cout << std::endl << "End of member functions test for ScavTrap" << std::endl << std::endl;
	}
	// End of Tests
	std::cout << std::endl << std::endl << "End of tests aka main..." << std::endl;
	return (0);
}
