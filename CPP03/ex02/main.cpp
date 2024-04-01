/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:09:36 by astein            #+#    #+#             */
/*   Updated: 2024/04/01 14:21:59 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "clapTrapUtils.hpp"

int	main()
{
		{	
		std::cout << std::endl << "First test the OCCF functions for FragTrap" << std::endl << std::endl;
		// Test the default constructor
		// FragTrap c1; // This is not allowed since the default constructor is private
		// std::cout << "c1 = " << c1.getName() << std::endl;
		
		// Create a FragTrap object
		FragTrap c1("Fraggy 1");
		print_all_status();
		std::cout << std::endl;
		
		// This is not allowed
		// c1 = c1;
		
		// Test the parameterized constructor
		FragTrap *c2 = new FragTrap("Fraggy 2");
		print_all_status();
		std::cout << std::endl;

		// Test the copy constructor
		FragTrap c3(c1);
		print_all_status();
		std::cout << std::endl;

		// Test the copy assignment operator
		FragTrap c4("Fraggy 4");
		print_all_status();
		c4 = c1;
		print_status(c4);
	
		delete c2;
		std::cout << std::endl << "End of OCCF functions test for FragTrap" << std::endl << std::endl;
	}
	{
		std::cout << std::endl << "Test of the member functions of FragTrap" << std::endl << std::endl;


		ClapTrap	c1("c1");
		ScavTrap	s1("s1");
		FragTrap	f1("f1");
		print_all_status();
	
		s1.guardGate();
		f1.highFivesGuys();
	
		c1.attack("s1");
		s1.attack("f1");
		f1.attack("c1");
		
		print_all_status();
		std::cout << std::endl << "End of member functions test for FragTrap" << std::endl << std::endl;
	}

	// End of Tests
	std::cout << std::endl << std::endl << "End of tests aka main..." << std::endl;
	return (0);
}
