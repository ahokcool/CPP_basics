/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:10:02 by astein            #+#    #+#             */
/*   Updated: 2024/04/01 14:07:05 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "clapTrapUtils.hpp"

// Static variables for the linked list
ClapTrap	*ClapTrap::_head = NULL;

// Private default constructor
ClapTrap::ClapTrap() :
	_name(""),
	_hitPoints(0),
	_energyPoints(0),
	_attackDamage(0),
	_next(NULL)
{
	std::cout << 
		COLOR_GREEN <<
		"ClapTrap default constructor called..." <<
		COLOR_RESET << std::endl;
	addCT(this);
}

// Parameterized constructor
ClapTrap::ClapTrap(std::string name) :
	_name(name),
	_hitPoints(10),
	_energyPoints(10),
	_attackDamage(0),
	_next(NULL)
{
	std::cout << 
		COLOR_GREEN <<
		"ClapTrap parameterized constructor called..." <<
		COLOR_RESET << std::endl;
	addCT(this);
}

// Copy constructor
ClapTrap::ClapTrap(const ClapTrap &other) :
	_name(other.getName()),
	_hitPoints(other._hitPoints),
	_energyPoints(other._energyPoints),
	_attackDamage(other._attackDamage),
	_next(NULL)
{
	std::cout <<
		COLOR_PURPLE <<
		"ClapTrap copy constructor called" <<
		COLOR_RESET << std::endl;
	addCT(this);
}

// Destructor
ClapTrap::~ClapTrap()
{
	std::cout << COLOR_RED <<
		"ClapTrap destructor called" <<
		COLOR_RESET << std::endl;
	removeCT(this);
}

// Assignment Operator Overload
ClapTrap	&ClapTrap::operator=(const ClapTrap &other)
{
	if (this != &other)
	{
		std::cout << COLOR_PURPLE <<
			"Deep copy from " << other.getName() << " to " << this->getName() <<
			COLOR_RESET << std::endl;
		this->_hitPoints = other.getHitPoints();
		this->_energyPoints = other.getEnergyPoints();
		this->_attackDamage = other.getAttackDamage();
	}
	else
		std::cout << COLOR_RED <<
			"Self assignments are not allowed!" <<
			COLOR_RESET << std::endl;
	return (*this);
}

// Public Member functions
// =============================================================================
void	ClapTrap::attack(const std::string &target)
{
	ClapTrap *targetClapTrap = getCTbyName(target);
	
	std::cout << COLOR_RED <<
		this ->getName() << " tries to attack " << target <<
		COLOR_RESET  << std::endl;
	if (this->_hitPoints  == 0)
	{
		std::cout << COLOR_RED <<
			"ClapTrap " << this->getName() <<
			" has no hit points left to attack " <<
			target <<
			COLOR_RESET << std::endl;
		return ;
	}
	if (this->_energyPoints == 0)
		std::cout << COLOR_RED <<
			"ClapTrap " << this->getName() <<
			" has no energy points left to attack " <<
			target <<
			COLOR_RESET << std::endl;
	else
	{
		if (targetClapTrap)
		{
			std::cout << COLOR_RED <<
				"ClapTrap " << this->getName() <<
				" attacks " << target <<
				", causing " << this->getAttackDamage() <<
				" points of damage!" <<
				COLOR_RESET << std::endl;
			targetClapTrap->takeDamage(this->getAttackDamage());
			this->_energyPoints -= 1;
		}
		else
			std::cout << COLOR_RED <<
				"ClapTrap " << this->getName() <<
				" cannot attack " <<
				target <<
				" because it does not exist!" <<
				COLOR_RESET << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints  == 0)
	{
		std::cout << COLOR_RED <<
			"ClapTrap " << this->getName() <<
			" has no hit points left to take damage!" <<
			COLOR_RESET << std::endl;
		return ;
	}
	if (this->_hitPoints - amount > 0)
	{
		std::cout << COLOR_GREEN <<
			"ClapTrap " << this->getName() <<
			" takes " << amount <<
			" points of damage!" <<
			COLOR_RESET << std::endl;
		this->_hitPoints -= amount;
	}
	else
	{
		std::cout << COLOR_YELLOW <<
			"ClapTrap " << this->getName() <<
			" takes only " << this->getHitPoints() <<
			"of the " << amount << " points of damage!" <<
			COLOR_RESET << std::endl;
		this->_hitPoints = 0;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints == 0)
	{
		std::cout << COLOR_RED <<
			"ClapTrap " << this->getName() <<
			" has no energy points left to be repaired!" <<
			COLOR_RESET << std::endl;
		return ;
	}
	std::cout << COLOR_GREEN <<
		"ClapTrap " << this->getName() <<
		" is being repaired for " <<
		amount <<
		" points! "<<
		"(" << this->getHitPoints() << "->" << this->getHitPoints() + amount << ")" <<
		COLOR_RESET << std::endl;
	this->_hitPoints += amount;
}

// Accessors (Getters)
// =============================================================================
std::string		ClapTrap::getName() const
{
	return (this->_name);
}

unsigned int	ClapTrap::getHitPoints() const
{
	return (this->_hitPoints);
}

unsigned int	ClapTrap::getEnergyPoints() const
{
	return (this->_energyPoints);
}

unsigned int	ClapTrap::getAttackDamage() const
{
	return (this->_attackDamage);
}

ClapTrap	*ClapTrap::getNext() const
{
	return (this->_next);
}

// Mutators (Setters)
// =============================================================================
void		ClapTrap::setHitPoints(unsigned int hitPoints)
{
	this->_hitPoints = hitPoints;
}

void		ClapTrap::setEnergyPoints(unsigned int energyPoints)
{
	this->_energyPoints = energyPoints;
}

void		ClapTrap::setAttackDamage(unsigned int attackDamage)
{
	this->_attackDamage = attackDamage;
}
	
void		ClapTrap::setNext(ClapTrap *next)
{
	this->_next = next;
}

// Static functions
// =============================================================================
ClapTrap	*ClapTrap::getHead()
{
	return (_head);
}

void		ClapTrap::setHead(ClapTrap *head)
{
	ClapTrap::_head = head;
}
