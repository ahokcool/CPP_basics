/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 00:29:47 by astein            #+#    #+#             */
/*   Updated: 2024/04/02 15:11:51 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

// Default constructor
MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource default constructor called!" << std::endl;
	for (int i = 0; i < 4; i++)
		_materias[i] = NULL;
}

// Copy constructor
MateriaSource::MateriaSource(const MateriaSource &other)
{
	std::cout << "MateriaSource copy constructor called!" << std::endl;
	*this = other;
}

// Destructor
MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource destructor called!" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (_materias[i])
			delete _materias[i];
	}
}

// Copy assignment operator
MateriaSource	&MateriaSource::operator=(const MateriaSource &other)
{
	std::cout << "MateriaSource copy assignment operator called!" << std::endl;
	if (this != &other)
	{
		// Create deep copy of other's materia
		for (int i = 0; i < 4; i++)
		{
			if (this->_materias[i])
				delete _materias[i];
			if (other._materias[i])
				this->_materias[i] = other._materias[i]->clone();
			else
				this->_materias[i] = NULL;
		}
	}
	return *this;
}

// Member functions
void		MateriaSource::learnMateria(AMateria *materia)
{
	if (!materia)
	{
		std::cout << CLR_RED <<
			"Cannot learn a NULL materia!" <<
			CLR_RESET << std::endl;
		return ;
	}
	for (int i = 0; i < 4; i++)
	{
		if (!_materias[i])
		{
			_materias[i] = materia;
			std::cout << CLR_GREEN <<
				"Materia learned!" <<
				CLR_RESET << std::endl;
			return ;
		}
	}
	std::cout << CLR_RED <<
		"Can't learm Materia: " <<  materia->getType() <<
		" since MateriaSource is full!" <<
		CLR_RESET << std::endl;
}

AMateria	*MateriaSource::createMateria(const std::string &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (_materias[i] && _materias[i]->getType() == type)
		{
			std::cout << CLR_GREEN <<
			"Materia with type: " << type <<
			" created!" <<
			CLR_RESET << std::endl;
			return _materias[i]->clone();
		}
	}
	std::cout << CLR_RED
		"Materia: " << type <<
		"couldn't be created since it wasn't learned!" <<
		CLR_RESET << std::endl;
	return 0;
}
