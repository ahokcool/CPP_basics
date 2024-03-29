/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:17:13 by astein            #+#    #+#             */
/*   Updated: 2024/03/29 01:38:10 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

// Constructor
AMateria::AMateria(const std::string & type) : _type(type)
{
	// Nothing to do here
}

// Copy Constructor
AMateria::AMateria(const AMateria & other)
{
	*this = other;
}

// Copy Assignment Operator
AMateria & AMateria::operator=(const AMateria & other)
{
	if (this != &other)
		this->_type = other._type;
	return (*this);
}

// Destructor
AMateria::~AMateria()
{
	// Nothing to do here
}

// Member functions
const std::string	&AMateria::getType() const
{
	return (this->_type);
}

void				AMateria::use(ICharacter & target)
{
	(void)target;
	// Not sure why I couldn't make this pure virtual
}