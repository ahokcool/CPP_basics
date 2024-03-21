/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clapTrapUtils.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:53:38 by astein            #+#    #+#             */
/*   Updated: 2024/03/21 15:29:09 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clapTrapUtils.hpp"

// Print the status of a single ClapTrap object
void		print_status(const ClapTrap &c)
{
	std::cout << COLOR_BLUE << "ClapTrap " << c.getName() << " has " <<
	c.getHitPoints() << " hit points, " << 
	c.getEnergyPoints() << " energy points and " <<
	c.getAttackDamage() << " attack damage! | " << 
	"Head: " << c.getHead()->getName() << " | ";
	if (c.getNext())
		std::cout << "Next: " << c.getNext()->getName();	
	else
		std::cout << "Next: NULL";
	std::cout << COLOR_RESET << std::endl;
}

// Print the status of all ClapTrap objects
void		print_all_status(const ClapTrap &c)
{
	ClapTrap *tmp = c.getHead();

	std::cout << COLOR_BLUE << std::endl << "Status of all objects:" << COLOR_RESET << std::endl;
	while (tmp)
	{
		print_status(*tmp);
		tmp = tmp->getNext();
	}
	std::cout << std::endl;
}

// Get a ClapTrap object by name
ClapTrap	*getCTbyName(const ClapTrap &c, const std::string &name)
{
	ClapTrap *tmp = c.getHead();
	while (tmp)
	{
		if (tmp->getName() == name)
			return (tmp);
		tmp = tmp->getNext();
	}
	return (NULL);
}

// Add a ClapTrap object to the linked list
void		addCT(ClapTrap *c)
{
	int i = 1;
	
	if (!c->getHead())
	{
		std::cout << "Adding ClapTrap " << c->getName() << " to the HEAD of the list (n=" << getCTCount(c) << ")" << std::endl;
		c->setHead(c);
	}
	else
	{
		std::cout << "Adding ClapTrap " << c->getName() << " to the list (n=" << getCTCount(c) << ")" << std::endl;
		ClapTrap *tmp = c->getHead();
		while (tmp->getNext())
		{
			tmp = tmp->getNext();
			i++;
		}
		tmp->setNext(c);
	}	
}

// Delete a ClapTrap object from the linked list
void		deleteCT(ClapTrap *c)
{
	if (!c)
		return ;
	ClapTrap *tmp = c->getHead();
	
	// Special Case Head
	if(c == tmp)
	{
		c->setHead(c->getNext());
		c->setNext(NULL);
		std::cout << COLOR_YELLOW <<
			"ClapTrap " << c->getName() <<
			" deleted from the HEAD of the list" <<
			COLOR_RESET << std::endl;
		return ;		
	}

	// General Case
	while(tmp)
	{
		if (tmp == c)
			break;
		tmp = tmp->getNext();
	}
	if (tmp)
	{
		tmp->setNext(c->getNext());
		c->setNext(NULL);
		std::cout << COLOR_YELLOW <<
			"ClapTrap " << c->getName() <<
			" deleted from the list" <<
			COLOR_RESET << std::endl;
	}
	else
		std::cout << COLOR_RED <<
			"ClapTrap " << c->getName() <<
			" not found in the list" <<
			COLOR_RESET << std::endl;	
}

// Get the number of ClapTrap objects in the linked list
int			getCTCount(ClapTrap *c)
{
	int i = 0;
	ClapTrap *tmp = c->getHead();
	while (tmp)
	{
		tmp = tmp->getNext();
		i++;
	}
	return (i);
}
