/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 01:24:22 by astein            #+#    #+#             */
/*   Updated: 2024/03/03 03:27:51 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"
#include <iostream>

int main()
{
	{
		Weapon club = Weapon("crude spiked club");
		
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
    {
        Weapon club = Weapon("crude spiked club");
		
        HumanB jim("Jim");
        jim.setWeapon(club);
        jim.attack();
        club.setType("some other type of club");
        jim.attack();
    }
	{
		// My tests: no weapon
		std::cout << std::endl << "My test: no weapon" << std::endl;
		Weapon sponge = Weapon("sponge");
		
		HumanA alex("Alex", sponge);
		alex.attack();
		
		// My tests: no weapon
		std::cout << std::endl << "My test: no weapon" << std::endl;
		
		HumanB blex("Blex");
		blex.attack();
		blex.setWeapon(sponge);
		blex.attack();
		sponge.setType("water gun");
		blex.attack();
	}
	{
		// My tests: alex = ander
		std::cout << std::endl << "My test: alex = ander" << std::endl;
		Weapon alex_sponge = Weapon("alex sponge");
		Weapon ander_sponge = Weapon("ander sponge");
		
		HumanA alex("Alex", alex_sponge);
		alex.attack();

		HumanA ander("Ander", ander_sponge);
		ander.attack();

		// alex = ander;
		// alex.attack();
		// ander.attack();

		// alex = alex;
		// alex.attack();
		// ander.attack();
		
		// My tests: blex = bnder
		std::cout << std::endl << "My test: blex = bnder" << std::endl;
		Weapon blex_sponge = Weapon("alex sponge");
		Weapon bnder_sponge = Weapon("ander sponge");
		
		HumanB blex("Blex");
		blex.setWeapon(blex_sponge);
		blex.attack();

		HumanB bnder("Bnder");
		bnder.setWeapon(bnder_sponge);
		bnder.attack();

		blex = bnder;
		blex.attack();
		bnder.attack();

		blex = blex;
		blex.attack();
		bnder.attack();
	}

	
	
    return 0;
}
