/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 18:52:34 by astein            #+#    #+#             */
/*   Updated: 2024/04/20 20:36:36 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
	public:
		Array<T>();
		Array<T>(const unsigned int n);
		Array<T>(const Array<T> &other);
		~Array<T>();

		// Member functions
		Array<T>		&operator=(const Array<T> &other);
		T				&operator[](const size_t i)	throw(std::exception);
		unsigned int 	size() const;

	private:
		unsigned int 	_size;
		T 				*_arr;

};

// Inlcuding templates after the class deinition!
// NOTE:
// Thus, placing the include for the .tpp file at the bottom of the .hpp file
// ensures that all necessary declarations are processed before any definitions
// are compiled, adhering to the C++ compilation model and reducing the
// likelihood of encountering errors related to incomplete types or unresolved
// symbols. This practice is especially crucial in template-heavy C++
// programming to maintain clarity and correctness in multi-file projects.
#include "Array.tpp"

#endif	