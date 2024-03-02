/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:06:59 by astein            #+#    #+#             */
/*   Updated: 2024/03/02 15:15:25 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void) : _first_name(""), _last_name(""), _nickname(""), _phone_number(""), _darkest_secret(""){}

void Contact::set_contact(void)
{	
	this->_first_name = get_input("First name", true, COLOR_GREEN, 4, 20);
	this->_last_name = get_input("Last name", true, COLOR_GREEN, 4, 20);
	this->_nickname = get_input("Nickname", true, COLOR_GREEN, 4, 20);
	this->_phone_number = get_input("Phone number", true, COLOR_GREEN, 4, 20);
	this->_darkest_secret = get_input("Darkest secret", true, COLOR_GREEN, 4, 20);
}

void		Contact::display_contact(int indentation) const
{
	format_output("First name: ", COLOR_CYAN, indentation, false, 20);
	std::cout << COLOR_CYAN << get_first_name() << COLOR_RESET << std::endl;
	format_output("Last name: ", COLOR_CYAN, indentation, false, 20);
	std::cout << COLOR_CYAN << get_last_name() << COLOR_RESET << std::endl;
	format_output("Nickname: ", COLOR_CYAN, indentation, false, 20);
	std::cout << COLOR_CYAN << get_nickname() << COLOR_RESET << std::endl;
	format_output("Phone number: ", COLOR_CYAN, indentation, false, 20);
	std::cout << COLOR_CYAN << get_phone_number() << COLOR_RESET << std::endl;
	format_output("Darkest secret: ", COLOR_CYAN, indentation, false, 20);
	std::cout << COLOR_CYAN << get_darkest_secret() << COLOR_RESET << std::endl;
}

std::string	Contact::get_first_name(void) const
{
	return (this->_first_name);
}

std::string	Contact::get_last_name(void) const
{
	return (this->_last_name);
}

std::string	Contact::get_nickname(void) const
{
	return (this->_nickname);
}

std::string	Contact::get_phone_number(void) const
{
	return (this->_phone_number);
}

std::string	Contact::get_darkest_secret(void) const
{
	return (this->_darkest_secret);
}

static	void print_column(std::string value)
{
	if (value.length() > 10)
		value = value.substr(0, 9) + ".";
	else if (value.length() == 0)
		value = "(empty)";
	std::cout << std::right << std::setw(10) << value;
	std::cout << "│";
}

void	Contact::print_contact_line(std::string color, const int indentation, const int index) const
{
	std::string	col_value;
	
	for (int i = 0; i < indentation; i++)
		std::cout << " ";
	std::cout << color << "├─ │";
	print_column(int_to_str(index));
	print_column(get_first_name());
	print_column(get_last_name());
	print_column(get_nickname());
	std::cout << COLOR_RESET << std::endl;
}
