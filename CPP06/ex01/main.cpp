/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:34:05 by astein            #+#    #+#             */
/*   Updated: 2024/04/18 13:52:56 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	// Serializer isn't instantiable since it has a private constructor
	// Serializer	serializer;

	Data		data1;
	Data		data2("Alexander", 25051994);
	
	data1.printData();
	data2.printData();
	std::cout << std::endl;

	Data*		ptr1 = &data1;
	Data*		ptr2 = &data2;

	ptr1->printData();
	ptr2->printData();
	std::cout << std::endl;
	
	uintptr_t	raw1 = Serializer::serialize(ptr1);
	uintptr_t	raw2 = Serializer::serialize(ptr2);
	
	// Change Data of ptr1
	ptr1->setName("astein");

	ptr1 = Serializer::deserialize(raw1);
	ptr2 = Serializer::deserialize(raw2);

	ptr1->printData();
	ptr2->printData();
	std::cout << std::endl;

	return 0;
}