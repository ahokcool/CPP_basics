/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:09:36 by astein            #+#    #+#             */
/*   Updated: 2024/04/01 17:57:35 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
#include "clapTrapUtils.hpp"

int	main()
{
	{	
		std::cout << std::endl << "First test the OCCF functions for DiamondTrap" << std::endl << std::endl;
		// Test the default constructor
		// DiamondTrap c1; // This is not allowed since the default constructor is private
		// std::cout << "c1 = " << c1.getName() << std::endl;
		
		// Create a DiamondTrap object
		DiamondTrap c1("Diamy 1");
		c1.whoAmI();
		print_all_status();
		std::cout << std::endl;
		
		// This is not allowed
		// c1 = c1;
		
		// Test the parameterized constructor
		DiamondTrap *c2 = new DiamondTrap("Diamy 2");
		c2->whoAmI();
		print_all_status();
		std::cout << std::endl;

		// Test the copy constructor
		DiamondTrap c3(c1);
		c3.whoAmI();
		print_all_status();
		std::cout << std::endl;

		// Test the copy assignment operator
		DiamondTrap c4("Diamy 4");
		c4.whoAmI();
		print_all_status();
		c4 = c1;
		c4.whoAmI();
		print_all_status();
	
		delete c2;
		std::cout << std::endl << "End of OCCF functions test for DiamondTrap" << std::endl << std::endl;
	}
	{
		std::cout << std::endl << "Test of the member functions of DiamondTrap" << std::endl << std::endl;
		ClapTrap	c1("c1");
		ScavTrap	s1("s1");
		FragTrap	f1("f1");
		DiamondTrap	d1("d1");
		print_all_status();

		s1.guardGate();
		f1.highFivesGuys();
		d1.whoAmI();

		c1.attack("s1");
		print_all_status();

		s1.attack("f1");
		print_all_status();

		f1.attack("c1");		
		print_all_status();
		std::cout << std::endl << "End of member functions test for FragTrap" << std::endl << std::endl;
	}
	// End of Tests
	std::cout << std::endl << std::endl << "End of tests aka main..." << std::endl;
	return (0);
}
