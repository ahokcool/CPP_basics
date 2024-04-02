/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 15:15:34 by astein            #+#    #+#             */
/*   Updated: 2024/04/02 18:15:40 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

void test1()
{
	std::cout << CLR_CYAN <<
		"TEST 1: OCCF Character" << std::endl <<
		"-----------------------------------------" <<
		CLR_RESET << std::endl;
	
	Character c1;
	Character *c2 = new Character("Alex");
	Character c3(c1);
	Character c4("not Alex");
	c4 = *c2;
	c4 = c4;

	std::cout << "RESULT:" << std::endl;
	std::cout << "c1: " << c1.getName() << std::endl;
	std::cout << "c2: " << c2->getName() << std::endl;
	std::cout << "c3: " << c3.getName() << std::endl;
	std::cout << "c4: " << c4.getName() << std::endl;
	
	delete c2;
}

void test2()
{
		std::cout << CLR_CYAN <<
		"TEST 2: OCCF Cure and Ice" << std::endl <<
		"-----------------------------------------" <<
		CLR_RESET << std::endl;
	
	{
		std::cout << "CURE:" << std::endl;
		Cure c1;
		Cure *c2 = new Cure();
		Cure c3(c1);
		Cure c4;
	
		c4 = *c2;
		c4 = c4;
	
		std::cout << "RESULT:" << std::endl;
		std::cout << "c1: " << c1.getType() << std::endl;
		std::cout << "c2: " << c2->getType() << std::endl;
		std::cout << "c3: " << c3.getType() << std::endl;	
		std::cout << "c3: " << c4.getType() << std::endl;	
		delete c2;
	}
	{
		std::cout << "ICE:" << std::endl;
		Ice i1;
		Ice *i2 = new Ice();
		Ice i3(i1);
		Ice i4;
	
		i4 = *i2;
		i4 = i4;
	
		std::cout << "RESULT:" << std::endl;
		std::cout << "i1: " << i1.getType() << std::endl;
		std::cout << "i2: " << i2->getType() << std::endl;
		std::cout << "i3: " << i3.getType() << std::endl;	
		std::cout << "c3: " << i4.getType() << std::endl;
		delete i2;
	}
	{
		std::cout << "MIX THEM:" << std::endl;
		AMateria *m1 = new Cure();
		AMateria *m2 = new Ice();
		AMateria *m3 = new Cure();
		AMateria *m4 = new Ice();
		std::cout << "m1: " << m1->getType() << std::endl;
		std::cout << "m2: " << m2->getType() << std::endl;
		std::cout << "m3: " << m3->getType() << std::endl;
		std::cout << "m4: " << m4->getType() << std::endl;
		*m3 = *m2;
		*m4 = *m1;
		std::cout << "RESULT:" << std::endl;
		std::cout << "m1: " << m1->getType() << std::endl;
		std::cout << "m2: " << m2->getType() << std::endl;
		std::cout << "m3: " << m3->getType() << std::endl;
		std::cout << "m4: " << m4->getType() << std::endl;
		delete m1;
		delete m2;
		delete m3;
		delete m4;	
	}
}

void test3()
{
	std::cout << CLR_CYAN <<
		"TEST 3: OCCF MateriaSource" << std::endl <<
		"-----------------------------------------" <<
		CLR_RESET << std::endl;
	
	MateriaSource ms1;
	MateriaSource *ms2 = new MateriaSource();
	MateriaSource ms3(ms1);
	MateriaSource ms4;
	
	ms4 = *ms2;
	ms4 = ms4;
	
	delete ms2;
}

void test4(void)
{
	std::cout << CLR_CYAN <<
		"TEST 4: Use Case aka wtf!" << std::endl <<
		"-----------------------------------------" <<
		CLR_RESET << std::endl;	

	std::cout << std::endl << CLR_CYAN <<
	 	"Creating two characters" <<
		std::endl << "---" << std::endl << CLR_RESET;
	
	Character alex = Character("Alex");
	Character bob = Character("Bob");

	std::cout << std::endl << CLR_CYAN <<
	 	"Creating AMateria instances of ice and cure as an AMateria Pointer" <<
		std::endl << "---" << std::endl << CLR_RESET;
	AMateria *ice = new Ice();
	AMateria *cure = new Cure();

	std::cout << std::endl << CLR_CYAN <<
	 	"Creating a MateriaSource and learning ice twice" <<
		std::endl << "---" << std::endl << CLR_RESET;
	
	MateriaSource ms = MateriaSource();
	ms.learnMateria(ice);
	ms.learnMateria(ice);

	std::cout << std::endl << CLR_CYAN <<
	 	"Learning NULL" <<
		std::endl << "---" << std::endl << CLR_RESET;
	ms.learnMateria(NULL);
	
	std::cout << std::endl << CLR_CYAN <<
	 	"Leaning 3 times more ice to overflow storage" <<
		std::endl << "---" << std::endl << CLR_RESET;
	ms.learnMateria(ice);
	ms.learnMateria(ice);
	ms.learnMateria(ice);

	std::cout << std::endl << CLR_CYAN <<
	 	"Creating two ice materias using via MateriaSource" <<
		std::endl << "---" << std::endl << CLR_RESET;
	
	AMateria *ice1 = ms.createMateria("ice");
	AMateria *ice2 = ms.createMateria("ice");

	std::cout << std::endl << CLR_CYAN <<
	 	"Trying to create 'cure' and 'foo'" <<
		std::endl << "---" << std::endl << CLR_RESET;
	AMateria *cure1 = ms.createMateria("cure");
	AMateria *foo = ms.createMateria("foo");
	// Void them for the flags
	(void)cure1;
	(void)foo;

	std::cout << std::endl << CLR_CYAN <<
	 	"Equiping Alex with ice and cure and NULL" <<
		std::endl << "---" << std::endl << CLR_RESET;

	alex.equip(ms.createMateria("ice"));
	alex.equip(new Cure());
	alex.equip(NULL);

	std::cout << std::endl << CLR_CYAN <<
	 	"Alex uses ice(0), cure(1), NULL(2) and wrong index(10) on Bob" <<
		std::endl << "---" << std::endl << CLR_RESET;
	
	alex.use(0, bob);
	alex.use(1, bob);
	alex.use(2, bob);
	alex.use(10, bob);

	std::cout << std::endl << CLR_CYAN <<
	 	"Over equiping Bob with cure and ice" <<
		std::endl << "---" << std::endl << CLR_RESET;
	bob.equip(new Cure());
	bob.equip(new Cure());
	bob.equip(new Cure());
	AMateria *ice3 = ms.createMateria("ice");
	AMateria *ice4 = ms.createMateria("ice");
	bob.equip(ice3);
	bob.equip(ice4);
	bob.equip(ice4);
	
	std::cout << std::endl << CLR_CYAN <<
	 	"Who is bob2 and bob3 and why are they so similar to Bob?" <<
		std::endl << "---" << std::endl << CLR_RESET;
	Character bob2(bob);
	Character *bob3 = new Character();
	*bob3 = bob;
	
	std::cout << std::endl << CLR_CYAN <<
	 	"Stupid Bob has only Cure so wants to unequip 0 to 2..." << std::endl <<
		"and since he is a stupid boy he unequippes everything twice" << std::endl <<
		"and even index 11 for some stupid reasons..." <<
		std::endl << "---" << std::endl << CLR_RESET;

	// Preventing materia leaks...
	AMateria *bob_slot_2 = bob.getMateria(2);
	AMateria *bob_slot_1 = bob.getMateria(1);
	AMateria *bob_slot_0 = bob.getMateria(0);
	AMateria *bob_slot_11 = bob.getMateria(11);

	bob.unequip(2);
	bob.unequip(2);
	bob.unequip(1);
	bob.unequip(1);
	bob.unequip(0);
	bob.unequip(0);
	bob.unequip(11);
	bob.unequip(11);
	
	std::cout << std::endl << CLR_CYAN <<
	 	"Bob 2 and 3 can still use slot 1 on bob!" <<
		std::endl << "---" << std::endl << CLR_RESET;

	bob2.use(1, bob);
	bob3->use(1, bob);	

	std::cout << std::endl << CLR_CYAN <<
	 	"Thats enough - let's deleting everything..." <<
		std::endl << "---" << std::endl << CLR_RESET;
	
	if (cure)
		delete cure;
	if (ice)
		delete ice;
	if (ice1)
		delete ice1;
	if (ice2)
		delete ice2;
	// Bob will delete it:
	// if (ice3)
	// 	delete ice3;
	if (ice4)
		delete ice4;
	if (cure1)
		delete cure1;
	if (foo)
		delete foo;
	if (bob_slot_0)
		delete bob_slot_0;
	if (bob_slot_1)
		delete bob_slot_1;
	if (bob_slot_2)
		delete bob_slot_2;
	if (bob_slot_11)
		delete bob_slot_11;		
	if (bob3)
		delete bob3;
}