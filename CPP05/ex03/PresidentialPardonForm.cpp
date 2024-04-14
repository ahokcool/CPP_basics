/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 20:20:02 by astein            #+#    #+#             */
/*   Updated: 2024/04/14 23:37:45 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PresidentialPardonForm.hpp"

// Constructors and destructor
// Private default constructor, should not be used
PresidentialPardonForm::PresidentialPardonForm() :
	AForm("PresidentialPardonForm", 25, 5)
{
	std::cout << "PresidentialPardonForm default constructor" << std::endl;	
}

// Parameterized constructor
PresidentialPardonForm::PresidentialPardonForm(const std::string &target) :
	AForm("PresidentialPardonForm", 25, 5, target)
{
	std::cout << "PresidentialPardonForm parameterized constructor" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) :
	AForm(other)
{
	std::cout << "PresidentialPardonForm copy constructor" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm destructor" << std::endl;
}

// Operator overloads
PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	std::cout << "PresidentialPardonForm assignment operator" << std::endl;
	AForm::operator=(other);
	return (*this);
}

// Base class pure virtual function override
void					PresidentialPardonForm::execute(const Bureaucrat &executor) const
	throw (	AForm::GradeTooLowException,
			AForm::FormNotSignedException)
{
	// check if it is executable
	if (!isExecutable(executor))
	{
		// I will never endup here because before the isExecutable() function
		// will return false, it will throw an exception, which needs to be
		// caught in the calling function aka main.cpp
	}
	else
	{
		// execute
		std::cout << CLR_TARGET << 
			_target << CLR_RST << 
			" has been pardoned by " << CLR_BLU <<
			"Zaphod Beeblebrox." << CLR_RST << std::endl;
	}
}
