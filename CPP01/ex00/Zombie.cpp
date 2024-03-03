/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 23:16:14 by astein            #+#    #+#             */
/*   Updated: 2024/03/03 01:55:22 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

// Constructor
Zombie::Zombie(const std::string& name) : _name(name)
{
	// Constructor - nothing to do
}

// Destructor
Zombie::~Zombie()
{
	std::cout << _name << " is dead" << std::endl;
}

// Member function
void Zombie::announce(void) const
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
