/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:09:36 by astein            #+#    #+#             */
/*   Updated: 2024/03/16 18:36:29 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "clapTrapUtils.hpp"

int	main()
{
	// Initialize 3 ClapTrap objects
	ClapTrap	c1("c1");
	ClapTrap	c2("c2");
	ClapTrap	c3("c3");
	ClapTrap	c4("c3");
	ClapTrap	c5("c3");


	// Print status of each object
	std::cout << std::endl << "Initial status of each object:" << std::endl;
	print_status(c1);
	print_status(c2);
	print_status(c3);

	// c1 attacks c2
	std::cout << std::endl << "c1 attacks c2:" << std::endl;
	c1.attack("c2");
	
	// Print status of each object
	std::cout << std::endl << "Status of each object" << std::endl;
	print_status(c1);
	print_status(c2);
	print_status(c3);

	// Assign c1 to c2
	std::cout << std::endl << "Assign c1 to c2:" << std::endl;
	c2 = c1;

	// Print status of each object
	std::cout << std::endl << "Status of each object" << std::endl;
	print_status(c1);
	print_status(c2);
	print_status(c3);
	return (0);
}
