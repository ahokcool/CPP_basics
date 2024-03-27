/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 18:05:18 by astein            #+#    #+#             */
/*   Updated: 2024/03/27 18:56:21 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

// Default constructor
Animal::Animal() : _type("Animal")
{
	std::cout << "Animal default constructor called" << std::endl;
	this->_brain = new Brain();
}

// Parameterized constructor
Animal::Animal(std::string type)
{
	std::cout << "Animal parameterized constructor called" << std::endl;
	this->_type = type;
	this->_brain = new Brain();
}

Animal::Animal(const Animal &other)
{
	std::cout << "Animal copy constructor called" << std::endl;
	this->_type = other._type;
	this->_brain = new Brain(*other._brain);
}

Animal &Animal::operator=(const Animal &other)
{
	std::cout << "Animal assignment operator called" << std::endl;
	if (this != &other)
	{
        this->_type = other._type;
		if(this->_brain)
			delete this->_brain;
		this->_brain = new Brain(*other._brain);	
	}
    return *this;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
	if(this->_brain)
		delete this->_brain;
}

std::string	Animal::getType() const
{
	return _type;
}

void 		Animal::setType(std::string type)
{
	std::cout << "Setting type to " << type << std::endl;
	_type = type;
}

void 		Animal::makeSound() const
{
	std::cout << "I have so many ideas:" << std::endl;
	this->print_ideas();
}

// Brain functions
void		Animal::setIdea(int i, std::string idea)
{
	std::cout << "Setting idea " << i << " to " << idea << std::endl;
	this->_brain->setIdea(i, idea);
}

std::string	Animal::getIdea(int i) const
{
	return this->_brain->getIdea(i);
}

void		Animal::print_ideas() const
{
	this->_brain->print_ideas();
}
