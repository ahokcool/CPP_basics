/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 00:41:42 by astein            #+#    #+#             */
/*   Updated: 2024/03/03 00:55:09 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde( int N, std::string name );

int main(void) {

	// Create a horde of 5 zombies all named "Zombie xy"
	std::cout << std::endl << "Creating a horde of 5 zombies all named Zombie xy" << std::endl;
	Zombie* horde = zombieHorde(5, "Zombie xy");

	// Announce each zombie
	std::cout << std::endl << "Announcing the horde" << std::endl;
	for (int i = 0; i < 5; i++) {
		horde[i].announce();
	}		

	// Delete the horde
	std::cout << std::endl << "Deleting the horde" << std::endl;
	delete [] horde;

	// Try to create a horde of -1 zombies (returns NULL)
	std::cout << std::endl << "Creating a horde of -1 zombies" << std::endl;
	horde = zombieHorde(-1, "Zombie abc");
	
	// Delete is safe to use with NULL
	std::cout << std::endl << "Deleting the horde" << std::endl << std::endl;
	delete [] horde;

	// The end
	return 0;
}
