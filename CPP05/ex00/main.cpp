/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 15:28:52 by astein            #+#    #+#             */
/*   Updated: 2024/04/05 18:17:06 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"

int main()
{
	{	
		std::cout << std::endl << CLR_YLW <<
			"START: TEST THE OCCF FUNCTIONS FOR BUREAUCRAT CLASS" << 
			std::endl << std::endl << CLR_RST;
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

		std::cout << std::endl << CLR_GRN <<
			"END: TEST THE OCCF FUNCTIONS FOR BUREAUCRAT CLASS" << 
			std::endl << std::endl << CLR_RST;
	}

	{
		std::cout << std::endl << CLR_YLW <<
			"START: MY TESTS" <<
			std::endl << std::endl << CLR_RST;
		
		std::cout << CLR_GRN <<
			"Creating valid Bureaucrats" <<
			CLR_RST << std::endl;
		Bureaucrat b1 = Bureaucrat("Bureaucrat1", 1);
		Bureaucrat b2 = Bureaucrat("Bureaucrat2", 150);
		std::cout << CLR_BLU
			"They present themselves as: " <<
			CLR_RST << std::endl;
		std::cout << b1;
		std::cout << b2;

		try
		{
			std::cout << CLR_YLW <<
				"Try creating invalid Bureaucrats (to low)" <<
				std::endl << CLR_RST;
			Bureaucrat b3 = Bureaucrat("Bureaucrat3", 151);
		}
		catch(const std::exception& e)
		{
			std::cerr << CLR_RED <<
			e.what() << 
			std::endl << CLR_RST;
		}
		
		try
		{
			std::cout << CLR_YLW <<
				"Try creating invalid Bureaucrats (to high)" <<
				std::endl << CLR_RST;
			Bureaucrat b4 = Bureaucrat("Bureaucrat4", 0);
		}
		catch(const std::exception& e)
		{
			std::cerr << CLR_RED <<
			e.what() << 
			std::endl << CLR_RST;
		}

		try
		{
			std::cout << CLR_YLW <<
				"Try degradation of Bureaucrat2 current state of b2:" <<
				std::endl << CLR_RST;
			std::cout << b2;
			b2--;
		}
		catch(const std::exception& e)
		{
			std::cerr << CLR_RED <<
				e.what() << 
				std::endl << CLR_RST;
		}
		
		// No need for try since I know it will work...
		std::cout << "Promoting Bureaucrat2" << std::endl;
		b2++;
		std::cout << b2;
		std::cout << "Promoting Bureaucrat2 - again" << std::endl;
		++b2;
		std::cout << b2;

		try
		{
			std::cout << CLR_YLW <<
				"Try to promote of Bureaucrat1 current state of b1:" <<
				std::endl << CLR_RST;
			std::cout << b1;
			b1++;
		}
		catch(const std::exception& e)
		{
			std::cerr << CLR_RED <<
				e.what() << 
				std::endl << CLR_RST;
		}
		
		std::cout << std::endl << CLR_GRN <<
			"END: MY TESTS" <<
			std::endl << std::endl << CLR_RST;
	}
	return 0;	
}
