/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 15:28:54 by astein            #+#    #+#             */
/*   Updated: 2024/04/06 00:10:27 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// 		CONSTRUCTORS AND DESTRUCTOR
// -----------------------------------------------------------------------------
// Private default constructor, should not be used
Bureaucrat::Bureaucrat()
	throw(GradeTooHighException) :
	_name("some random guy working in an random office"),
	_grade(150)
{
	std::cout << CLR_RED <<
		"Bureaucrat default constructor called" << std::endl <<
		"No grade given aka grade is NULL an therefore too high!" <<
		std::endl << CLR_RST;
	throw GradeTooHighException();
}

// Parametric constructor
Bureaucrat::Bureaucrat(const std::string &name, unsigned int grade)
	throw(GradeTooHighException, GradeTooLowException) :
	_name(name),
	_grade(grade)
{
	std::cout << "Bureaucrat parametric constructor called" << std::endl;
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
}

// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat &other) :
	_name(other._name),
	_grade(other._grade)
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
}

// Destructor
Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}

// 		OPERATOR OVERLOADS
// -----------------------------------------------------------------------------
// Overload of assignment operator
Bureaucrat 			&Bureaucrat::operator=(const Bureaucrat &other)
{
	std::cout << "Bureaucrat assignment operator called" << std::endl;
	if (this != &other)
	{
		_grade = other._grade;
		// _name = other._name; // _name is const
	}
	return *this;
}

// Overload of PREFIX increment operator (++b)
Bureaucrat 			&Bureaucrat::operator++()
	throw(GradeTooHighException)
{
	std::cout << "Bureaucrat PREFIX increment operator called (++b)" << std::endl;
	if (_grade > 1)
		_grade--;
	else
		throw GradeTooHighException();
	return *this;
}

// Overload of POSTFIX increment operator (b++)
Bureaucrat 			Bureaucrat::operator++(int)
	throw(GradeTooHighException)
{
	std::cout << "Bureaucrat POSTFIX increment operator called (b++)" << std::endl;
	Bureaucrat tmp(*this);
	if (_grade > 1)
		_grade--;
	else
		throw GradeTooHighException();
	return tmp;
}

// Overload of PREFIX decrement operator (--b)
Bureaucrat 			&Bureaucrat::operator--()
	throw(GradeTooLowException)
{
	std::cout << "Bureaucrat PREFIX decrement operator called (--b)" << std::endl;
	if (_grade < 150)
		_grade++;
	else
		throw GradeTooLowException();
	return *this;
}

// Overload of POSTFIX decrement operator (b--)
Bureaucrat 			Bureaucrat::operator--(int)
	throw(GradeTooLowException)
{
	std::cout << "Bureaucrat POSTFIX decrement operator called (b--)" << std::endl;
	Bureaucrat tmp(*this);
	if (_grade < 150)
		_grade++;
	else
		throw GradeTooLowException();
	return tmp;
}

// 		GETTERS
// -----------------------------------------------------------------------------
const std::string 	&Bureaucrat::getName() const
{
	return _name;
}

unsigned int 		Bureaucrat::getGrade() const
{
	return _grade;
}


// 		EXCEPTIONS
// -----------------------------------------------------------------------------
// GradeTooHighException
const char 			*GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

// GradeTooLowException
const char 			*GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

// OVERLOAD OF INSERTION OPERATOR
// -----------------------------------------------------------------------------
std::ostream 		&operator<<(std::ostream &out, const Bureaucrat &b)
{
	out << CLR_BLU <<
		" # Hello, I am " << CLR_BLD << CLR_GRN <<
		b.getName() << CLR_RST << CLR_BLU <<
		", and my grade is " << CLR_BLD << CLR_GRN <<
		b.getGrade() << CLR_RST << CLR_BLU << " #" << std::endl <<
		CLR_RST << std::endl;
	return out;
}