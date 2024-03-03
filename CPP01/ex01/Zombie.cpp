/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 23:16:14 by astein            #+#    #+#             */
/*   Updated: 2024/03/03 01:59:23 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

// Constructors
Zombie::Zombie(const std::string& name) : _name(name)
{
	// Constructor - nothing to do
}

Zombie::Zombie() : _name("name_not_set")
{
	// Constructor - nothing to do
}

// Destructor
Zombie::~Zombie()
{
	std::cout << _name << " is dead" << std::endl;
}

// Member functions
void	Zombie::announce() const
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(const std::string& name)
{
	_name = name;
}