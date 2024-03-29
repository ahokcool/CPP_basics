/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 01:15:07 by astein            #+#    #+#             */
/*   Updated: 2024/03/29 01:16:44 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

// Constructor
Cure::Cure() : AMateria("cure")
{
	// Nothing to do here
}

// Copy Constructor
Cure::Cure(const Cure &other) : AMateria(other)
{
	// Nothing to do here
}

// Copy Assignment Operator
Cure &Cure::operator=(const Cure &other)
{
	if (this != &other)
		AMateria::operator=(other);
	return (*this);
}

// Destructor
Cure::~Cure()
{
	// Nothing to do here
}

// Member functions
AMateria	*Cure::clone() const
{
	return (new Cure(*this));
}

void		Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
