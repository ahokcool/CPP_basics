/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 18:05:18 by astein            #+#    #+#             */
/*   Updated: 2024/04/01 18:39:39 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

// Default constructor
Animal::Animal() : _type("Animal")
{
	std::cout << "Animal default constructor called" << std::endl;
}

// Parameterized constructor
Animal::Animal(std::string type)
{
	std::cout << "Animal parameterized constructor called" << std::endl;
	this->_type = type;
}

// Copy constructor
Animal::Animal(const Animal &other)
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = other;
}

// Destructor
Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

// Assignment operator overload
Animal 		&Animal::operator=(const Animal &other)
{
	std::cout << "Animal assignment operator called" << std::endl;
	if (this != &other)
        this->_type = other._type;
	else
		std::cout << "Self assignment" << std::endl;
    return *this;
}

// Member functions
std::string	Animal::getType() const
{
	return _type;
}

void 		Animal::setType(const std::string type)
{
	_type = type;
}

void 		Animal::makeSound() const
{
	std::cout << "Animal sound (type: " << _type << ")" << std::endl;
}
