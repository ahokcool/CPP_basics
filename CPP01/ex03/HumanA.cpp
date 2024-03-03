/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 01:05:46 by astein            #+#    #+#             */
/*   Updated: 2024/03/03 03:05:17 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "Weapon.hpp"

// Constructor
HumanA::HumanA(const std::string& name, Weapon &weapon) : _name(name), _weapon(weapon)
{
	// Constructor - nothing to do
}

// Destructor
HumanA::~HumanA()
{
	// Destructor - nothing to do
}

void HumanA::attack() const
{
    std::cout << this->_name << " attacks with his ";
	// No need to check if _weapon is NULL since it's a reference and 
	// it's guaranteed to be initialized
	std::cout << this->_weapon.getType() << std::endl;
}
