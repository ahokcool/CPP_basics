/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 18:05:18 by astein            #+#    #+#             */
/*   Updated: 2024/04/02 13:23:22 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

// Default constructor
Animal::Animal() :
	_type("Animal"),
	_brain(NULL)
{
	std::cout << "Animal default constructor called" << std::endl;
}

// Parameterized constructor
Animal::Animal(const std::string &type) :
	_type(type),
	_brain(NULL)
{
	std::cout << "Animal parameterized constructor called" << std::endl;
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
	if(this->_brain)
		delete this->_brain;
}

// Assignment operator overload
Animal 		&Animal::operator=(const Animal &other)
{
	std::cout << "Animal assignment operator called" << std::endl;
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
std::string	Animal::getType() const
{
	return _type;
}

void 		Animal::setType(const std::string &type)
{
	std::cout << "Setting type to " << type << std::endl;
	_type = type;
}

void 		Animal::makeSound() const
{
	std::cout <<  CLR_RED <<
		"*Animal Noise* (type: " << _type << ")" <<
		CLR_RESET << std::endl;
	if (_brain)
	{
		std::cout << "I have so many ideas:" << std::endl;
		_brain->print_ideas();
	}
	else
		std::cout <<
			"Can have ideas since I don't have a brain - so sad!" <<
			std::endl;
}

// Brain related functions
void 		Animal::setIdea(const int index, const std::string &idea)
{
	if (_brain)
		_brain->setIdea(index, idea);
	else
		std::cout <<
			"Can't memorize the idea since I don't have a brain - so sad!" <<
			std::endl;
}
