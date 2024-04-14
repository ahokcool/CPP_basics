/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 15:28:52 by astein            #+#    #+#             */
/*   Updated: 2024/04/14 23:17:40 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"
# include "Form.hpp"

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
		title("START: TEST THE OCCF FUNCTIONS FOR FORM CLASS", 1, 0);
		// Test the default constructor // cant since its private
		// Form f1;
		// std::cout << f1;
		
		info("Create a Form object with the parameterized constructor...", CLR_GRN);
		Form f2("Form 2", 1, 2);
		std::cout << f2;
		
		info("Self assignation not allowed", CLR_RED);
		// f2 = f2;
		
		info("Test the copy constructor", CLR_GRN);
		Form f3(f2);
		info("f2:", CLR_BLU);
		std::cout << f2;
		info("f3:", CLR_BLU);
		std::cout << f3;

		info ("Test the assignment Operator Overload", CLR_GRN);
		Form f4("Form 4", 149, 150);
		info("f2:", CLR_BLU);
		std::cout << f2;
		info("f4:", CLR_BLU);
		std::cout << f4;
		f4 = f2;
		info("f2:", CLR_BLU);
		std::cout << f2;
		info("f4:", CLR_BLU);
		std::cout << f4;
		title("END: TEST THE OCCF FUNCTIONS FOR FORM CLASS", 0, 1);
	}

	{
		title("START: MY BASIC TESTS", 1, 0);

		Form f1("Form 1", 1, 2);
		info("f1:", CLR_BLU);
		std::cout << f1;
		info("Test Getters:", CLR_GRN);
		std::cout << "Name: " << f1.getName() << std::endl;
		std::cout << "Grade to sign: " << f1.getGradeToSign() << std::endl;
		std::cout << "Grade to execute: " << f1.getGradeToExecute() << std::endl;
		std::cout << "Signed: " << f1.getSigned() << std::endl;
		info("Insertion operator overload:", CLR_GRN);
		std::cout << f1;

		try
		{
			info("Create a Form with a grade to sign too high...", CLR_YLW);
			Form f2("Form 2", 0, 2);
		}
		catch(const std::exception& e)
		{
			info("Exception caught: ", CLR_RED);
			info(e.what(), CLR_RED);
		}
		
		try
		{
			info("Create a Form with a grade to sign too low...", CLR_YLW);
			Form f3("Form 3", 151, 2);
		}
		catch(const std::exception& e)
		{
			info("Exception caught: ", CLR_RED);
			info(e.what(), CLR_RED);
		}
		
		try
		{
			info("Create a Form with a grade to execute too high...", CLR_YLW);
			Form f4("Form 4", 1, 0);
		}
		catch(const std::exception& e)
		{
			info("Exception caught: ", CLR_RED);
			info(e.what(), CLR_RED);
		}
		
		try
		{
			info("Create a Form with a grade to execute too low...", CLR_YLW);
			Form f5("Form 5", 1, 151);
		}
		catch(const std::exception& e)
		{
			info("Exception caught: ", CLR_RED);
			info(e.what(), CLR_RED);
		}
		title("END: MY BASIC TESTS", 0, 1);
	}
	{
		title("TEST THE SIGNING PROCESS", 1, 0);
		info("Create two Bureaucrat with a grades: 42 & 1", CLR_GRN);
		Bureaucrat b42("Bureaucrat 42 Lisboa", 42);
		Bureaucrat b1("Bureaucrat Numero Uno", 1);
		std::cout << b42;
		std::cout << b1;
		info ("USE CASE: form.beSigned function...", CLR_ORN);
		info("Create a Form with a grade to sign of 1 and a grade to execute of 42", CLR_GRN);
		Form f6("urgent form - pls sign asap!", 1, 42);
		std::cout << f6;
		try
		{
			info("Try to sign the form with b42", CLR_GRN);
			f6.beSigned(b42);
		}
		catch(const std::exception& e)
		{
			info("Exception caught: ", CLR_RED);
			info(e.what(), CLR_RED);
		}
		std::cout << f6;
		info("Sign the form with b1", CLR_GRN);
		f6.beSigned(b1);
		std::cout << f6;
		info("Sign the form with b1 AGAIN", CLR_GRN);
		f6.beSigned(b1);
		std::cout << f6;
		
		info("USE CASE: Bureaucrat.signForm function...", CLR_ORN);
		info("Create a Form with a grade to sign of 1 and a grade to execute of 42", CLR_GRN);
		Form f7("urgent form - pls sign asap!", 1, 42);
		std::cout << f7;
		info("Try to sign the form with b42", CLR_GRN);
		b42.signForm(f7);
		std::cout << f7;
		info("Sign the form with b1", CLR_GRN);
		b1.signForm(f7);
		std::cout << f7;
		title("END: TEST THE SIGNING PROCESS", 0, 1);
	}
	return 0;	
}
