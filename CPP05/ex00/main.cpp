/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 15:28:52 by astein            #+#    #+#             */
/*   Updated: 2024/04/06 00:07:14 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"

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
		title("START: TEST THE OCCF FUNCTIONS FOR BUREAUCRAT CLASS", 1, 0);
		// Test the default constructor
		// Bureaucrat b1;
		// std::cout << b1;
		
		// Create a Bureaucrat object with the parameterized constructor
		Bureaucrat b2("Bureaucrat 2", 150);
		std::cout << b2;
		
		// This is not allowed
		// b2 = b2;
		
		// Test the copy constructor
		Bureaucrat b3(b2);
		std::cout << b3;

		// Test the assignment Operator Overload
		Bureaucrat b4("Bureaucrat 4", 1);
		std::cout << b4;
		b4 = b2;
		std::cout << b4;
		title("END: TEST THE OCCF FUNCTIONS FOR BUREAUCRAT CLASS", 0, 1);
	}

	{
		title("START: MY TESTS", 1, 0);
		info("Creating valid Bureaucrats", CLR_GRN);
		Bureaucrat b1 = Bureaucrat("Bureaucrat1", 1);
		Bureaucrat b2 = Bureaucrat("Bureaucrat2", 150);
		info("They present themselves as: ", CLR_BLU);
		std::cout << b1;
		std::cout << b2;

		try
		{
			info("Try creating invalid Bureaucrats (to low)", CLR_YLW);
			Bureaucrat b3 = Bureaucrat("Bureaucrat3", 151);
		}
		catch(const std::exception& e)
		{
			info("Exception caught: ", CLR_RED);
			info(e.what(), CLR_RED);
		}
		
		try
		{
			info("Try creating invalid Bureaucrats (to high)", CLR_YLW);
			Bureaucrat b4 = Bureaucrat("Bureaucrat4", 0);
		}
		catch(const std::exception& e)
		{
			info("Exception caught: ", CLR_RED);
			info(e.what(), CLR_RED);
		}

		try
		{
			info("Try degradation of Bureaucrat1 current state of b1:", CLR_YLW);
			std::cout << b2;
			b2--;
		}
		catch(const std::exception& e)
		{
			info("Exception caught: ", CLR_RED);
			info(e.what(), CLR_RED);
		}
		
		// No need for try since I know it will work...
		info("Promoting Bureaucrat 2", CLR_YLW);
		b2++;
		std::cout << b2;
		info("Promoting Bureaucrat 2 - again", CLR_YLW);
		++b2;
		std::cout << b2;

		try
		{
			info("Try to promote of Bureaucrat1 current state of b1:", CLR_YLW);
			std::cout << b1;
			b1++;
		}
		catch(const std::exception& e)
		{
			info("Exception caught: ", CLR_RED);
			info(e.what(), CLR_RED);
		}
		
		info("Testing the getters:", CLR_YLW);
		std::cout << b1.getName() << std::endl;
		std::cout << b1.getGrade() << std::endl;
		std::cout << b1 << std::endl;
		

		title("END: MY TESTS", 0, 1);
	}
	return 0;	
}
