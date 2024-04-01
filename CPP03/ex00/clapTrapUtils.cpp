/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clapTrapUtils.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:53:38 by astein            #+#    #+#             */
/*   Updated: 2024/04/01 13:57:13 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clapTrapUtils.hpp"
#include <iostream>
#include <iomanip>


// Print the status of a single ClapTrap object
void		print_status(const ClapTrap &c)
{
	std::cout << COLOR_BLUE << "ClapTrap " << c.getName() << "\t" <<
	"hit p.:" << std::setw(2) << std::setfill('0') << c.getHitPoints() << "\t" <<
	"energy p.:" << std::setw(2) << std::setfill('0') << c.getEnergyPoints() << "\t" <<
	"attack damage:" << std::setw(2) << std::setfill('0') << c.getAttackDamage() << "\t" <<
	"Head: " << ClapTrap::getHead()->getName() << " | ";
	if (c.getNext())
		std::cout << "Next: " << c.getNext()->getName();	
	else
		std::cout << "Next: NULL";
	std::cout << COLOR_RESET << std::endl;
}

// Print the status of all ClapTrap objects
void		print_all_status()
{
	ClapTrap *ptr = ClapTrap::getHead();

	std::cout << COLOR_BLUE << std::endl << 
		"Status of all objects:" << 
		COLOR_RESET << std::endl;
	while (ptr)
	{
		print_status(*ptr);
		ptr = ptr->getNext();
	}
	std::cout << std::endl;
}

// Get a ClapTrap object by name
ClapTrap	*getCTbyName(const std::string &name)
{
	ClapTrap *ptr = ClapTrap::getHead();
	while (ptr)
	{
		if (ptr->getName() == name)
			return (ptr);
		ptr = ptr->getNext();
	}
	return (NULL);
}

// Add a ClapTrap object to the linked list
void		addCT(ClapTrap *c)
{
	int i = 1;
	
	if (!ClapTrap::getHead())
	{
		std::cout <<
			"Adding ClapTrap " << c->getName() <<
			" to the HEAD of the list (n=" << getCTCount() << ")" << 
			std::endl;
		ClapTrap::setHead(c);
	}
	else
	{
		std::cout << 
			"Adding ClapTrap " << c->getName() <<
			" to the list (n=" << getCTCount() << ")" <<
			std::endl;
		ClapTrap *tmp = ClapTrap::getHead();
		while (tmp->getNext())
		{
			tmp = tmp->getNext();
			i++;
		}
		tmp->setNext(c);
	}	
}

// Delete a ClapTrap object from the linked list
void		removeCT(ClapTrap *c)
{
	if (!c)
		return ;
		
	// Special Case Head
	if (c == ClapTrap::getHead())
	{
		ClapTrap::setHead(c->getNext());
		c->setNext(NULL);
		std::cout << COLOR_YELLOW <<
			"ClapTrap " << c->getName() <<
			" removed from the HEAD of the list" <<
			COLOR_RESET << std::endl;
		return ;		
	}
	else
	{
		// General Case
		ClapTrap	*prev = NULL;
		ClapTrap	*ptr = ClapTrap::getHead();
		while (ptr && ptr != c)
		{
			prev = ptr;
			ptr = ptr->getNext();
		}
		if (ptr)
		{
			if (prev)
				prev->setNext(c->getNext());
			c->setNext(NULL);
			std::cout << COLOR_YELLOW <<
				"ClapTrap " << c->getName() <<
				" removed from the list" <<
				COLOR_RESET << std::endl;
		}
		else
			std::cout << COLOR_RED <<
				"ClapTrap " << c->getName() <<
				" not found in the list" <<
				COLOR_RESET << std::endl;	
	}	
}

// Get the number of ClapTrap objects in the linked list
int			getCTCount()
{
	int i = 0;
	ClapTrap *ptr = ClapTrap::getHead();
	while (ptr)
	{
		ptr = ptr->getNext();
		i++;
	}
	return (i);
}
