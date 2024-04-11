/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 18:56:59 by astein            #+#    #+#             */
/*   Updated: 2024/04/11 14:00:09 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "AForm.hpp"

// 		CONSTRUCTORS AND DESTRUCTOR
// -----------------------------------------------------------------------------
// Private default constructor, should not be used
AForm::AForm() :
	_name("some random AForm"),
	_gradeToSign(1),
	_gradeToExecute(1),
	_signed(false),
	_target("*no target specified*")
{
	std::cout << CLR_RED <<
		"AForm default constructor called" << std::endl <<
		"No grade provided, so it was set to the highest possible grade!" <<
		std::endl << CLR_RST;
}

// Parameterized constructor
AForm::AForm(const std::string &name, unsigned int gradeToSign, unsigned int gradeToExecute)
	throw(Bureaucrat::GradeTooHighException, Bureaucrat::GradeTooLowException) :
	_name(name),
	_gradeToSign(gradeToSign),
	_gradeToExecute(gradeToExecute),
	_signed(false),
	_target("*no target specified*")
{
	if (gradeToSign < 1)
		throw Bureaucrat::GradeTooHighException("Cannot create a AForm with a 'gradeToSign' higher than 1!");
	if (gradeToSign > 150)
		throw Bureaucrat::GradeTooLowException("Cannot create a AForm with a 'gradeToSign' lower than 150!");
	if (gradeToExecute < 1)
		throw Bureaucrat::GradeTooHighException("Cannot create a AForm with a 'gradeToExecute' higher than 1!");
	if (gradeToExecute > 150)
		throw Bureaucrat::GradeTooLowException("Cannot create a AForm with a 'gradeToExecute' lower than 150!");
}

// Parameterized constructor including the target
AForm::AForm(const std::string &name, unsigned int gradeToSign, unsigned int gradeToExecute, const std::string &target)
	throw(Bureaucrat::GradeTooHighException, Bureaucrat::GradeTooLowException) :
	_name(name),
	_gradeToSign(gradeToSign),
	_gradeToExecute(gradeToExecute),
	_signed(false),
	_target(target)
{
	if (gradeToSign < 1)
		throw Bureaucrat::GradeTooHighException("Cannot create a AForm with a 'gradeToSign' higher than 1!");
	if (gradeToSign > 150)
		throw Bureaucrat::GradeTooLowException("Cannot create a AForm with a 'gradeToSign' lower than 150!");
	if (gradeToExecute < 1)
		throw Bureaucrat::GradeTooHighException("Cannot create a AForm with a 'gradeToExecute' higher than 1!");
	if (gradeToExecute > 150)
		throw Bureaucrat::GradeTooLowException("Cannot create a AForm with a 'gradeToExecute' lower than 150!");
}

// Copy constructor
AForm::AForm(const AForm &other) :
	_name(other._name),
	_gradeToSign(other._gradeToSign),
	_gradeToExecute(other._gradeToExecute),
	_signed(other._signed),
	_target(other._target)
{
	std::cout << "AForm copy constructor called" << std::endl;
}

// Destructor
AForm::~AForm()
{
	std::cout << "AForm destructor called" << std::endl;
}

// 		OPERATOR OVERLOADS
// -----------------------------------------------------------------------------
// Overload of assignment operator
AForm				&AForm::operator=(const AForm &other)
{
	std::cout << "AForm assignment operator called..." << std::endl;
	if (this != &other)
	{
		// _gradeToSign = other._gradeToSign;		// doesn't work cause const
		// _gradeToExecute = other._gradeToExecute;	// doesn't work cause const
		// _name = other._name; 					// doesn't work cause const
		// _target = other._target;					// doesn't work cause const	
		// _signed = other._signed;					// by design I think this doesn't make sense
		std::cout << "...no attributes to assign!" << std::endl;
	}
	else
		std::cout << "...with self assignment" << std::endl;
	return *this;
}

// 		GETTERS
// -----------------------------------------------------------------------------
const std::string	&AForm::getName() const
{
	return _name;
}

unsigned int		AForm::getGradeToSign() const
{
	return _gradeToSign;
}

unsigned int		AForm::getGradeToExecute() const
{
	return _gradeToExecute;
}

bool				AForm::getSigned() const
{
	return _signed;
}

//		MEMBER FUNCTIONS
// -----------------------------------------------------------------------------
std::ostream		&AForm::print(std::ostream& os) const
{
	const int 		columnWidth = 40;
    std::string 	name = this->getName();
    const int 		nameWidth = columnWidth - 4;

    // Truncate the name if it's too long
    if (name.length() > nameWidth)
        name = name.substr(0, nameWidth - 3) + "...";

    // Prepare the border based on the fixed column width
    std::string 	border = " # " + std::string(columnWidth - 4, '=') + " #";

    os << border << std::endl
       << " # " << CLR_FORM << std::setw(nameWidth) << std::left << name << CLR_RST << std::right << " # " << std::endl
       << border << std::endl
       << " # Grade to sign:      " << CLR_GRADE << std::setw(columnWidth-24) << std::left << this->getGradeToSign() << CLR_RST << " # " << std::endl
       << " # Grade to execute:   " << CLR_GRADE << std::setw(columnWidth-24) << std::left << this->getGradeToExecute() << CLR_RST << " # " << std::endl;
	if (this->getSigned())
       os << " # Signed:             " << CLR_GRN << std::setw(columnWidth-24) << std::left << "X" << CLR_RST << " # " << std::endl;
	else
		os << " # Signed:             " << CLR_RED << std::setw(columnWidth-24) << std::left << "O" << CLR_RST << " # " << std::endl;
	os << " # Target:             " << CLR_TARGET << std::setw(columnWidth-24) << std::left << _target << CLR_RST << " # " << std::endl << border << std::endl;
    return os;
}


void				AForm::beSigned(const Bureaucrat &bureaucrat)
	throw(AForm::GradeTooLowException)
{
	if (bureaucrat.getGrade() > _gradeToSign)
	{
		// Not sure if I should print an message here or just throw the exception
		std::cout <<
			"The grade of the bureaucrat " << CLR_CLERK <<
			bureaucrat.getName() << CLR_RST <<
			" is too low to sign this AForm " << CLR_FORM <<
			_name << CLR_RST << 
			"(" << CLR_GRADE <<
			bureaucrat.getGrade() << CLR_RST <<
			" < " << CLR_GRADE <<
			_gradeToSign << CLR_RST <<
			")!" << std::endl;
		throw AForm::GradeTooLowException();
	}
	if (_signed)
		std::cout <<
			"The AForm " << CLR_FORM <<
			_name << CLR_RST <<
			" cannot be signed by " <<  CLR_CLERK <<
			bureaucrat.getName() << CLR_RST <<
			" because the AForm is already signed!" <<
			CLR_RST << std::endl;
	else
	{
		_signed = true;
		std::cout <<
			"The AForm " << CLR_FORM <<
			_name << CLR_RST <<
			" was signed by " <<  CLR_CLERK <<
			bureaucrat.getName() << CLR_RST << "!" << std::endl;
	}
}

// Throwing and exception and returning a bool is a bit redundant
bool				AForm::isExecutable(const Bureaucrat &bureaucrat) const
	throw (AForm::GradeTooLowException, AForm::FormNotSignedException)
{
	// check if grade is high enough
	if (bureaucrat.getGrade() > this->_gradeToExecute)
		throw AForm::GradeTooLowException("Can't execute AForm because the grade of the bureaucrat is too low!");
	
	// check if signed
	if (!this->_signed)
		throw AForm::FormNotSignedException("Can't execute an unsigned AForm!");

	return true;
}

// 		EXCEPTIONS
// -----------------------------------------------------------------------------
// GradeTooLowException
AForm::GradeTooLowException::GradeTooLowException(const std::string &msg) throw()
{
	if (msg.empty())
		_msg = "The grade of the bureaucrat is too low!";
	else
		_msg = "The grade of the bureaucrat is too low: " + msg;
}

const char			*AForm::GradeTooLowException::what() const throw()
{
	return _msg.c_str();
}

AForm::GradeTooLowException::~GradeTooLowException() throw()
{
	// nothing to do here
}

// FormNotSignedException
AForm::FormNotSignedException::FormNotSignedException(const std::string &msg) throw()
{
	if (msg.empty())
		_msg = "The AForm is not signed!";
	else
		_msg = "The AForm is not signed: " + msg;
}

const char			*AForm::FormNotSignedException::what() const throw()
{
	return _msg.c_str();
}

AForm::FormNotSignedException::~FormNotSignedException() throw()
{
	// nothing to do here
}

// Insertion operator overload
std::ostream					&operator<<(std::ostream &os, const AForm &theForm)
{
	return theForm.print(os);
}
