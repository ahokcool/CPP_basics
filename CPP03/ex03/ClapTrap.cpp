/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:10:02 by astein            #+#    #+#             */
/*   Updated: 2024/03/21 21:44:58 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "clapTrapUtils.hpp"

// Static variables for the linked list
ClapTrap	*ClapTrap::_head = NULL;

// Constructor
ClapTrap::ClapTrap(std::string name) :
	_name(name),
	_hitPoints(10),
	_energyPoints(10),
	_attackDamage(0),
	_next(NULL)
{
	std::cout << 
		COLOR_GREEN <<
		"ClapTrap constructor called..." <<
		COLOR_RESET << std::endl;
	addCT(this);
}

// Copy constructor
ClapTrap::ClapTrap(const ClapTrap &other) :
	_name(other.getName()),
	_hitPoints(other.getHitPoints()),
	_energyPoints(other.getEnergyPoints()),
	_attackDamage(other.getAttackDamage())
{
	std::cout <<
		COLOR_PURPLE <<
		"ClapTrap copy constructor called" <<
		COLOR_RESET << std::endl;
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

// Destructor
ClapTrap::~ClapTrap()
{
	std::cout << COLOR_RED <<
		"ClapTrap destructor called" <<
		COLOR_RESET << std::endl;
	deleteCT(this);
}

// Getter Functions
// =============================================================================
const	std::string		ClapTrap::getName() const
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

ClapTrap	*ClapTrap::getHead() const
{
	return (ClapTrap::_head);
}

ClapTrap	*ClapTrap::getNext() const
{
	return (this->_next);
}

// Setter Functions
// =============================================================================
void			ClapTrap::set_hitPoints(unsigned int hitPoints)
{
	_hitPoints = hitPoints;	
}

void			ClapTrap::set_energyPoints(unsigned int energyPoints)
{
	_energyPoints = energyPoints;	
}

void			ClapTrap::set_attackDamage(unsigned int attackDamage)
{
	_attackDamage = attackDamage;	
}

void		ClapTrap::setHead(ClapTrap *head)
{
	ClapTrap::_head = head;
}

void		ClapTrap::setNext(ClapTrap *next)
{
	this->_next = next;
}

// Member Functions
// =============================================================================
void	ClapTrap::print_status() const
{
	std::cout << COLOR_BLUE <<
	"ClapTrap\t" <<
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

void	ClapTrap::attack(const std::string &target)
{
	ClapTrap *targetClapTrap = getCTbyName(*this, target);
	
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
	if (this->getHitPoints()  == 0)
	{
		std::cout << COLOR_RED <<
			"ClapTrap " << this->getName() <<
			" has no hit points left to take damage!" <<
			COLOR_RESET << std::endl;
		return ;
	}
	if ((int)(this->getHitPoints()) - (int)amount >= 0)
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
			" of the " << amount << " points of damage!" <<
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

