/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 00:57:46 by astein            #+#    #+#             */
/*   Updated: 2024/03/03 02:01:21 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main()
{
	// Setup the string, the pointer and the reference
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	// Print the memory address of the string variable
	std::cout << "Memory address of the string variable: " << &str << std::endl;

	// Print the memory address held by stringPTR
	std::cout << "Memory address held by stringPTR: " << stringPTR << std::endl;

	// Print the memory address held by stringREF
	std::cout << "Memory address held by stringREF: " << &stringREF << std::endl;

	// Print the value of the string variable
	std::cout << "Value of the string variable: " << str << std::endl;
	std::cout << "Value pointed to by stringPTR: " << *stringPTR << std::endl;
	std::cout << "Value pointed to by stringREF: " << stringREF << std::endl;

	// The end
	return 0;
}
