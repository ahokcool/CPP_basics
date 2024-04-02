/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 01:15:07 by astein            #+#    #+#             */
/*   Updated: 2024/04/02 18:06:29 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "ICharacter.hpp"

// Constructor
Cure::Cure() : AMateria("cure")
{
	// Nothing to do here
	std::cout << "Cure default constructor called!" << std::endl;
}

// Copy Constructor
Cure::Cure(const Cure &other) : AMateria(other)
{
	// Nothing to do here since Cure has no other attributes
	std::cout << "Cure copy constructor called!" << std::endl;
}

// Destructor
Cure::~Cure()
{
	// Nothing to do here since Cure has no attributes to delete
	std::cout << "Cure destructor called!" << std::endl;
}

// Copy Assignment Operator
Cure &Cure::operator=(const Cure &other)
{
	std::cout << "Cure copy assignment operator called!" << std::endl;
	// No need to check for self-assignment since Cure has no other attributes
	AMateria::operator=(other);
	return (*this);
}

// Member functions
AMateria	*Cure::clone() const
{
	std::cout << "Cure clone called!" << std::endl;
	return (new Cure());
}

void		Cure::use(const ICharacter &target)
{
	
	std::cout << CLR_GREEN <<
		"* heals " <<
		target.getName() << "'s wounds *" << 
		CLR_RESET << std::endl;
}
