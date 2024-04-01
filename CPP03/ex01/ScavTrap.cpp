/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:37:29 by astein            #+#    #+#             */
/*   Updated: 2024/04/01 15:20:33 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "clapTrapUtils.hpp"

// Private default constructor
ScavTrap::ScavTrap() : ClapTrap("nameless ScavTrap"), _gateKeeperMode(false)
{
	std::cout << 
		COLOR_GREEN <<
		"ScavTrap default constructor called..." <<
		COLOR_RESET << std::endl;
}

// Parametric Constructor
ScavTrap::ScavTrap(std::string name) : ClapTrap(name), _gateKeeperMode(false)
{
	std::cout << 
		COLOR_GREEN <<
		"ScavTrap constructor called..." <<
		COLOR_RESET << std::endl;
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
}

// Copy constructor
ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other), _gateKeeperMode(other._gateKeeperMode)
{
	std::cout <<
		COLOR_PURPLE <<
		"ScavTrap copy constructor called" <<
		COLOR_RESET << std::endl;
}

// Destructor
ScavTrap::~ScavTrap()
{
	std::cout << COLOR_RED <<
		"ScavTrap destructor called" <<
		COLOR_RESET << std::endl;
}

// Assignment Operator Overload
ScavTrap	&ScavTrap::operator=(const ScavTrap &other)
{
	std::cout <<
		COLOR_PURPLE <<
		"ScavTrap equal assignment operator called" <<
		COLOR_RESET << std::endl;
	if (this != &other)
	{
		ClapTrap::operator=(other);
		this->_gateKeeperMode = other._gateKeeperMode;	
	}
	return (*this);
}

// Member functions
void	ScavTrap::attack(const std::string &target)
{
	std::cout << COLOR_RED <<
		"ScavTrap " << this ->getName() << " tries to attack " << target <<
		COLOR_RESET  << std::endl;
	ClapTrap::attack(target);
}

void	ScavTrap::guardGate()
{
	this->_gateKeeperMode = true;
	std::cout << COLOR_YELLOW <<
		"ScavTrap " << this->getName() <<
		" has entered Gate keeper mode!" <<
		COLOR_RESET << std::endl;
}
