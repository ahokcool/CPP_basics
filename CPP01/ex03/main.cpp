/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 01:24:22 by astein            #+#    #+#             */
/*   Updated: 2024/03/29 21:54:48 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

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
		// My tests
		std::cout << std::endl << "My test" << std::endl;
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
    return 0;
}
