/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 01:05:51 by astein            #+#    #+#             */
/*   Updated: 2024/03/03 03:01:52 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include "Weapon.hpp"

// Constructor
HumanB::HumanB(const std::string& name) : _name(name)
{
	this->_weapon = NULL;
}

// Destructor
HumanB::~HumanB()
{
	// Destructor - nothing to do
}

// Copy Constructor
HumanB&	HumanB::operator=(const HumanB& assign)
{
	if (this == &assign)
		return (*this);
	this->_name = assign._name;
	this->_weapon = assign._weapon;
	return (*this);
}

void HumanB::attack() const
{
    std::cout << this->_name << " attacks with his ";
	if (this->_weapon)
        std::cout << this->_weapon->getType() << std::endl;
    else
    	std::cout << "bare hands" << std::endl;
}

void	HumanB::setWeapon(Weapon& weapon)
{
	this->_weapon = &weapon;
}
