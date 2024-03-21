/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:59:01 by astein            #+#    #+#             */
/*   Updated: 2024/03/21 22:21:29 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "clapTrapUtils.hpp"

// Constructor
FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << 
		COLOR_GREEN <<
		"FragTrap constructor called..." <<
		COLOR_RESET << std::endl;
	this->set_hitPoints(100);
	this->set_energyPoints(100);
	this->set_attackDamage(30);
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

// Overriding base class member functions
void		FragTrap::print_status() const
{
	std::cout << COLOR_BLUE <<
	"FragTrap\t" <<
	this->getName() << "\t" <<
	this->getHitPoints() << "\t" <<
	this->getEnergyPoints() << "\t" <<
	this->getAttackDamage() << "\t" <<
	this->getHead()->getName() << "\t";
	if (this->getNext())
		std::cout << this->getNext()->getName();
	else
		std::cout << "NULL";
	std::cout << COLOR_RESET << std::endl;
}

void	FragTrap::attack(std::string const &target)
{
	std::cout << COLOR_RED <<
		"FragTrap " << this ->getName() << " tries to attack " << target <<
		COLOR_RESET  << std::endl;
	ClapTrap::attack(target);
}

// Member functions
void	FragTrap::highFivesGuys()
{
	std::cout << COLOR_YELLOW <<
		"FragTrap " << this->getName() <<
		" requests a high five!" <<
		COLOR_RESET << std::endl;
}

