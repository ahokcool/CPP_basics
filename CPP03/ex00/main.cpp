/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:09:36 by astein            #+#    #+#             */
/*   Updated: 2024/03/21 14:28:59 by astein           ###   ########.fr       */
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

	print_all_status(c1);
	c1.attack("c2");
	print_all_status(c1);
	c2 = c1;
	print_all_status(c1);
	c1.attack("c2");
	print_all_status(c1);
	c1.attack("c3");
	print_all_status(c1);
	return (0);
}
