/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 20:36:55 by astein            #+#    #+#             */
/*   Updated: 2024/04/13 21:36:46 by astein           ###   ########.fr       */
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
AForm		*Intern::createS(std::string target) const
{
	return new ShrubberyCreationForm(target);
}

AForm		*Intern::createR(std::string target) const
{
	return new RobotomyRequestForm(target);
}

AForm		*Intern::createP(std::string target) const
{
	return new PresidentialPardonForm(target);
}



AForm		*Intern::makeForm(const std::string &formName, const std::string &target) const
{
	std::string form_names[3] =
	{
		"ShrubberyCreationForm",
		"RobotomyRequestForm",
		"PresidentialPardonForm"
	};

	AForm	*(Intern::*form_funcs[3])(const std::string target) const =
	{
		&Intern::createS,
		&Intern::createR,
		&Intern::createP
	};
	
	for (int i = 0; i < 3; i++)
	{
		if (formName == form_names[i])
		{
			std::cout <<
				"Intern creates " << CLR_FORM <<
				formName << 
				"..." CLR_RST << std::endl;
			return (this->*form_funcs[i])(target);
		}
	}
	std::cout << CLR_RED <<
		"The intern is overwhelmed and doesn't know how to create this form: " <<
		formName << CLR_RST << std::endl;
	return (NULL);
}