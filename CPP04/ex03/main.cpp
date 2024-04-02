/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:17:08 by astein            #+#    #+#             */
/*   Updated: 2024/04/02 15:12:09 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	(void)src;

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	
	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);
	
	delete bob;
	delete me;
	delete src;
	
	// Try equipe use without materia
	test uneqp and use with
		wrong index
		on empty slot


	copy a character with Materia
	therefore its materia will be CLONed
	then check for memory leaks of the mareria
	
	create a character withour a name

	test the copy if its deeps with both copy construtors

	learn a MateriaSource when its full and passing a null pointer

	try to create a amteria from source which wasnt learnd before
	

	return 0;
}
