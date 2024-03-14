/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clapTrapUtils.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:53:38 by astein            #+#    #+#             */
/*   Updated: 2024/03/14 18:10:26 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

void		print_status(const ClapTrap &c)
{
	std::cout << "ClapTrap " << c.getName() << " has " <<
	c.getHitPoints() << " hit points, " << 
	c.getEnergyPoints() << " energy points and " <<
	c.getAttackDamage() << " attack damage!" << std::endl;
}

ClapTrap	*getClapTrap(const std::string &name)
{
	ClapTrap *tmp = ClapTrap::getHead();
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
	// TODO
}

void		addClapTrap(const ClapTrap *c)
{
	int i = 1;
	
	if (!c->getHead())
		c.setHead(c);
	else
	{
		ClapTrap *tmp = c->getHead();
		while (tmp->getNext())
		{
			tmp = tmp->getNext();
			i++;
		}
	}	
}
