/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 13:17:02 by astein            #+#    #+#             */
/*   Updated: 2024/04/09 17:45:02 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ShrubberyCreationForm.hpp"

// Constructors and destructor
// Private default constructor, should not be used
ShrubberyCreationForm::ShrubberyCreationForm() :
	AForm("ShrubberyCreationForm", 145, 137)
{
	std::cout << "ShrubberyCreationForm default constructor" << std::endl;	
}

// Parameterized constructor
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) :
	AForm("ShrubberyCreationForm", 145, 137, target)
{
	std::cout << "ShrubberyCreationForm parameterized constructor" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) :
	AForm(other)
{
	std::cout << "ShrubberyCreationForm copy constructor" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor" << std::endl;
}

// Operator overloads
ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	std::cout << "ShrubberyCreationForm assignment operator" << std::endl;
	AForm::operator=(other);
	return (*this);
}

// Member functions
void					ShrubberyCreationForm::createShrubbery() const
{
	// TODO:

	// AForm::execute(executor);
	// std::ofstream file(getName() + "_shrubbery");
	// if (!file.is_open())
	// 	throw std::runtime_error("Could not open file");
	// file << "      /\\      " << std::endl;
	// file << "     /\\*\\     " << std::endl;
	// file << "    /\\O\\*\\    " << std::endl;
	// file << "   /*/\\/\\/\\   " << std::endl;
	// file << "  /\\O\\/\\*\\/\\  " << std::endl;
	// file << " /\\*\\/\\*\\/\\/\\ " << std::endl;
	// file << "/\\O\\/\\/*/\\/O/\\" << std::endl;
	// file << "      ||      " << std::endl;
	// file << "      ||      " << std::endl;
	// file << "      ||      " << std::endl;
	// file << std::endl;
	// file.close();
}

void					ShrubberyCreationForm::execute(Bureaucrat const &executor) const
	throw (AForm::GradeTooLowException, AForm::FormNotSignedException)
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
		std::cout << "ShrubberyCreationForm is being executed" << std::endl;
		createShrubbery();
	}
}
