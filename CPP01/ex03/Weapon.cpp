/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 01:02:49 by astein            #+#    #+#             */
/*   Updated: 2024/03/29 21:44:33 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

// Constructor
Weapon::Weapon(const std::string &type)
{
	this->_type = type;
}

// Destructor
Weapon::~Weapon()
{
	// Destructor - nothing to do
}

// Member functions
const std::string	&Weapon::getType() const
{
	return (this->_type);
}

void				Weapon::setType(const std::string &type)
{
	this->_type = type;
}
