/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 23:16:14 by astein            #+#    #+#             */
/*   Updated: 2024/03/03 00:31:47 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Constructor
Zombie::Zombie(std::string name) : _name(name)	{}
// Destructor
Zombie::~Zombie(void)	{	std::cout << _name << " is dead" << std::endl;	}
// Member function
void Zombie::announce(void) const	{	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;	}
