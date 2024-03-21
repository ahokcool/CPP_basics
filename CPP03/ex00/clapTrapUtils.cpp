/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clapTrapUtils.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:53:38 by astein            #+#    #+#             */
/*   Updated: 2024/03/21 14:33:10 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clapTrapUtils.hpp"

void		print_status(const ClapTrap &c)
{
	std::cout << COLOR_GREEN << "ClapTrap " << c.getName() << " has " <<
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

ClapTrap	*getClapTrap(const ClapTrap &c, const std::string &name)
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

void		deleteClapTrap(const ClapTrap *c)
{
	(void)c;
	// TODO
}

void		addClapTrap(ClapTrap *c)
{
	int i = 1;
	
	if (!c->getHead())
	{
		std::cout << "Adding ClapTrap " << c->getName() << " to the HEAD of the list (n=" << getClapTrapCount(c) << ")" << std::endl;
		c->setHead(c);
	}
	else
	{
		std::cout << "Adding ClapTrap " << c->getName() << " to the list (n=" << getClapTrapCount(c) << ")" << std::endl;
		ClapTrap *tmp = c->getHead();
		while (tmp->getNext())
		{
			tmp = tmp->getNext();
			i++;
		}
		tmp->setNext(c);
	}	
}

int			getClapTrapCount(ClapTrap *c)
{
	int i = 0;
	ClapTrap *tmp = c->getHead();
	while (tmp)
	{
		// print_status(*tmp);
		tmp = tmp->getNext();
		i++;
	}
	return (i);
}