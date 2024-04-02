/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 18:05:18 by astein            #+#    #+#             */
/*   Updated: 2024/04/02 13:45:40 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

// Default constructor
AAnimal::AAnimal() :
	_type("Animal"),
	_brain(NULL)
{
	std::cout << "AAnimal default constructor called" << std::endl;
}

// Parameterized constructor
AAnimal::AAnimal(const std::string &type) :
	_type(type),
	_brain(NULL)
{
	std::cout << "AAnimal parameterized constructor called" << std::endl;
}

// Copy constructor
AAnimal::AAnimal(const AAnimal &other)
{
	std::cout << "AAnimal copy constructor called" << std::endl;
	*this = other;
}

// Destructor
AAnimal::~AAnimal()
{
	std::cout << "AAnimal destructor called" << std::endl;
	if(this->_brain)
		delete this->_brain;
}

// Assignment operator overload
AAnimal 	&AAnimal::operator=(const AAnimal &other)
{
	std::cout << "AAnimal assignment operator called" << std::endl;
	if (this != &other)
	{
        this->_type = other._type;
		if(this->_brain)
			delete this->_brain;
		if (other._brain)
			this->_brain = new Brain(*other._brain);
		else
			this->_brain = NULL;
	}
	else
		std::cout << "Self assignment" << std::endl;
    return *this;
}

// Member functions
std::string	AAnimal::getType() const
{
	return _type;
}

void 		AAnimal::setType(const std::string &type)
{
	std::cout << "Setting type to " << type << std::endl;
	_type = type;
}

// Brain related functions
void		AAnimal::setIdea(const int index, const std::string &idea)
{
	if (_brain)
		_brain->setIdea(index, idea);
	else
		std::cout <<
			"Can't memorize the idea since I don't have a brain - so sad!" <<
			std::endl;
}
