/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:17:14 by astein            #+#    #+#             */
/*   Updated: 2024/04/01 21:21:51 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include "clapTrapUtils.hpp"

// Private default constructor
DiamondTrap::DiamondTrap() :
	ClapTrap ("nameless DiamondTrap"),
	ScavTrap ("nameless DiamondTrap"),
	FragTrap ("nameless DiamondTrap"),
	_name("nameless DiamondTrap")
{
	std::cout << 
		COLOR_GREEN <<
		"DiamondTrap default constructor called..." <<
		COLOR_RESET << std::endl;
}

// Parametric Constructor
DiamondTrap::DiamondTrap(std::string name) :
	ClapTrap(name + "_cn"),
	ScavTrap(name + "_cn"),
	FragTrap(name + "_cn"),
	_name(name)
{
	std::cout << 
		COLOR_GREEN <<
		"DiamondTrap constructor called..." <<
		COLOR_RESET << std::endl;
	// this->setHitPoints(100);		//Not needed since the FragTrap already sets it	
	// this->setAttackDamage(30);
	this->setEnergyPoints(50);
}

// Copy constructor
DiamondTrap::DiamondTrap(const DiamondTrap &other) : 
	ClapTrap(other),
	ScavTrap(other),
	FragTrap(other),
	_name(other._name)
{
	std::cout <<
		COLOR_PURPLE <<
		"DiamondTrap copy constructor called" <<
		COLOR_RESET << std::endl;
}

// Destructor
DiamondTrap::~DiamondTrap()
{
	std::cout << COLOR_RED <<
		"DiamondTrap destructor called" <<
		COLOR_RESET << std::endl;
}

// Assignment Operator Overload
DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &other)
{
	std::cout <<
		COLOR_PURPLE <<
		"DiamondTrap equal assignment operator called" <<
		COLOR_RESET << std::endl;
	if (this != &other)
	{
		ClapTrap::operator=(other);
        ScavTrap::operator=(other);
        FragTrap::operator=(other);
		this->_name = other._name;
	}
	return (*this);
}

// Needs an override because this class has a different name than the base class
const std::string	DiamondTrap::getName() const
{
	return (this->_name);
}

// Needs an override because both ScavTrap and FragTrap have an attack function
void				DiamondTrap::attack(const std::string &target)
{
	std::cout << COLOR_RED <<
		"DiamondTrap " << this->getName() << " attacks like a ScavTrap " << target <<
		COLOR_RESET << std::endl;
	ScavTrap::attack(target);
}

// Member functions
void				DiamondTrap::whoAmI() const
{
	std::cout << COLOR_YELLOW <<
		"I am " << this->getName() <<
		" and my ClapTrap name is " << ClapTrap::getName() <<
		COLOR_RESET << std::endl;
		// Since we call the base class function within an instance of DiamondTrap
		// The instance pointer "this" will not be changed an therefore the function
		// call 'ClapTrap::getName()' will contain the corresponding this pointer
}
