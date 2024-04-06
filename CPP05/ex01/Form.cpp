/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 18:56:59 by astein            #+#    #+#             */
/*   Updated: 2024/04/06 01:17:56 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Form.hpp"

// 		CONSTRUCTORS AND DESTRUCTOR
// -----------------------------------------------------------------------------
// Private default constructor, should not be used
Form::Form() :
	_name("some random form"),
	_gradeToSign(1),
	_gradeToExecute(1),
	_signed(false)
{
	std::cout << CLR_RED <<
		"Form default constructor called" << std::endl <<
		"No grade so it was set to the highest possible grade!" <<
		std::endl << CLR_RST;
}

// Parameterized constructor
Form::Form(const std::string &name, unsigned int gradeToSign, unsigned int gradeToExecute)
	throw(GradeTooHighException, GradeTooLowException) :
	_name(name),
	_gradeToSign(gradeToSign),
	_gradeToExecute(gradeToExecute),
	_signed(false)
{
	if (gradeToSign < 1)
		throw GradeTooHighException("Cannot create a form with a 'gradeToSign' higher than 1!");
	if (gradeToSign > 150)
		throw GradeTooLowException("Cannot create a form with a 'gradeToSign' lower than 150!");
	if (gradeToExecute < 1)
		throw GradeTooHighException("Cannot create a form with a 'gradeToExecute' higher than 1!");
	if (gradeToExecute > 150)
		throw GradeTooLowException("Cannot create a form with a 'gradeToExecute' lower than 150!");
}

// Copy constructor
Form::Form(const Form &other) :
	_name(other._name),
	_gradeToSign(other._gradeToSign),
	_gradeToExecute(other._gradeToExecute),
	_signed(other._signed)
{
	std::cout << "Form copy constructor called" << std::endl;
}

// Destructor
Form::~Form()
{
	std::cout << "Form destructor called" << std::endl;
}

// 		OPERATOR OVERLOADS
// -----------------------------------------------------------------------------
// Overload of assignment operator
Form				&Form::operator=(const Form &other)
{
	std::cout << "Form assignment operator called..." << std::endl;
	if (this != &other)
	{
		// _gradeToSign = other._gradeToSign;		// doesn't work cause const
		// _gradeToExecute = other._gradeToExecute;	// doesn't work cause const
		// _name = other._name; 					// doesn't work cause const
		// _signed = other._signed;					// by design I think this doesn't make sense
		std::cout << "...no attributes to assign!" << std::endl;
	}
	else
		std::cout << "...with self assignment" << std::endl;
	return *this;
}

// 		GETTERS
// -----------------------------------------------------------------------------
const std::string	&Form::getName() const
{
	return _name;
}

unsigned int		Form::getGradeToSign() const
{
	return _gradeToSign;
}

unsigned int		Form::getGradeToExecute() const
{
	return _gradeToExecute;
}

bool				Form::getSigned() const
{
	return _signed;
}

// Insertion operator overload
std::ostream					&operator<<(std::ostream &os, const Form &form)
{
	os << CLR_BLU <<
		" #===============================================" << std::endl <<
		" #\tFORM NAME:\t" << form.getName() << std::endl <<
		" #===============================================" << std::endl <<
		" # -> Grade to sign:\t" << form.getGradeToSign() << std::endl <<
		" # -> Grade to execute:\t" << form.getGradeToExecute() << std::endl <<
		" # -> Signed:\t\t" << std::boolalpha << form.getSigned() << std::endl <<
		" #===============================================" << std::endl <<
		CLR_RST << std::endl;
	return os;
}
