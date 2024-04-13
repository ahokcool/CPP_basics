/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 18:56:59 by astein            #+#    #+#             */
/*   Updated: 2024/04/11 13:58:15 by astein           ###   ########.fr       */
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
	throw(Bureaucrat::GradeTooHighException, Bureaucrat::GradeTooLowException) :
	_name(name),
	_gradeToSign(gradeToSign),
	_gradeToExecute(gradeToExecute),
	_signed(false)
{
	if (gradeToSign < 1)
		throw Bureaucrat::GradeTooHighException("Cannot create a form with a 'gradeToSign' higher than 1!");
	if (gradeToSign > 150)
		throw Bureaucrat::GradeTooLowException("Cannot create a form with a 'gradeToSign' lower than 150!");
	if (gradeToExecute < 1)
		throw Bureaucrat::GradeTooHighException("Cannot create a form with a 'gradeToExecute' higher than 1!");
	if (gradeToExecute > 150)
		throw Bureaucrat::GradeTooLowException("Cannot create a form with a 'gradeToExecute' lower than 150!");
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

//		MEMBER FUNCTIONS
// -----------------------------------------------------------------------------
void				Form::beSigned(const Bureaucrat &bureaucrat)
	throw(Form::GradeTooLowException)
{
	if (bureaucrat.getGrade() > _gradeToSign)
	{
		// Not sure if I should print an message here or just throw the exception
		std::cout <<
			"The grade of the bureaucrat " << CLR_CLERK <<
			bureaucrat.getName() << CLR_RST <<
			" is too low to sign this form " << CLR_FRM <<
			_name << CLR_RST << 
			"(" << CLR_GRADE <<
			bureaucrat.getGrade() << CLR_RST <<
			" < " << CLR_GRADE <<
			_gradeToSign << CLR_RST <<
			")!" << std::endl;
		throw Form::GradeTooLowException();
	}
	if (_signed)
		std::cout <<
			"The form " << CLR_FRM <<
			_name << CLR_RST <<
			" cannot be signed by " <<  CLR_CLERK <<
			bureaucrat.getName() << CLR_RST <<
			" because the form is already signed!" <<
			CLR_RST << std::endl;
	else
	{
		_signed = true;
		std::cout <<
			"The form " << CLR_FRM <<
			_name << CLR_RST <<
			" was signed by " <<  CLR_CLERK <<
			bureaucrat.getName() << CLR_RST << "!" << std::endl;
	}
}

// 		EXCEPTIONS
// -----------------------------------------------------------------------------
const char			*Form::GradeTooLowException::what() const throw()
{
	return "The grade of the bureaucrat is too low to sign this form!";
}

// Insertion operator overload
std::ostream					&operator<<(std::ostream &os, const Form &form)
{
	const int 		columnWidth = 40;
    std::string 	name = form.getName();
    const int 		nameWidth = columnWidth - 4;

    // Truncate the name if it's too long
    if (name.length() > nameWidth)
        name = name.substr(0, nameWidth - 3) + "...";

    // Prepare the border based on the fixed column width
    std::string 	border = " # " + std::string(columnWidth - 4, '=') + " #";

    os << border << std::endl
       << " # " << CLR_FRM << std::setw(nameWidth) << std::left << name << CLR_RST << std::right << " # " << std::endl
       << border << std::endl
       << " # Grade to sign:      " << CLR_GRADE << std::setw(columnWidth-24) << std::left << form.getGradeToSign() << CLR_RST << " # " << std::endl
       << " # Grade to execute:   " << CLR_GRADE << std::setw(columnWidth-24) << std::left << form.getGradeToExecute() << CLR_RST << " # " << std::endl;
	if (form.getSigned())
       os << " # Signed:             " << CLR_GRN << std::setw(columnWidth-24) << std::left << "X" << CLR_RST << " # " << std::endl << border << std::endl;
	else
		os << " # Signed:             " << CLR_RED << std::setw(columnWidth-24) << std::left << "O" << CLR_RST << " # " << std::endl << border << std::endl;
    return os;
}
