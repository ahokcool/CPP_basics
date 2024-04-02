/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 01:21:49 by astein            #+#    #+#             */
/*   Updated: 2024/04/02 17:37:15 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "AMateria.hpp"

// Default Constructors
Character::Character() : _name("some random dude")
{
	for (int i = 0; i < 4; i++)
	{
		this->_materia[i] = NULL;
		std::cout << "\tSlot " << i << " set to NULL" << std::endl;
	}
	std::cout << "Default Character created!" << std::endl;
}

// Parameterized Constructors
Character::Character(const std::string &name) : _name(name)
{
	for (int i = 0; i < 4; i++)
	{
		this->_materia[i] = NULL;
		std::cout << "\tSlot " << i << " set to NULL" << std::endl;
	}
	std::cout << "Character '" << this->_name << "' created!" << std::endl;
}

// Copy Constructor
Character::Character(const Character &other)
{
	std::cout << "Character copy constructor called!" << std::endl;
	_name = other._name;
	for (int i = 0; i < 4; i++)
	{
		this->_materia[i] = NULL;
		std::cout << "\tSlot " << i << " set to NULL" << std::endl;
	}
	*this = other;
}

// Destructor
Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_materia[i])
		{
			delete this->_materia[i];
			this->_materia[i] = NULL;
		}
	}
	std::cout << "Character '" << this->_name << "' destroyed!" << std::endl;
}

// Copy Assignment Operator
Character 			&Character::operator=(const Character &other)
{
	std::cout << "Character copy assignment operator called!" << std::endl;
	if (this != &other)
	{
		this->_name = other._name;
		// delete existing materia
		for (int i = 0; i < 4; i++)
		{
			if (this->_materia[i])
			{
				delete this->_materia[i];
				this->_materia[i] = NULL;
			}
		}
		// deep copy materia of other
		for (int i = 0; i < 4; i++)
		{
			if (other._materia[i])
				this->_materia[i] = other._materia[i]->clone();
			else
				this->_materia[i] = NULL;
		}
	}
	else
		std::cout << "Self-assignment!" << std::endl;
	return *this;
}

// Member functions
const std::string	&Character::getName() const
{
	return (this->_name);
}

void				Character::equip(AMateria *m)
{
	if (!m)
	{
		std::cout << CLR_RED <<
			"Cannot equip a NULL materia!" <<
			CLR_RESET << std::endl;
		return ;
	}

	for (int i = 0; i < 4; i++)
	{
		if (!this->_materia[i])
		{
			this->_materia[i] = m;
			std::cout << CLR_GREEN
				"Materia equipped! Type: " << 
				m->getType() <<
				CLR_RESET << std::endl;
			return ;
		}
	}
	std::cout << CLR_RED <<
		"Character's inventory is full!" <<
		CLR_RESET << std::endl;
}

void				Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4)
	{
		std::cout << CLR_RED <<
			"Invalid index! (" << idx <<
			") - can't unequip" <<
			CLR_RESET << std::endl;
		return ;
	}
	if (!this->_materia[idx])
	{
		std::cout << CLR_RED <<
			"No materia in slot: " << idx <<
			" - can't unequip" <<
			CLR_RESET << std::endl;
		return ;
	}
	std::cout << CLR_YELLOW <<
		"Materia (" << _materia[idx]->getType() <<
		") in slot " << idx <<
		" successfully unequipped!" <<
		CLR_RESET << std::endl;
	this->_materia[idx] = NULL;
}

void				Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx >= 4)
	{
		std::cout << CLR_RED <<
			"Invalid index! (" << idx <<
			") - can't use materia!" <<
			CLR_RESET << std::endl;
		return ;
	}
	if (!this->_materia[idx])
	{
		std::cout << CLR_RED <<
			"No materia in slot: " << idx <<
			" - can't use materia!" <<
			CLR_RESET << std::endl;
		return ;
	}
	this->_materia[idx]->use(target);
}

// Getters
AMateria			*Character::getMateria(int idx) const
{
	std::cout << "Getting materia at index: " << idx << std::endl;
	if (idx < 0 || idx >= 4)
	{
		std::cout << CLR_RED <<
			"Invalid index! (" << idx <<
			") - can't get materia!" <<
			CLR_RESET << std::endl;
		return NULL;
	}
	if (!this->_materia[idx])
	{
		std::cout << CLR_RED <<
			"No materia in slot: " << idx <<
			" - can't get materia! (returning NULL)" <<
			CLR_RESET << std::endl;
		return NULL;
	}
	return this->_materia[idx];
}
