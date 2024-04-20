/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:39:28 by astein            #+#    #+#             */
/*   Updated: 2024/04/18 13:54:04 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

// Constructors & Destructors
Data::Data() : _name("Default"), _moreData(42)
{
	// Nothing to do here
}

Data::Data(const std::string &name, int moreData) : _name(name), _moreData(moreData)
{
	// Nothing to do here
}

Data::Data(const Data &other) : _name(other._name), _moreData(other._moreData)
{
	// Nothing to do here
}

Data::~Data()
{
	// Nothing to do here
}

// Equal assignment operator overload
Data 	&Data::operator=(const Data &other)
{
	if (this == &other)
		return *this;
	_name = other._name;
	_moreData = other._moreData;
	return *this;
}

// Member functions
void	Data::printData() const
{
	std::cout <<
		"Hello, my name is: " <<
		 _name <<
		 "\t and I have more data: " <<
		 _moreData << std::endl;
}

void	Data::setName(const std::string &name)
{
	_name = name;
}
