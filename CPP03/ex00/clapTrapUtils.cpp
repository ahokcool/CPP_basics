/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clapTrapUtils.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:53:38 by astein            #+#    #+#             */
/*   Updated: 2024/03/16 18:37:13 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clapTrapUtils.hpp"

void		print_status(const ClapTrap &c)
{
	std::cout << "ClapTrap " << c.getName() << " has " <<
	c.getHitPoints() << " hit points, " << 
	c.getEnergyPoints() << " energy points and " <<
	c.getAttackDamage() << " attack damage!" << std::endl;
}

ClapTrap	*getClapTrap(const ClapTrap &c, const std::string &name)
{
	(void)c;
	(void)name;
	// ClapTrap *tmp = c.getHead();
	// while (tmp)
	// {
	// 	if (tmp->getName() == name)
	// 		return (tmp);
	// 	tmp = tmp->getNext();
	// }
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