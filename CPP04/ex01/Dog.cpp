/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 18:05:29 by astein            #+#    #+#             */
/*   Updated: 2024/04/01 22:44:56 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

// Default constructor
Dog::Dog() : Animal("Dog")
{
	std::cout << "Dog constructor called" << std::endl;
}

// Copy constructor
Dog::Dog(const Dog &other) : Animal(other)
{
	std::cout << "Dog copy constructor called" << std::endl;
}

// Destructor
Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}

// Assignment operator overload
Dog 	&Dog::operator=(const Dog &other)
{
	std::cout << "Dog assignment operator called" << std::endl;
	Animal::operator=(other);
    return *this;
}


void 	Dog::makeSound() const
{
	std::cout << "Woof Woof (type: " << _type << ")" << std::endl;
	Animal::makeSound();
}
