/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:17:14 by astein            #+#    #+#             */
/*   Updated: 2024/04/01 15:26:42 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include "clapTrapUtils.hpp"

// Private default constructor
DiamondTrap::DiamondTrap() : ClapTrap ("nameless DiamondTrap")
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
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(30);
}

// Copy constructor
DiamondTrap::DiamondTrap(const DiamondTrap &other) : 
	ClapTrap(other)
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
		this->_name = other._name;
	}
	return (*this);
}

// // Overriding base class member functions
// void		DiamondTrap::print_status() const
// {
// 	std::cout << COLOR_BLUE <<
// 		"DiamondTrap\t" <<
// 		this->getName() << "\t" <<
// 		this->getHitPoints() << "\t" <<
// 		this->getEnergyPoints() << "\t" <<
// 		this->getAttackDamage() << "\t" <<
// 		this->getHead()->getName() << "\t";
// 	if (this->getNext())
// 		std::cout << this->getNext()->getName();
// 	else
// 		std::cout << "NULL";
// 	std::cout << "\t" <<
// 		this->_name <<
// 		COLOR_RESET << std::endl;
// }

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
		" and my ClapTrap name is " << this->getName() <<
		COLOR_RESET << std::endl;
}