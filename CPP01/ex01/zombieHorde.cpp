/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 00:39:11 by astein            #+#    #+#             */
/*   Updated: 2024/03/03 02:00:45 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie*	zombieHorde(const int N, const std::string& name)
{
	if (N < 0)
	{
		std::cout << "Invalid number of zombies" << std::endl;
		return NULL;
	}
	
	Zombie* horde = new Zombie[N];
	for (int i = 0; i < N; i++)
		horde[i].setName(name);
	return horde;
}
