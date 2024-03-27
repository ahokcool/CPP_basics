/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 18:05:18 by astein            #+#    #+#             */
/*   Updated: 2024/03/27 19:03:35 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

// Default constructor
AAnimal::AAnimal() : _type("Animal")
{
	std::cout << "AAnimal default constructor called" << std::endl;
	this->_brain = new Brain();
}

// Parameterized constructor
AAnimal::AAnimal(std::string type)
{
	std::cout << "AAnimal parameterized constructor called" << std::endl;
	this->_type = type;
	this->_brain = new Brain();
}

AAnimal::AAnimal(const AAnimal &other)
{
	std::cout << "AAnimal copy constructor called" << std::endl;
	this->_type = other._type;
	this->_brain = new Brain(*other._brain);
}

AAnimal &AAnimal::operator=(const AAnimal &other)
{
	std::cout << "AAnimal assignment operator called" << std::endl;
	if (this != &other)
	{
        this->_type = other._type;
		if(this->_brain)
			delete this->_brain;
		this->_brain = new Brain(*other._brain);	
	}
    return *this;
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal destructor called" << std::endl;
	if(this->_brain)
		delete this->_brain;
}

std::string	AAnimal::getType() const
{
	return _type;
}

void 		AAnimal::setType(std::string type)
{
	std::cout << "Setting type to " << type << std::endl;
	_type = type;
}

void 		AAnimal::makeSound() const
{
	std::cout << "I have so many ideas:" << std::endl;
	this->print_ideas();
}

// Brain functions
void		AAnimal::setIdea(int i, std::string idea)
{
	std::cout << "Setting idea " << i << " to " << idea << std::endl;
	this->_brain->setIdea(i, idea);
}

std::string	AAnimal::getIdea(int i) const
{
	return this->_brain->getIdea(i);
}

void		AAnimal::print_ideas() const
{
	this->_brain->print_ideas();
}
