/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:59:01 by astein            #+#    #+#             */
/*   Updated: 2024/04/01 14:25:28 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "clapTrapUtils.hpp"

// Private default constructor
FragTrap::FragTrap() : ClapTrap("nameless FragTrap")
{
	std::cout << 
		COLOR_GREEN <<
		"FragTrap default constructor called..." <<
		COLOR_RESET << std::endl;
}

// Parametric Constructor
FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << 
		COLOR_GREEN <<
		"FragTrap constructor called..." <<
		COLOR_RESET << std::endl;
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
}

// Copy constructor
FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	std::cout <<
		COLOR_PURPLE <<
		"FragTrap copy constructor called" <<
		COLOR_RESET << std::endl;
}

// Destructor
FragTrap::~FragTrap()
{
	std::cout << COLOR_RED <<
		"FragTrap destructor called" <<
		COLOR_RESET << std::endl;
}

// Assignment Operator Overload
FragTrap	&FragTrap::operator=(const FragTrap &other)
{
	std::cout <<
		COLOR_PURPLE <<
		"FragTrap equal assignment operator called" <<
		COLOR_RESET << std::endl;
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
	return (*this);
}

// Member functions
void	FragTrap::attack(std::string const &target)
{
	std::cout << COLOR_RED <<
		"FragTrap " << this ->getName() << " tries to attack " << target <<
		COLOR_RESET  << std::endl;
	ClapTrap::attack(target);
}

void	FragTrap::highFivesGuys() const
{
	std::cout << COLOR_YELLOW <<
		"FragTrap " << this->getName() <<
		" requests a high five!" <<
		COLOR_RESET << std::endl;
}
