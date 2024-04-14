/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 15:28:52 by astein            #+#    #+#             */
/*   Updated: 2024/04/14 23:31:19 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "AForm.hpp"
# include "Bureaucrat.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

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
	// TEST THE OCCF FUNCTIONS FOR ShrubberyCreationForm CLASS
	{	
		title("START: TEST THE OCCF FUNCTIONS FOR ShrubberyCreationForm CLASS", 1, 0);
		// Test the default constructor // cant since its private
		// ShrubberyCreationForm scf1;
		// std::cout << scf1;
		
		info("Create a ShrubberyCreationForm object with the parameterized constructor...", CLR_GRN);
		ShrubberyCreationForm scf2("dessert");
		std::cout << scf2;
		
		info("Self assignation not allowed", CLR_RED);
		// scf2 = scf2;
		
		info("Test the copy constructor", CLR_GRN);
		ShrubberyCreationForm scf3(scf2);
		info("scf2:", CLR_BLU);
		std::cout << scf2;
		info("scf3:", CLR_BLU);
		std::cout << scf3;

		info ("Test the assignment Operator Overload", CLR_GRN);
		ShrubberyCreationForm scf4("garden");
		info("scf2:", CLR_BLU);
		std::cout << scf2;
		info("scf4:", CLR_BLU);
		std::cout << scf4;
		scf4 = scf2;
		info("scf2:", CLR_BLU);
		std::cout << scf2;
		info("scf4:", CLR_BLU);
		std::cout << scf4;

		info("Create a ShrubberyCreationForm as a AForm pointer...", CLR_GRN);
		AForm *scf5 = new ShrubberyCreationForm("forest");
		std::cout << *scf5;
		delete scf5;
		title("END: TEST THE OCCF FUNCTIONS FOR ShrubberyCreationForm CLASS", 0, 1);
	}
	
	// TEST THE OCCF FUNCTIONS FOR RobotomyRequestForm CLASS
	{	
		title("START: TEST THE OCCF FUNCTIONS FOR RobotomyRequestForm CLASS", 1, 0);
		// Test the default constructor // cant since its private
		// RobotomyRequestForm rrf1;
		// std::cout << rrf1;
		
		info("Create a RobotomyRequestForm object with the parameterized constructor...", CLR_GRN);
		RobotomyRequestForm rrf2("dessert");
		std::cout << rrf2;
		
		info("Self assignation not allowed", CLR_RED);
		// rrf2 = rrf2;
		
		info("Test the copy constructor", CLR_GRN);
		RobotomyRequestForm rrf3(rrf2);
		info("rrf2:", CLR_BLU);
		std::cout << rrf2;
		info("rrf3:", CLR_BLU);
		std::cout << rrf3;

		info ("Test the assignment Operator Overload", CLR_GRN);
		RobotomyRequestForm rrf4("garden");
		info("rrf2:", CLR_BLU);
		std::cout << rrf2;
		info("rrf4:", CLR_BLU);
		std::cout << rrf4;
		rrf4 = rrf2;
		info("rrf2:", CLR_BLU);
		std::cout << rrf2;
		info("rrf4:", CLR_BLU);
		std::cout << rrf4;

		info("Create a RobotomyRequestForm as a AForm pointer...", CLR_GRN);
		AForm *rrf5 = new RobotomyRequestForm("forest");
		std::cout << *rrf5;
		delete rrf5;
		title("END: TEST THE OCCF FUNCTIONS FOR RobotomyRequestForm CLASS", 0, 1);
	}

	// TEST THE OCCF FUNCTIONS FOR PresidentialPardonForm CLASS
	{	
		title("START: TEST THE OCCF FUNCTIONS FOR PresidentialPardonForm CLASS", 1, 0);
		// Test the default constructor // cant since its private
		// PresidentialPardonForm ppf1;
		// std::cout << ppf1;
		
		info("Create a PresidentialPardonForm object with the parameterized constructor...", CLR_GRN);
		PresidentialPardonForm ppf2("dessert");
		std::cout << ppf2;
		
		info("Self assignation not allowed", CLR_RED);
		// ppf2 = ppf2;
		
		info("Test the copy constructor", CLR_GRN);
		PresidentialPardonForm ppf3(ppf2);
		info("ppf2:", CLR_BLU);
		std::cout << ppf2;
		info("ppf3:", CLR_BLU);
		std::cout << ppf3;

		info ("Test the assignment Operator Overload", CLR_GRN);
		PresidentialPardonForm ppf4("garden");
		info("ppf2:", CLR_BLU);
		std::cout << ppf2;
		info("ppf4:", CLR_BLU);
		std::cout << ppf4;
		ppf4 = ppf2;
		info("ppf2:", CLR_BLU);
		std::cout << ppf2;
		info("ppf4:", CLR_BLU);
		std::cout << ppf4;

		info("Create a PresidentialPardonForm as a AForm pointer...", CLR_GRN);
		AForm *ppf5 = new PresidentialPardonForm("forest");
		std::cout << *ppf5;
		delete ppf5;
		title("END: TEST THE OCCF FUNCTIONS FOR PresidentialPardonForm CLASS", 0, 1);
	}

	// START: MY BASIC TESTS for ShrubberyCreationForm
	{
		title("START: MY BASIC TESTS for ShrubberyCreationForm", 1, 0);
		info("Create a Bureaucrat with a grade of 145", CLR_GRN);
		Bureaucrat b145("145 boy", 145);

		info("Create a Bureaucrat with a grade of 137", CLR_GRN);
		Bureaucrat b137("137 girl", 137);

		info("Create a ShrubberyCreationForm", CLR_GRN);
		ShrubberyCreationForm scf6("somewhere");
		std::cout << scf6;
		
		info("Try to execute the AForm with both bureaucrats, shouldn't work since the form isn't signed yet...", CLR_GRN);
		b145.executeForm(scf6);
		b137.executeForm(scf6);
	
		info("Sign the ShrubberyCreationForm", CLR_GRN);
		b145.signForm(scf6);
		std::cout << scf6;

		info("Try to execute the ShrubberyCreationForm with too low grade bureaucrat, shouldn't work...", CLR_GRN);
		b145.executeForm(scf6);
		info("Try to execute the ShrubberyCreationForm with high enough grade bureaucrat, should work...", CLR_GRN);
		b137.executeForm(scf6);
		title("END: MY BASIC TESTS for ShrubberyCreationForm", 0, 1);
	}

	// START: MY BASIC TESTS for RobotomyRequestForm
	{
		title("START: MY BASIC TESTS for RobotomyRequestForm", 1, 0);
		info("Create a Bureaucrat with a grade of 72", CLR_GRN);
		Bureaucrat b72("72 boy", 72);

		info("Create a Bureaucrat with a grade of 45", CLR_GRN);
		Bureaucrat b45("45 girl", 45);

		info("Create a RobotomyRequestForm", CLR_GRN);
		RobotomyRequestForm rrf6("somewhere");
		std::cout << rrf6;
		
		info("Try to execute the AForm with both bureaucrats, shouldn't work since the form isn't signed yet...", CLR_GRN);
		b72.executeForm(rrf6);
		b45.executeForm(rrf6);
		info("Sign the RobotomyRequestForm", CLR_GRN);
		b72.signForm(rrf6);
		std::cout << rrf6;

		info("Try to execute the RobotomyRequestForm with too low grade bureaucrat, shouldn't work...", CLR_GRN);
		b72.executeForm(rrf6);

		info("Try to execute the RobotomyRequestForm with high enough grade bureaucrat, should work...", CLR_GRN);
		b45.executeForm(rrf6);

		title("END: MY BASIC TESTS for RobotomyRequestForm", 0, 1);
	}

	{
		title("START: MY CLERK EXECUTE TEST", 1, 0);
		
		Bureaucrat b1("The BOSS", 1);

		info("Test for the ShrubberyCreationForm...", CLR_GRN);
		ShrubberyCreationForm scf1("target Shrubbery");
		AForm &a1 = scf1;
		
		b1.executeForm(a1);
		b1.signForm(a1);
		b1.executeForm(a1);

		info("Test for the RobotomyRequestForm...", CLR_GRN);
		RobotomyRequestForm rrf1("target Robotomy");
		AForm &a2 = rrf1;
		b1.executeForm(a2);
		b1.signForm(a2);
		b1.executeForm(a2);

		info("Test for the PresidentialPardonForm...", CLR_GRN);
		PresidentialPardonForm ppf1("target Presidential");
		AForm &a3 = ppf1;
		b1.executeForm(a3);
		b1.signForm(a3);
		b1.executeForm(a3);

		title("END: MY CLERK EXECUTE TEST", 0, 1);
	}
	
	return 0;	
}
