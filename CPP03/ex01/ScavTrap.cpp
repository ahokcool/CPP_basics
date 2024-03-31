/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:37:29 by astein            #+#    #+#             */
/*   Updated: 2024/03/30 17:44:16 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "clapTrapUtils.hpp"

// Default constructor
// ScavTrap::ScavTrap() : ClapTrap("nameless ScavTrap")
// {
// 	std::cout << 
// 		COLOR_GREEN <<
// 		"ScavTrap default constructor called..." <<
// 		COLOR_RESET << std::endl;
// }

// Parametric Constructor
ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << 
		COLOR_GREEN <<
		"ScavTrap constructor called..." <<
		COLOR_RESET << std::endl;
	this->set_hitPoints(100);
	this->set_energyPoints(50);
	this->set_attackDamage(20);
}

// Copy constructor
ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	std::cout <<
		COLOR_PURPLE <<
		"ScavTrap copy constructor called" <<
		COLOR_RESET << std::endl;
}

// Equal assignment operator
ScavTrap	&ScavTrap::operator=(const ScavTrap &other)
{
	std::cout <<
		COLOR_PURPLE <<
		"ScavTrap equal assignment operator called" <<
		COLOR_RESET << std::endl;
	if (this != &other)
		ClapTrap::operator=(other);
	return (*this);
}

// Destructor
ScavTrap::~ScavTrap()
{
	std::cout << COLOR_RED <<
		"ScavTrap destructor called" <<
		COLOR_RESET << std::endl;
}

// Member functions
void	ScavTrap::attack(std::string const &target)
{
	std::cout << COLOR_RED <<
		"ScavTrap " << this ->getName() << " tries to attack " << target <<
		COLOR_RESET  << std::endl;
	ClapTrap::attack(target);
}

void	ScavTrap::guardGate()
{
	std::cout << COLOR_YELLOW <<
		"ScavTrap " << this->getName() <<
		" has entered Gate keeper mode!" <<
		COLOR_RESET << std::endl;
}
