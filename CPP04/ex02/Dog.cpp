/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 18:05:29 by astein            #+#    #+#             */
/*   Updated: 2024/04/02 13:50:59 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

// Default constructor
Dog::Dog() : AAnimal("Dog")
{
	std::cout << "Dog constructor called" << std::endl;
	_brain = new Brain();
}

// Copy constructor
Dog::Dog(const Dog &other) : AAnimal(other)
{
	std::cout << "Dog copy constructor called" << std::endl;
	*this = other;
}

// Destructor
Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	// No need to delete the brain sinde the AAnimal destructor does it
	// if (this->_brain)
	//	delete this->_brain;
}

// Assignment operator overload
Dog		&Dog::operator=(const Dog &other)
{
	std::cout << "Dog assignment operator called" << std::endl;
	// No need to check for self assignment since the base class does it
	// and the derived class does not have any other members
	AAnimal::operator=(other);
    return *this;
}

// Member functions override
void	Dog::makeSound() const
{
	std::cout << CLR_BLUE <<
		"Woof Woof (type: " << _type << ")" <<
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
