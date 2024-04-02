/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 15:13:32 by astein            #+#    #+#             */
/*   Updated: 2024/04/02 20:51:26 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

// Default constructor
Brain::Brain()
{
	std::cout << "Brain constructor called" << std::endl;
	// Fill the brain with ideas
	for (int i = 0; i < 20; i++)
		_ideas[i] = "Zzz...";
}

// Copy constructor
Brain::Brain(const Brain &other)
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = other;
}

// Destructor
Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

// Assignment operator overload
Brain 		&Brain::operator=(const Brain &other)
{
	std::cout << "Brain equal operator called" << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 20; i++)
			_ideas[i] = other._ideas[i];
	}
	else
		std::cout << "Self assignment" << std::endl;
	return *this;
}

// Member functions
std::string	Brain::getIdea(const int i) const
{
	return _ideas[i];
}

void		Brain::setIdea(const int i, const std::string &idea)
{
	if (i < 0 || i >= 20)
		std::cout << "Invalid index aka my brain is too small" << std::endl;
	else
		_ideas[i] = idea;
}

void		Brain::print_ideas() const
{
	for (int i = 0; i < 20; i++)
	{
		std::cout << 
			"(" << std::setw(2) << std::setfill('0') << i << 
			"): " << 
			_ideas[i] << " |";
		if ((i+1) % 10 == 0)
			std::cout << std::endl;
	}
	std::cout << std::endl;
}
