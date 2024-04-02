/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 23:49:11 by astein            #+#    #+#             */
/*   Updated: 2024/04/02 12:34:31 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

// Default constructor
WrongAnimal::WrongAnimal() : _type("WrongAnimal")
{
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

// Parameterized constructor
WrongAnimal::WrongAnimal(const std::string &type)
{
	std::cout << "WrongAnimal parameterized constructor called" << std::endl;
	this->_type = type;
}

// Copy constructor
WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	*this = other;
}

// Destructor
WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

// Assignment operator overload
WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
	std::cout << "WrongAnimal assignment operator called" << std::endl;
	if (this != &other)
        this->_type = other._type;
    return *this;
}

// Member functions
std::string	WrongAnimal::getType() const
{
	return _type;
}

void 		WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal sound (type: " << _type << ")" << std::endl;
}
