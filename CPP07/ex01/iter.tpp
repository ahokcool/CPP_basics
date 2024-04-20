/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 15:13:59 by astein            #+#    #+#             */
/*   Updated: 2024/04/20 16:02:15 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_TPP
#define ITER_TPP

#include <iostream>

template <typename A>
void iter(A *adress, const size_t length, void(*func)(A&))
{
	for (size_t i = 0; i < length; i++)
		func(adress[i]);
}

// Test template function to add 42 to the element...
template <typename T>
void add42(T &i)
{
	i += 42;
}

// Test template function to print...
template <typename T>
void put(T &i)
{
	std::cout << i << std::endl;
}

// An full specialization of the put function for integers
template <>
void put(int &i)
{
	std::cout << "int: " << i << std::endl;
}

// An full specialization of the put function for strings
template <>
void put(std::string &i)
{
	std::cout << "string: " << i << std::endl;
}
#endif