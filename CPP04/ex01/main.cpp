/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 18:05:15 by astein            #+#    #+#             */
/*   Updated: 2024/04/02 13:33:52 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	int arr_size = 2;

	std::cout << std::endl << CLR_PINK <<
		"MY TEST MAIN" << std::endl << "---" << 
		CLR_RESET << std::endl;
    Animal* arr[arr_size];

	std::cout << std::endl << CLR_PINK <<
		"CREATING ANIMALS" << std::endl << "---" <<
		CLR_RESET << std::endl;
	for(int i = 0; i < arr_size; i++)
	{
		if (i % 2 == 0)
			arr[i] = new Dog();
		else
			arr[i] = new Cat();
	}
	
	std::cout << std::endl << CLR_PINK <<
		"MAKE SOME NOISE!" << std::endl << "---" << 
		CLR_RESET << std::endl;
	for(int i = 0; i < arr_size; i++)
		arr[i]->makeSound();

	std::cout << std::endl << CLR_PINK <<
		"A cat with some ideas..." << std::endl << "---" << 
		CLR_RESET << std::endl;
	arr[1]->setIdea(0, "I'm a cat");
	arr[1]->setIdea(10, "I hate dogs!");
	arr[1]->setIdea(20, "Let's go annoy the dog");
	arr[1]->makeSound();

	std::cout << std::endl << CLR_PINK <<
		"The dog sleeps and the cat copies herself to him..." <<
		std::endl << "---" << CLR_RESET << std::endl;
	*arr[0] = *arr[1];
	
	std::cout << std::endl << CLR_PINK <<
		"The dog awakes and makes strage noises..." <<
		std::endl << "---" << CLR_RESET << std::endl;
	arr[0]->makeSound();

	std::cout << std::endl << CLR_PINK <<
		"So he comes up with his own ideas and resets his type..." <<
		std::endl << "---" << CLR_RESET << std::endl;
	arr[0]->setType("I'm a Dog!");
	arr[0]->setIdea(0, "I'm a f*cking dog!");
	arr[0]->setIdea(10, "I hate cats!");
	arr[0]->setIdea(20, "Let's go annoy the cat");
	arr[0]->makeSound();

	std::cout << std::endl << CLR_PINK <<
		"But the dog couldn't change the cats brain..." <<
		std::endl << "---" << CLR_RESET << std::endl;
	arr[1]->makeSound();

	std::cout << std::endl << CLR_PINK <<
		"DELETING ANIMALS" <<
		std::endl << "---" << CLR_RESET << std::endl;
	for(int i = 0; i < arr_size; i++)
		delete arr[i];
		
	std::cout << std::endl << CLR_PINK <<
		"END OF MAIN" << CLR_RESET << std::endl;
    return 0;
}
