/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:06:59 by astein            #+#    #+#             */
/*   Updated: 2024/03/01 17:48:39 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void) : _first_name(""), _last_name(""), _nickname(""), _phone_number(""), _darkest_secret(""){}

void Contact::set_contact(void)
{	
	this->_first_name = get_input("First name", true, COLOR_GREEN, 4);
	this->_last_name = get_input("Last name", true, COLOR_GREEN, 4);
	this->_nickname = get_input("Nickname", true, COLOR_GREEN, 4);
	this->_phone_number = get_input("Phone number", true, COLOR_GREEN, 4);
	this->_darkest_secret = get_input("Darkest secret", true, COLOR_GREEN, 4);
}

std::string	Contact::get_first_name(void) const
{
	return (this->_first_name);
}