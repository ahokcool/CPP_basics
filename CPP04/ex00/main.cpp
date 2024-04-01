/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 18:05:15 by astein            #+#    #+#             */
/*   Updated: 2024/04/01 22:22:52 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	{	
		std::cout << std::endl << "TEST THE OCCF FUNCTIONS FOR ANIMAL CLASS" << std::endl << std::endl;
		// Test the default constructor
		Animal a1;
		a1.makeSound();
		
		// Create a Animal object with the parameterized constructor
		Animal a2("Elefant");
		a2.makeSound();
		
		// This is not allowed
		// a1 = a1;
		
		// Test the parameterized constructor
		Animal *a3 = new Animal("Animal 3");
		a3->makeSound();
		
		// Test the copy constructor
		Animal a4(a1);
		a4.makeSound();

		// Test the assignment Operator Overload
		Animal a5("Cat");
		a4.makeSound();
		a4 = a1;
		a4.makeSound();
	
		delete a3;
		std::cout << std::endl << "END OF OCCF FUNCTIONS TEST FOR ANIMAL CLASS" << std::endl << std::endl;
	}

	{	
		std::cout << std::endl << "TEST THE OCCF FUNCTIONS FOR CAT CLASS" << std::endl << std::endl;
		// Test the default constructor
		Cat c1;
		c1.makeSound();
		
		// Create a Cat object with the parameterized constructor DOENST EXIST
		Cat c2;
		c2.makeSound();
		
		// This is not allowed
		// c1 = c1;
		
		// Test the parameterized constructor DOENST EXIST
		Cat *c3 = new Cat();
		c3->makeSound();
		
		// Test the copy constructor
		Cat c4(c1);
		c4.makeSound();

		// Test the assignment Operator Overload
		Cat c5;
		c4.makeSound();
		c4 = c1;
		c4.makeSound();
	
		delete c3;
		std::cout << std::endl << "END OF OCCF FUNCTIONS TEST FOR CAT CLASS" << std::endl << std::endl;
	}

	{	
		std::cout << std::endl << "TEST THE OCCF FUNCTIONS FOR DOG CLASS" << std::endl << std::endl;
		// Test the default constructor
		Dog d1;
		d1.makeSound();
		
		// Create a Dog object with the parameterized constructor DOENST EXIST
		Dog d2;
		d2.makeSound();
		
		// This is not allowed
		// d1 = d1;
		
		// Test the parameterized constructor DOENST EXIST
		Dog *d3 = new Dog();
		d3->makeSound();
		
		// Test the copy constructor
		Dog d4(d1);
		d4.makeSound();

		// Test the assignment Operator Overload
		Dog a5;
		d4.makeSound();
		d4 = d1;
		d4.makeSound();
	
		delete d3;
		std::cout << std::endl << "END OF OCCF FUNCTIONS TEST FOR DOG CLASS" << std::endl << std::endl;
	}
	{
		std::cout << std::endl << "42 MAIN" << std::endl << "---" << std::endl;
    	const Animal* meta = new Animal();
    	const Animal* j = new Dog();
    	const Animal* i = new Cat();
    	std::cout << j->getType() << " " << std::endl;
    	std::cout << i->getType() << " " << std::endl;
    	i->makeSound();
    	j->makeSound();
    	meta->makeSound();
		delete meta;
		delete j;
		delete i;
	
		std::cout << std::endl << "MY MAIN" << std::endl << "---" << std::endl;
		Animal a;
		Dog d;
		Dog d2;
		Cat c;
	
		std::cout << std::endl << "ANIMALS CREATED NOW MAKE SOME NOISE" << std::endl;
		a.makeSound();
		d.makeSound();
		c.makeSound();
		
		std::cout << std::endl << "ASSIGNMENT OPERATOR" << std::endl << "---" << std::endl;
		d2.setType("Shitty Dog");
		d2.makeSound();
		d2 = d;
		d2.makeSound();
	
		std::cout << std::endl << "COPY CONSTRUCTOR" << std::endl << "---" << std::endl;
		Dog d3(d);
		d3.makeSound();
	
		std::cout << std::endl << "WRONG ANIMALS" << std::endl << "---" << std::endl;
    	const WrongAnimal *wc = new WrongCat();
    	std::cout << wc->getType() << " " << std::endl;
    	wc->makeSound();
		delete wc;
		std::cout << std::endl << "END OF MY MAIN" << std::endl << "---" << std::endl;
	}
		std::cout << std::endl << "END OF MAIN" << std::endl;
    return 0;
}
