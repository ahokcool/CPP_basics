/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 20:36:55 by astein            #+#    #+#             */
/*   Updated: 2024/04/13 21:17:52 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Intern.hpp"

// Constructors and destructor
Intern::Intern()
{
	std::cout << "Intern default constructor called" << std::endl;	
}

Intern::Intern(const Intern &other)
{
	std::cout << "Intern copy constructor called" << std::endl;
	*this = other;
}

Intern::~Intern()
{
	std::cout << "Intern destructor called" << std::endl;
}

// Operator overloads
Intern		&Intern::operator=(const Intern &other)
{
	std::cout << "Intern assignment operator called" << std::endl;
	// Nothing to do here
	(void)other;
	return (*this);
}

// Member functions
AForm		*Intern::makeForm(const std::string &formName, const std::string &target) const
{
	if (formName == "ShrubberyCreationForm")
	{
		std::cout << "Intern creates " << CLR_FORM <<
		formName << CLR_RST << std::endl;
		return (new ShrubberyCreationForm(target));
	}
	else if (formName == "RobotomyRequestForm")
	{
		std::cout << "Intern creates " << CLR_FORM <<
		formName << CLR_RST << std::endl;
		return (new RobotomyRequestForm(target));
	}
	else if (formName == "PresidentialPardonForm")
	{
		std::cout << "Intern creates " << CLR_FORM <<
		formName << CLR_RST << std::endl;
		return (new PresidentialPardonForm(target));
	}
	else
	{
		std::cout << CLR_RED <<
			"The intern is overwhelmed and doesn't know how to create this form: " <<
			formName << CLR_RST << std::endl;
		return (NULL);
	}
}