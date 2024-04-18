/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:59:21 by astein            #+#    #+#             */
/*   Updated: 2024/04/18 14:35:44 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Inheritance.hpp"
#include "Data.hpp"

int main()
{
	std::cout << "Create 10 Random Instances" << std::endl;
	Base *instances[10];
	std::cout << "CREATING:\t";
	for (int i = 0; i < 10; i++)
	{
		instances[i] = generate();
	}
	std::cout << std::endl;
	
	// std::cout << "Identify the Instances via pointer" << std::endl;
	std::cout << "POINTER:\t";
	for (int i = 0; i < 10; i++)
	{
		identify(instances[i]);
	}
	std::cout << std::endl;


	// std::cout << "Identify the Instances via reference" << std::endl;
	std::cout << "REFERENCE:\t";
	for (int i = 0; i < 10; i++)
	{
		identify(*instances[i]);
	}
	std::cout << std::endl;

	
	// delete the instances
	for (int i = 0; i < 10; i++)
	{
		delete instances[i];
	}
	std::cout << std::endl;

	std::cout << "create an null pointer" << std::endl;
	Base *randomPointer = NULL;
	std::cout << "try to identify the null pointer" << std::endl;
	identify(randomPointer);
	identify(*randomPointer);
	
	std::cout << "create an D instance which is not meantioned in the identify function" << std::endl;
	Base *dInstance = new D();
	std::cout << "try to identify the D instance" << std::endl;
	identify(dInstance);
	identify(*dInstance);
	delete dInstance;
	
	return 0;
}