/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 01:12:31 by astein            #+#    #+#             */
/*   Updated: 2024/03/29 01:14:59 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

// Constructor
Ice::Ice() : AMateria("ice")
{
	// Nothing to do here
}

// Copy Constructor
Ice::Ice(const Ice &other) : AMateria(other)
{
	// Nothing to do here
}

// Copy Assignment Operator
Ice &Ice::operator=(const Ice &other)
{
	if (this != &other)
		AMateria::operator=(other);
	return (*this);
}

// Destructor
Ice::~Ice()
{
	// Nothing to do here
}

// Member functions
AMateria	*Ice::clone() const
{
	return (new Ice(*this));
}

void		Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
