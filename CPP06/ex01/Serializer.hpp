/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:34:17 by astein            #+#    #+#             */
/*   Updated: 2024/04/18 13:51:43 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include "Data.hpp"
#include <stdint.h>
# include <iostream>

class Serializer
{
	public:
		// Static methods
		static uintptr_t		serialize(Data* ptr);
		static Data*			deserialize(uintptr_t raw);

	private:
		// Constructors & Destructors
		Serializer();
		Serializer(const Serializer &other);
		~Serializer();

		// Equal assignment operator overload
		Serializer 				&operator=(const Serializer &other);
};

#endif
