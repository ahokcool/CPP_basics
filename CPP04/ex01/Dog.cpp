/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 18:05:29 by astein            #+#    #+#             */
/*   Updated: 2024/04/02 13:24:05 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

// Default constructor
Dog::Dog() : Animal("Dog")
{
	std::cout << "Dog constructor called" << std::endl;
	_brain = new Brain();
}

// Copy constructor
Dog::Dog(const Dog &other) : Animal(other)
{
	std::cout << "Dog copy constructor called" << std::endl;
	*this = other;
}

// Destructor
Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	// No need to delete the brain sinde the animal destructor does it
	// if (this->_brain)
	//	delete this->_brain;
}

// Assignment operator overload
Dog		&Dog::operator=(const Dog &other)
{
	std::cout << "Dog assignment operator called" << std::endl;
	// No need to check for self assignment since the base class does it
	// and the derived class does not have any other members
	Animal::operator=(other);
    return *this;
}

// Member functions override
void	Dog::makeSound() const
{
	std::cout << CLR_BLUE <<
		"Woof Woof (type: " << _type << ")" <<
		CLR_RESET << std::endl;
	Animal::makeSound();
}
