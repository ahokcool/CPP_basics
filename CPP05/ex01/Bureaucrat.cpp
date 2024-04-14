/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 15:28:54 by astein            #+#    #+#             */
/*   Updated: 2024/04/14 23:18:42 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

// 		CONSTRUCTORS AND DESTRUCTOR
// -----------------------------------------------------------------------------
// Private default constructor, should not be used
Bureaucrat::Bureaucrat()
	throw(Bureaucrat::GradeTooHighException) :
	_name("some random guy working in an random office"),
	_grade(150)
{
	std::cout << CLR_RED <<
		"Bureaucrat default constructor called" << std::endl <<
		"No grade given aka grade is NULL an therefore too high!" <<
		std::endl << CLR_RST;
	throw Bureaucrat::GradeTooHighException("Cannot create a Bureaucrat without a grade!");
}

// Parametric constructor
Bureaucrat::Bureaucrat(const std::string &name, unsigned int grade)
	throw(Bureaucrat::GradeTooHighException, GradeTooLowException) :
	_name(name),
	_grade(grade)
{
	std::cout << "Bureaucrat parametric constructor called" << std::endl;
	if (grade < 1)
		throw GradeTooHighException("Cannot create a Bureaucrat with a grade lower than 1!");
	else if (grade > 150)
		throw GradeTooLowException("Cannot create a Bureaucrat with a grade higher than 150!");
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
	throw(Bureaucrat::GradeTooHighException)
{
	std::cout << "Bureaucrat PREFIX increment operator called (++b)" << std::endl;
	if (_grade > 1)
		_grade--;
	else
		throw GradeTooHighException("Cannot increment bureaucrats grade, it is already at the highest level aka 1!");
	return *this;
}

// Overload of POSTFIX increment operator (b++)
Bureaucrat 			Bureaucrat::operator++(int)
	throw(Bureaucrat::GradeTooHighException)
{
	std::cout << "Bureaucrat POSTFIX increment operator called (b++)" << std::endl;
	Bureaucrat tmp(*this);
	if (_grade > 1)
		_grade--;
	else
		throw GradeTooHighException("Cannot increment bureaucrats grade, it is already at the highest level aka 1!");
	return tmp;
}

// Overload of PREFIX decrement operator (--b)
Bureaucrat 			&Bureaucrat::operator--()
	throw(Bureaucrat::GradeTooLowException)
{
	std::cout << "Bureaucrat PREFIX decrement operator called (--b)" << std::endl;
	if (_grade < 150)
		_grade++;
	else
		throw GradeTooLowException("Cannot decrement bureaucrats grade, it is already at the lowest level aka 150!");
	return *this;
}

// Overload of POSTFIX decrement operator (b--)
Bureaucrat 			Bureaucrat::operator--(int)
	throw(Bureaucrat::GradeTooLowException)
{
	std::cout << "Bureaucrat POSTFIX decrement operator called (b--)" << std::endl;
	Bureaucrat tmp(*this);
	if (_grade < 150)
		_grade++;
	else
		throw GradeTooLowException("Cannot decrement bureaucrats grade, it is already at the lowest level aka 150!");
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

// 		MEMBER FUNCTIONS
// -----------------------------------------------------------------------------
void				Bureaucrat::signForm(Form &form) const
{
	try
	{
		form.beSigned(*this);
		std::cout << CLR_CLERK <<
			_name << CLR_RST <<
			" signs " << CLR_FORM <<
			form.getName() << CLR_RST << std::endl;
	}
	catch (const Form::GradeTooLowException &e)
	{
		std::cout << CLR_CLERK << 
			_name << CLR_RED <<
			" cannot sign " << CLR_FORM <<
			form.getName() << CLR_RST <<
			" because: " << CLR_RED <<
			e.what() <<
			CLR_RST << std::endl;
	}
}

// 		EXCEPTIONS
// -----------------------------------------------------------------------------
// GradeTooHighException
Bureaucrat::GradeTooHighException::GradeTooHighException(const std::string &msg) throw()
{
	if (msg.empty())
		_msg = "Grade is too high!";
	else
		_msg = "Grade is too high: " + msg;
}
 
const char 			*Bureaucrat::GradeTooHighException::what() const throw()
{
	return _msg.c_str();
}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw()
{
	// nothing to do here
}

// GradeTooLowException
Bureaucrat::GradeTooLowException::GradeTooLowException(const std::string &msg) throw()
{
	if (msg.empty())
		_msg = "Grade is too low!";
	else
		_msg = "Grade is too low: " + msg;
}

const char 			*Bureaucrat::GradeTooLowException::what() const throw()
{
	return _msg.c_str();
}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw()
{
	// nothing to do here
}

// OVERLOAD OF INSERTION OPERATOR
// -----------------------------------------------------------------------------
std::ostream 		&operator<<(std::ostream &out, const Bureaucrat &b)
{
	out <<
		" ### Hello, I am " << CLR_RST << CLR_CLERK <<
		b.getName() << CLR_RST << 
		", and my grade is " << CLR_RST << CLR_GRADE <<
		b.getGrade() << CLR_RST << " ###" <<
		std::endl;
	return out;
}
