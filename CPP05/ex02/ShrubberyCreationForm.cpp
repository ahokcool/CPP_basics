/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 13:17:02 by astein            #+#    #+#             */
/*   Updated: 2024/04/14 23:36:08 by astein           ###   ########.fr       */
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

// Base class pure virtual function override
void					ShrubberyCreationForm::execute(const Bureaucrat &executor) const
	throw (	AForm::GradeTooLowException,
			AForm::FormNotSignedException,
			std::runtime_error)
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
		std::string filename = this->_target + "_shrubbery";

		std::ofstream file(filename.c_str());
		if (!file.is_open())
			throw std::runtime_error("Could not open file");

		// NOTE: 	THE LAYOUT LOOKS WRONG BECAUSE OF THE TABS AND THE "\"
		// 			BUT IT IS CORRECT
		file << "                        /\\"                              		<< std::endl;
		file << "                       /\\*\\"                             	<< std::endl;
		file << "                      /\\O\\*\\"                           	<< std::endl;
		file << "                     /*/\\/\\/\\"                          	<< std::endl;
		file << "                    /\\O\\/\\*\\/\\"                       	<< std::endl;
		file << "                   /\\*\\/\\*\\/\\/\\"                      	<< std::endl;
		file << "                  /\\O\\/\\/*/\\/O/\\"                     	<< std::endl;
		file << "                 /*/\\/\\/\\/*/\\/\\/\\"                    	<< std::endl;
		file << "                /\\O\\/\\/*/\\/O/\\/\\*\\"                		<< std::endl;
		file << "               /\\*\\/\\*\\/\\/\\/*/\\/*/\\"              		<< std::endl;
		file << "              /\\O\\/\\/*/\\/O/\\/\\*\\/\\/\\"           		<< std::endl;
		file << "             /*/\\/\\/\\/*/\\/\\/\\/*/\\/\\/\\"        		<< std::endl;
		file << "            /\\O\\/\\/*/\\/O/\\/\\*\\/\\O/\\/\\\\"     		<< std::endl;
		file << "   /\\                   ||"                           	    << std::endl;
		file << "  /\\*\\                  ||"                          	    << std::endl;
		file << " /\\* /\\                 ||"                          	    << std::endl;
		file << "/\\O/ \\*\\                ||"                         	    << std::endl;
		file << "   ||                   ||"                                	<< std::endl;
		file << "   ||                   ||"                                	<< std::endl;
		file << "   ||"          												<< std::endl;
		file << "   ||"          												<< std::endl;
		file << "               &&& &&  & &&"									<< std::endl;
     	file << "         && &\\/&\\|& ()|/ @, &&"								<< std::endl;
     	file << "         &\\/(/&/&||/& /_/)_&/_&                /\\"			<< std::endl;
		file << "        &() &\\/&|()|/&\\/ '%\" & ()             /\\*\\"		<< std::endl;
		file << "       &_\\_&&_\\ |& |&&/&__%_/_& &&           /\\||/\\"		<< std::endl;
		file << "      &&   && & &| &| /& & % ()& /&&        /\\O/\\\\/\\"		<< std::endl;
		file << "       ()&_---()&\\&\\|&&-&&--%---()~            ||"			<< std::endl;
		file << "           &&     \\|||                         ||"			<< std::endl;
		file << "                   |||                         ||"				<< std::endl;
		file << "                   |||                         ||"				<< std::endl;
		file << "                   |||"										<< std::endl;			
		file << "             , -=-~  .-^- _"									<< std::endl;
		file << std::endl;
		file.close();

		// print success message
		std::cout <<
			"The AForm " << CLR_FORM <<
			this->getName() << CLR_RST <<
			" was successfully executed by " << CLR_CLERK <<
			executor.getName() << CLR_RST <<
			" which created the file: " << CLR_TARGET <<
			filename << CLR_RST << "!" << std::endl;
	}
}
