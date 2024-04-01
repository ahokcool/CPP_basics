/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:17:14 by astein            #+#    #+#             */
/*   Updated: 2024/03/21 22:16:49 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

// Constructor
DiamondTrap::DiamondTrap(std::string name) :
	ClapTrap(name + "_cn"),
	ScavTrap(name),
	FragTrap(name),
	_name(name)
{
	std::cout << 
		COLOR_GREEN <<
		"DiamondTrap constructor called..." <<
		COLOR_RESET << std::endl;
	this->set_hitPoints(100);
	this->set_energyPoints(50);
	this->set_attackDamage(30);
}

// Destructor
DiamondTrap::~DiamondTrap()
{
	std::cout << COLOR_RED <<
		"DiamondTrap destructor called" <<
		COLOR_RESET << std::endl;
}

// Overriding base class member functions
void		DiamondTrap::print_status() const
{
	std::cout << COLOR_BLUE <<
		"DiamondTrap\t" <<
		this->getName() << "\t" <<
		this->getHitPoints() << "\t" <<
		this->getEnergyPoints() << "\t" <<
		this->getAttackDamage() << "\t" <<
		this->getHead()->getName() << "\t";
	if (this->getNext())
		std::cout << this->getNext()->getName();
	else
		std::cout << "NULL";
	std::cout << "\t" <<
		this->_name <<
		COLOR_RESET << std::endl;
}

//needs an override because this class has a different name than the base class
const std::string	DiamondTrap::getName() const
{
	return (this->_name);
}

// Member functions
void	DiamondTrap::whoAmI()
{
	std::cout << COLOR_YELLOW <<
		"I am " << this->getName() <<
		" and my ClapTrap name is " << this->ClapTrap::getName() <<
		COLOR_RESET << std::endl;
}