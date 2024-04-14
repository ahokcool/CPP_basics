/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 13:17:02 by astein            #+#    #+#             */
/*   Updated: 2024/04/14 23:36:18 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "RobotomyRequestForm.hpp"

// Constructors and destructor
// Private default constructor, should not be used
RobotomyRequestForm::RobotomyRequestForm() :
	AForm("RobotomyRequestForm", 72, 45)
{
	std::cout << "RobotomyRequestForm default constructor" << std::endl;	
}

// Parameterized constructor
RobotomyRequestForm::RobotomyRequestForm(const std::string &target) :
	AForm("RobotomyRequestForm", 72, 45, target)
{
	std::cout << "RobotomyRequestForm parameterized constructor" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) :
	AForm(other)
{
	std::cout << "RobotomyRequestForm copy constructor" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor" << std::endl;
}

// Operator overloads
RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	std::cout << "RobotomyRequestForm assignment operator" << std::endl;
	AForm::operator=(other);
	return (*this);
}

// Base class pure virtual function override
void					RobotomyRequestForm::execute(const Bureaucrat &executor) const
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
		std::cout << CLR_CLERK <<
		executor.getName() << CLR_RST <<
		" is executing the AForm " << CLR_FORM <<
		this->getName() << CLR_RST <<
		"..." << std::endl;

		std::cout <<
			"ZZZZZZZRRRRRRTTTTT!" << std::endl <<
			"ZZZRRRR-RRRZZZZZRTTT!" << std::endl <<
			"ZRRRRRRRRRR-ZZZZZZRT!" << std::endl <<
			"ZZZZRR-ZZRRRRRRRRTTT!" << std::endl <<
			"RRRZZZZRRRRRRRT-ZZZZ!" << std::endl <<
			"ZZZZZRRRRRRRTTTTT-ZRR!" << std::endl <<
			"RRRRR-ZZZZZZZRRRRRTTT!" << std::endl <<
			"ZZZZZRRRTTTT-ZRRRRRRR!" << std::endl <<
			"ZRRRRRRRRRT-ZZZZZZRRR!" << std::endl <<
			"ZZZZZZZRRRRRRRRRRRTTT!" << std::endl;

		// NOTE:
		// 50% of the time its a success (see subject)
		// I decided to not throw an exception here, because the robotomy is
		// quite likely to fail, so I will just print a message instead...
		srand(time(NULL));
		if (rand() % 2)
			std::cout << CLR_GRN <<
				"   !!!YIHAAAAAAA!!!" << CLR_TARGET << std::endl <<
				_target << CLR_RST <<
				" has been robotomized successfully!" <<
				std::endl;
		else
			std::cout << CLR_RED <<
				"   !!!BOOOOOOOOM!!!" << CLR_TARGET << std::endl <<
				_target << CLR_RST <<
				" could not be robotomized! Try again!" <<
				std::endl;
	}
}
