/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 18:05:15 by astein            #+#    #+#             */
/*   Updated: 2024/03/27 16:07:27 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	int arr_size = 4;

	std::cout << std::endl << "MY TEST MAIN" << std::endl << "---" << std::endl;
    Animal* arr[arr_size];

	std::cout << std::endl << "CREATING ANIMALS" << std::endl << "---" << std::endl;
	for(int i = 0; i < arr_size; i++)
	{
		if (i % 2 == 0)
			arr[i] = new Dog();
		else
			arr[i] = new Cat();
	}
	
	std::cout << std::endl << "MAKE SOME NOISE!" << std::endl << "---" << std::endl;
	for(int i = 0; i < arr_size; i++)
		arr[i]->makeSound();

	std::cout << std::endl << "A cat with some ideas..." << std::endl << "---" << std::endl;
	arr[1]->setIdea(0, "I'm a cat");
	arr[1]->setIdea(10, "I hate dogs!");
	arr[1]->setIdea(20, "Let's go annoy the dog");
	arr[1]->makeSound();

	std::cout << std::endl << "The dog sleeps and the cat copies her brain to him..." << std::endl << "---" << std::endl;
	arr[0] = arr[1];
	arr[0]->makeSound();

	std::cout << std::endl << "The dog awakes and restores its brain and type..." << std::endl << "---" << std::endl;
	arr[0]->setType("I'm a Dog!");
	for(int i = 0; i < 100; i++)
	{
		if (i % 2 == 0)
			arr[0]->setIdea(i, "Where is the ball???");
		else
			arr[0]->setIdea(i, "F*ck cats!");
	}
	arr[0]->makeSound();

	std::cout << std::endl << "But the dog couldn't change the cats brain..." << std::endl << "---" << std::endl;
	arr[1]->makeSound();

	std::cout << std::endl << "DELETING ANIMALS" << std::endl << "---" << std::endl;
	for(int i = 0; i < arr_size; i++)
		delete arr[i];
		
	std::cout << std::endl << "END OF MAIN" << std::endl;
    return 0;
}
