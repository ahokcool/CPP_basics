/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:09:36 by astein            #+#    #+#             */
/*   Updated: 2024/03/21 22:06:23 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
#include "clapTrapUtils.hpp"

int	main()
{
	ClapTrap	c1("c1");
	ScavTrap	s1("s1");
	FragTrap	f1("f1");
	DiamondTrap	d1("d1");
	print_all_status(d1);

	s1.guardGate();
	f1.highFivesGuys();
	d1.whoAmI();

	c1.attack("s1");
	s1.attack("f1");
	f1.attack("c1");
	
	print_all_status(c1);

	// End of Tests
	std::cout << std::endl << std::endl << "End of tests aka main..." << std::endl;
	return (0);
}
