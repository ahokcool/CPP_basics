/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 15:13:32 by astein            #+#    #+#             */
/*   Updated: 2024/04/01 22:32:49 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain constructor called" << std::endl;
	// Fill the brain with ideas
	for (int i = 0; i < 100; i++)
		_ideas[i] = "42";
}

Brain::Brain(const Brain &other)
{
	std::cout << "Brain copy constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		_ideas[i] = other._ideas[i];
}

Brain &Brain::operator=(const Brain &other)
{
	std::cout << "Brain assignation operator called" << std::endl;
	if (this == &other)
		return *this;
	for (int i = 0; i < 100; i++)
		_ideas[i] = other._ideas[i];
	return *this;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

// Member functions
std::string	Brain::getIdea(int i) const
{
	return _ideas[i];
}

void	Brain::setIdea(int i, std::string idea)
{
	_ideas[i] = idea;
}

void	Brain::print_ideas() const
{
	for (int i = 0; i < 100; i++)
	{
		 std::cout << "(" << std::setw(2) << std::setfill('0') << i << "): " << _ideas[i] << " |";
		if ((i+1) % 10 == 0)
			std::cout << std::endl;
	}
	std::cout << std::endl;
}
