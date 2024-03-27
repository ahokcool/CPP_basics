/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 18:05:15 by astein            #+#    #+#             */
/*   Updated: 2024/03/27 00:26:19 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
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
    const WrongAnimal* wc = new WrongCat();
    std::cout << wc->getType() << " " << std::endl;
    wc->makeSound();
	delete wc;	

	std::cout << std::endl << "END OF MAIN" << std::endl;
    return 0;
}
