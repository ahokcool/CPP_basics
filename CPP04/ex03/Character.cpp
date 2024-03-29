/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 01:21:49 by astein            #+#    #+#             */
/*   Updated: 2024/03/29 01:49:59 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "AMateria.hpp"

// Constructors
Character::Character() : _name("Default Name")
{
	for (int i = 0; i < 4; i++)
		this->_materia[i] = NULL;
}

Character::Character(const std::string name) : _name(name)
{
	for (int i = 0; i < 4; i++)
		this->_materia[i] = NULL;
}

// Copy Constructor
Character::Character(const Character &other)
{
	*this = other;
}

// Copy Assignment Operator
Character & Character::operator=(const Character &other)
{
	if (this != &other)
	{
		this->_name = other._name;
		for (int i = 0; i < 4; i++)
			this->_materia[i] = other._materia[i];
	}
	return *this;
}

// Destructor
Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_materia[i])
			delete this->_materia[i];
	}
}

// Member functions
const std::string	&Character::getName() const
{
	return (this->_name);
}

void				Character::equip(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!this->_materia[i])
		{
			this->_materia[i] = m;
			std::cout << "Materia equipped!" << std::endl;
			return ;
		}
	}
	std::cout << "Character's inventory is full!" << std::endl;
}

void				Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4)
	{
		std::cout << "Invalid index!" << std::endl;
		return ;
	}
	if (!this->_materia[idx])
	{
		std::cout << "No materia in this slot!" << std::endl;
		return ;
	}
	std::cout << "Materia " << _materia[idx]->getType() << " unequipped!" << std::endl;
	this->_materia[idx] = NULL;
}

void				Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx >= 4)
	{
		std::cout << "Invalid index!" << std::endl;
		return ;
	}
	if (!this->_materia[idx])
	{
		std::cout << "No materia in this slot!" << std::endl;
		return ;
	}
	this->_materia[idx]->use(target);
}
