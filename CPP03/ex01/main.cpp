/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:09:36 by astein            #+#    #+#             */
/*   Updated: 2024/03/21 16:56:52 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "clapTrapUtils.hpp"

int	main()
{
	ClapTrap	c1("c1");
	print_all_status(c1);

	// Initialize 3 ScavTrap objects
	std::cout << std::endl << std::endl << "Initializing ScavTrap objects..." << std::endl;
	ScavTrap	s1("s1");
	ScavTrap	s2("s2");
	print_all_status(s1);
	s1.attack("s2");
	print_all_status(s1);
	s1.attack("s2");
	print_all_status(s1);
	s1.attack("s2");
	print_all_status(s1);
	s1.attack("s2");
	print_all_status(s1);
	s1.attack("s2");
	print_all_status(s1);
	s1.attack("s2");
	print_all_status(s1);
	s2.beRepaired(10);
	print_all_status(s1);
	s2.beRepaired(5);
	print_all_status(s1);
	s1.attack("s2");
	print_all_status(s1);
	s1.guardGate();
	
	// End of Tests
	std::cout << std::endl << std::endl << "End of tests aka main..." << std::endl;
	return (0);
}
