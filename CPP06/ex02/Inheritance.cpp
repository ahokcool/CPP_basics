/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Inheritance.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:59:09 by astein            #+#    #+#             */
/*   Updated: 2024/04/18 14:36:12 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Inheritance.hpp"

// Constructors & Destructors of Base
Base::Base()
{
	// std::cout << "Base constructor called" << std::endl;
}

Base::~Base()
{
	// std::cout << "Base destructor called" << std::endl;
}

// Test Functions
Base	*generate(void)
{
	static bool iniSrand = false; 
	// To ensure we only initialize the random seed once
	
    if (!iniSrand)
	{
		// This C cast is ugly!
		// I should use a static cast, but since I'm only allowed to use
		// one type of cast per exercise, I'll stick with this C cast!
		srand((unsigned int)time(NULL));
        iniSrand = true;
    }

	int random = rand() % 3;

	switch (random)
	{
		case 0:
			// (C) for creating...
			std::cout << "(C) A | ";
			return new A();
		case 1:
			std::cout << "(C) B | ";
			return new B();
		default:
			std::cout << "(C) C | ";
			return new C();
	}
}

void	identify(Base *p)
{
	// This is the way to check the type of the object
	// For pointes we use if/else to protect the cast
	if (dynamic_cast<A*>(p))
		// (P) for pointer
		std::cout << "(P) A | ";
	else if (dynamic_cast<B*>(p))
		std::cout << "(P) B | ";
	else if (dynamic_cast<C*>(p))
		std::cout << "(P) C | ";
	else
		std::cout << "(P) Unknown" << std::endl;
}

void	identify(Base &r)
{
	// This is the way to check the type of the object
	// For references we use try/catch to protect the cast
	try
	{
		(void)dynamic_cast<A&>(r);
		// (R) for reference
		std::cout << "(R) A | ";
		return ;
	}
	// catch (std::bad_cast &bc) {}
	// This would be the better (more percise) way to catch the exception
	// but we are not allowed to use the header <typeinfo>
	catch (std::exception &e) {}
	try
	{
		(void)dynamic_cast<B&>(r);
		std::cout << "(R) B | ";
		return ;
	}
	catch (std::exception &e) {}
	try
	{
		(void)dynamic_cast<C&>(r);
		std::cout << "(R) C | ";
		return ;
	}
	catch (std::exception &e) {}
	std::cout << "(R) Unknown" << std::endl;
}