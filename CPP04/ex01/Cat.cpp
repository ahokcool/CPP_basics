/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 18:05:25 by astein            #+#    #+#             */
/*   Updated: 2024/04/02 13:23:46 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// Default constructor
Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat constructor called" << std::endl;
	_brain = new Brain();
}

// Copy constructor
Cat::Cat(const Cat &other) : Animal(other)
{
	std::cout << "Cat copy constructor called" << std::endl;
	*this = other;
}

// Destructor
Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	// No need to delete the brain sinde the animal destructor does it
	// if (this->_brain)
	//	delete this->_brain;
}

// Assignment operator overload
Cat 	&Cat::operator=(const Cat &other)
{
	std::cout << "Cat assignment operator called" << std::endl;
	// No need to check for self assignment since the base class does it
	// and the derived class does not have any other members
	Animal::operator=(other);
    return *this;
}

// Member functions override
void 	Cat::makeSound() const
{
	std::cout << CLR_CYAN <<
		"Meow Meow (type: " << _type << ")" <<
		CLR_RESET << std::endl;
	Animal::makeSound();
}
