/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clapTrapUtils.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:53:38 by astein            #+#    #+#             */
/*   Updated: 2024/03/21 22:15:44 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clapTrapUtils.hpp"

// Print the status of all ClapTrap objects
void		print_all_status(const ClapTrap &c)
{
	ClapTrap *tmp = c.getHead();

	std::cout << COLOR_BLUE << std::endl <<
		"Status of all objects:" << std::endl <<
		"Type\t\tName\tHit\tEnergy\tAttack\tHead\tNext\t[DiamondTrap Name]" <<
		COLOR_RESET << std::endl;
	while (tmp)
	{
		tmp->print_status();
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
		std::cout <<
			"Adding ClapTrap " <<
			c->getName() <<
			" to the HEAD of the list (n=" << getCTCount(c) << ")" << std::endl;
		c->setHead(c);
	}
	else
	{
		std::cout <<
			"Adding ClapTrap " <<
			c->getName() <<
			" to the list (n=" << getCTCount(c) << ")" << std::endl;
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
