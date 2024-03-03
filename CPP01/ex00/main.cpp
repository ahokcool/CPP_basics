/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 23:18:14 by astein            #+#    #+#             */
/*   Updated: 2024/03/03 00:07:43 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void) {

	// Allocation on the stack
	Zombie zombie01 = Zombie("Zombie 01");
	zombie01.announce();

	// Allocation on the heap
	Zombie *zombie02 = Zombie::newZombie("Zombie 02");
	zombie02->announce();
	
	// Random allocation on the stack (randomChump)
	Zombie::randomChump("Zombie 03");
	
	// We need to delete the heap allocated zombie
	delete zombie02;
	
	return 0;
}
