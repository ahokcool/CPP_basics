/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 18:05:25 by astein            #+#    #+#             */
/*   Updated: 2024/04/01 22:42:47 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// Default constructor
Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat constructor called" << std::endl;
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
}

// Assignment operator overload
Cat &Cat::operator=(const Cat &other)
{
	std::cout << "Cat assignment operator called" << std::endl;
	Animal::operator=(other);
    return *this;
}

void Cat::makeSound() const
{
	std::cout << "Meow Meow (type: " << _type << ")" << std::endl;
	Animal::makeSound();
}
