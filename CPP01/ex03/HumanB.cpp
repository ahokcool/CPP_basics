/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 01:05:51 by astein            #+#    #+#             */
/*   Updated: 2024/03/29 21:52:18 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

// Constructor
HumanB::HumanB(const std::string &name) : _name(name)
{
	this->_weapon = NULL;
}

// Destructor
HumanB::~HumanB()
{
	// Destructor - nothing to do
}

// Member functions
void HumanB::attack() const
{
    std::cout << this->_name << " attacks with his ";
	if (this->_weapon)
        std::cout << this->_weapon->getType() << std::endl;
    else
    	std::cout << "bare hands" << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}
