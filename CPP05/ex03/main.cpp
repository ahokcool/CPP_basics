/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 15:28:52 by astein            #+#    #+#             */
/*   Updated: 2024/04/13 21:23:04 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "AForm.hpp"
# include "Bureaucrat.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "Intern.hpp"

void	title(std::string str, bool newline_before, bool newline_after)
{
	if (newline_before)
		std::cout << std::endl;
	std::cout << CLR_ORN <<
		">>> " << str << " <<<" <<
		CLR_RST << std::endl;
	if (newline_after)
		std::cout << std::endl;
}

void	info(std::string str, std::string clr)
{
	std::cout <<
		clr <<
		" >> " << str <<
		CLR_RST << std::endl;
}

int main()
{
	// TEST THE OCCF FUNCTIONS FOR Intern CLASS
	{	
		title("START: TEST THE OCCF FUNCTIONS FOR Intern CLASS", 1, 0);
		info("Test the default constructor...", CLR_GRN);
		Intern int1;
		
		info("Self assignation not allowed", CLR_RED);
		// int1 = int1;
		
		info("Test the copy constructor", CLR_GRN);
		Intern int2(int1);
		
		info ("Test the assignment Operator Overload", CLR_GRN);
		Intern int3;
		int3 = int2;

		info("Create a Intern as a pointer...", CLR_GRN);
		Intern *int4 = new Intern;
		delete int4;
		title("END: TEST THE OCCF FUNCTIONS FOR Intern CLASS", 0, 1);
	}
	
	{
		title("START: MY INTERN TEST", 1, 0);
		
		Intern intern;
		AForm *form;
		info("Create a ShrubberyCreationForm with the Intern...", CLR_GRN);
		form = intern.makeForm("ShrubberyCreationForm", "here");
		std::cout << *form;
		delete form;
		form = NULL;

		info("Create a RobotomyRequestForm with the Intern...", CLR_GRN);
		form = intern.makeForm("RobotomyRequestForm", "there");
		std::cout << *form;
		delete form;
		form = NULL;

		info("Create a PresidentialPardonForm with the Intern...", CLR_GRN);
		form = intern.makeForm("PresidentialPardonForm", "everywhere");
		std::cout << *form;
		delete form;
		form = NULL;

		info("Create a non-existing form with the Intern...", CLR_GRN);
		intern.makeForm("PayInternsMinimumWage!", "internet");
		// Note: This check should be done as well in the cases before,
		// but since I know they exist, I didn't bother to check it.
		if (form)
		{
			std::cout << *form;
			delete form;
		}

		title("END: MY INTERN TEST", 0, 1);
	}
	
	return 0;	
}
