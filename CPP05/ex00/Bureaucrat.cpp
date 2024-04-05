/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 15:28:54 by astein            #+#    #+#             */
/*   Updated: 2024/04/05 17:42:58 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// Private default constructor, should not be used
Bureaucrat::Bureaucrat()
	throw(Bureaucrat::GradeTooHighException) :
	_name("NULL"),
	_grade(150)
{
	std::cout << CLR_RED <<
		"Bureaucrat default constructor called" << std::endl <<
		"No grade given aka grade is NULL an therefore too high!" <<
		std::endl << CLR_RST;
	throw Bureaucrat::GradeTooHighException();
}

// Parametric constructor
Bureaucrat::Bureaucrat(const std::string &name, unsigned int grade)
	throw(Bureaucrat::GradeTooHighException, Bureaucrat::GradeTooLowException) :
	_name(name)
{
	std::cout << "Bureaucrat parametric constructor called" << std::endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		_grade = grade;
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

// Overload of assignment operator
Bureaucrat 			&Bureaucrat::operator=(const Bureaucrat &other)
{
	std::cout << "Bureaucrat assignment operator called" << std::endl;
	if (this != &other)
	{
		_grade = other._grade;
	}
	return *this;
}

// Overload of increment operator
Bureaucrat 			&Bureaucrat::operator++(int)
	throw(Bureaucrat::GradeTooHighException)
{
	std::cout << "Bureaucrat increment operator called" << std::endl;
	if (_grade > 1)
		_grade--;
	else
		throw Bureaucrat::GradeTooHighException();
	return *this;
}

// Overload of decrement operator
Bureaucrat 			&Bureaucrat::operator--(int)
	throw(Bureaucrat::GradeTooLowException)
{
	std::cout << "Bureaucrat decrement operator called" << std::endl;
	if (_grade < 150)
		_grade++;
	else
		throw Bureaucrat::GradeTooLowException();
	return *this;
}

// Getters
const std::string 	&Bureaucrat::getName() const
{
	return _name;
}

unsigned int 		Bureaucrat::getGrade() const
{
	return _grade;
}

// Overload of insertion operator
std::ostream 		&operator<<(std::ostream &out, const Bureaucrat &b)
{
	out << CLR_BLU <<
		b.getName() << ", bureaucrat grade " <<
		b.getGrade() << "." <<
		CLR_RST << std::endl;
	return out;
}

// EXCEPTIONS
// GradeTooHighException
const char 			*Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

// GradeTooLowException
const char 			*Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}