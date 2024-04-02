/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 01:12:31 by astein            #+#    #+#             */
/*   Updated: 2024/04/02 15:02:46 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "ICharacter.hpp"

// Default constructor
Ice::Ice() : AMateria("ice")
{
	std::cout << "Ice default constructor called!" << std::endl;
	// Nothing to do here
}

// Copy Constructor
Ice::Ice(const Ice &other) : AMateria(other)
{
	std::cout << "Ice copy constructor called!" << std::endl;
	// Nothing to do here since Ice has no other attributes
}

// Destructor
Ice::~Ice()
{
	std::cout << "Ice destructor called!" << std::endl;
	// Nothing to do here since Ice has no attributes to delete
}

// Copy Assignment Operator
Ice 		&Ice::operator=(const Ice &other)
{
	std::cout << "Ice copy assignment operator called!" << std::endl;
	// No need to check for self-assignment since Ice has no other attributes
	AMateria::operator=(other);
	return (*this);
}

// Member functions
AMateria	*Ice::clone() const
{
	std::cout << "Ice clone called!" << std::endl;
	return (new Ice(*this));
}

void		Ice::use(const ICharacter &target)
{
	std::cout << CLR_CYAN << 
		"* shoots an ice bolt at " <<
		target.getName() << " *" <<
		CLR_RESET << std::endl;
}
