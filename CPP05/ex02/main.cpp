/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 15:28:52 by astein            #+#    #+#             */
/*   Updated: 2024/04/09 18:30:31 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"
# include "ShrubberyCreationForm.hpp"

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
		title("END: TEST THE OCCF FUNCTIONS FOR ShrubberyCreationForm CLASS", 0, 1);
	}

	{
		title("START: MY BASIC TESTS", 1, 0);
		info("Create a Bureaucrat with a grade of 145", CLR_GRN);
		Bureaucrat b145("145 boy", 145);

		info("Create a Bureaucrat with a grade of 137", CLR_GRN);
		Bureaucrat b137("137 girl", 137);

		info("Create a ShrubberyCreationForm", CLR_GRN);
		ShrubberyCreationForm scf6("somewhere");
		std::cout << scf6;
		
		info("Try to execute the AForm with both bureaucrats, shouldn't work since the form isn't signed yet...", CLR_GRN);
		try
		{
			scf6.execute(b145);
		}
		catch(const std::exception& e)
		{
			info("Exception caught: ", CLR_RED);
			info(e.what(), CLR_RED);
		}
		try
		{
			scf6.execute(b137);
		}
		catch(const std::exception& e)
		{
			info("Exception caught: ", CLR_RED);
			info(e.what(), CLR_RED);
		}
		info("Sign the ShrubberyCreationForm", CLR_GRN);
		scf6.beSigned(b145);
		std::cout << scf6;

		info("Try to execute the ShrubberyCreationForm with too low grade bureaucrat, shouldn't work...", CLR_GRN);
		try
		{
			scf6.execute(b145);
		}
		catch(const std::exception& e)
		{
			info("Exception caught: ", CLR_RED);
			info(e.what(), CLR_RED);
		}
		info("Try to execute the ShrubberyCreationForm with high enough grade bureaucrat, should work...", CLR_GRN);
		scf6.execute(b137);

		title("END: MY BASIC TESTS", 0, 1);
	}
	{
		title("TEST THE SIGNING PROCESS", 1, 0);
		// info("Create two Bureaucrat with a grades: 42 & 1", CLR_GRN);
		// Bureaucrat b42("Bureaucrat 42 Lisboa", 42);
		// Bureaucrat b1("Bureaucrat Numero Uno", 1);
		// std::cout << b42;
		// std::cout << b1;
		// info("Create a AForm with a grade to sign of 1 and a grade to execute of 42", CLR_GRN);
		// AForm f6("urgent AForm - pls sign asap!", 1, 42);
		// std::cout << f6;
		// try
		// {
		// 	info("Try to sign the AForm with b42", CLR_GRN);
		// 	f6.beSigned(b42);
		// }
		// catch(const std::exception& e)
		// {
		// 	info("Exception caught: ", CLR_RED);
		// 	info(e.what(), CLR_RED);
		// }
		// std::cout << f6;
		// info("Sign the AForm with b1", CLR_GRN);
		// f6.beSigned(b1);
		// std::cout << f6;
		// info("Sign the AForm with b1 AGAIN", CLR_GRN);
		// f6.beSigned(b1);
		// std::cout << f6;
		
		title("END: TEST THE SIGNING PROCESS", 0, 1);
	}
	return 0;	
}
