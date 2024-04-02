/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:17:13 by astein            #+#    #+#             */
/*   Updated: 2024/04/02 14:12:59 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

// Private default constructor
AMateria::AMateria() : _type("some type, let's keepit a vague...")
{
	// Nothing to do here
}

// Parameterized constructor
AMateria::AMateria(const std::string &type) : _type(type)
{
	// Nothing to do here
}

// Copy Constructor
AMateria::AMateria(const AMateria &other)
{
	*this = other;
}

// Destructor
AMateria::~AMateria()
{
	// Nothing to do here
}

// Copy Assignment Operator
AMateria 			&AMateria::operator=(const AMateria &other)
{
	// SUBJECT:
	// While assigning a Materia to another,
	// copying the type doesn’t make sense.
	// if (this != &other)
	//	this->_type = other._type;
	(void)other;
	return (*this);
}

// Member functions
const std::string	&AMateria::getType() const
{
	return (this->_type);
}

void				AMateria::use(const ICharacter &target)
{
	(void)target;
	// Not sure why I couldn't make this pure virtual
}