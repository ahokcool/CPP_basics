/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 09:33:02 by astein            #+#    #+#             */
/*   Updated: 2024/04/16 11:36:27 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
	double d = 42.42424242;

	int i = (int)d;
	std::cout << i << std::endl;
	int j = static_cast<int>(d);
	std::cout << j << std::endl;
	int *k = (int *)&d;
	std::cout << *k << std::endl;
	int *l = static_cast<int*>(&d);
	std::cout << *l << std::endl;
	return 0;
}