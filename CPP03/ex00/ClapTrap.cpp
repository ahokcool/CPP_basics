/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:10:02 by astein            #+#    #+#             */
/*   Updated: 2024/03/21 14:37:40 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "clapTrapUtils.hpp"

ClapTrap	*ClapTrap::_head = NULL;

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0), _next(NULL)
{
	std::cout << COLOR_CYAN << "ClapTrap constructor called..." << COLOR_RESET << std::endl;
	addClapTrap(this);
}

ClapTrap::ClapTrap(const ClapTrap &other) : _name(other._name), _hitPoints(other._hitPoints), _energyPoints(other._energyPoints), _attackDamage(other._attackDamage)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << COLOR_PURPLE << "Deep copy from " << other.getName() << " to " << this->getName() << COLOR_RESET << std::endl;
	if (this != &other)
	{
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << COLOR_CYAN << "ClapTrap destructor called" << COLOR_RESET << std::endl;
}

void	ClapTrap::attack(const std::string &target)
{
	ClapTrap *targetClapTrap = getClapTrap(*this, target);
	
	std::cout << COLOR_RED << this ->getName() << " tries to attack " << target << COLOR_RESET  << std::endl;
	if (this->_hitPoints  == 0)
	{
		std::cout << COLOR_RED << "ClapTrap " << this->_name << " has no hit points left to attack <target>!" << COLOR_RESET << std::endl;
		return ;
	}
	if (this->_energyPoints == 0)
		std::cout << COLOR_RED << "ClapTrap " << this->_name << " has no energy points left to attack <target>!" << COLOR_RESET << std::endl;
	else
	{
		if (targetClapTrap)
		{
			std::cout << COLOR_RED << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->getAttackDamage() << " points of damage!" << COLOR_RESET << std::endl;
			targetClapTrap->takeDamage(this->getAttackDamage());
			this->_energyPoints -= 1;
		}
		else
			std::cout << COLOR_RED << "ClapTrap " << this->_name << " cannot attack " << target << " because it does not exist!" << COLOR_RESET << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints  == 0)
	{
		std::cout << COLOR_YELLOW << "ClapTrap " << this->_name << " has no hit points left to take damage!" << COLOR_RESET << std::endl;
		return ;
	}
	if (this->_hitPoints - amount > 0)
	{
		std::cout << COLOR_YELLOW << "ClapTrap " << this->_name << " takes " << amount << " points of damage!" << COLOR_RESET << std::endl;
		this->_hitPoints -= amount;
	}
	else
	{
		std::cout << COLOR_YELLOW << "ClapTrap " << this->_name << " takes only " << this->_hitPoints << "of the " << amount << " points of damage!" << COLOR_RESET << std::endl;
		this->_hitPoints = 0;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name << " has no energy points left to be repaired!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " is being repaired for " << amount << " points! (now: " << this->_hitPoints + amount << " hitpoints)" << std::endl;	
	this->_hitPoints += amount;
}

// Getter
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

// Linked List Functions
void		ClapTrap::setHead(ClapTrap *head)
{
	ClapTrap::_head = head;
}

void		ClapTrap::setNext(ClapTrap *next)
{
	this->_next = next;
}

ClapTrap	*ClapTrap::getHead() const
{
	return (ClapTrap::_head);
}

ClapTrap	*ClapTrap::getNext() const
{
	return (this->_next);
}

// Print 