/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:50:48 by astein            #+#    #+#             */
/*   Updated: 2024/03/01 20:48:19 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

Phonebook::Phonebook() : _cur_contact(-1){}

int Phonebook::get_contact_count(void) const
{
	return (_cur_contact);
}

void Phonebook::run()
{
	std::string cur_line;

	std::cout << "Welcome to your phonebook!" << std::endl;
	while (true)
	{
		cur_line = get_input("MAIN MENU", false, COLOR_YELLOW, 0);
		if (cur_line == "EXIT")
			break;
		else if (cur_line == "ADD")
			_add();
		else if (cur_line == "SEARCH")
			_search();
		else
			format_output("Invalid command! use: ADD, SEARCH or EXIT", COLOR_RED, 2, true);
	}
}

int	Phonebook::_get_contact_count(void) const
{
	int count;

	count = 0;	
	for (int i = 0; i < 8; i++)
	{
		if (_contacts[i].get_first_name() != "")
			count++;
	}
	std::cout << "count: " << count << std::endl;
	return (count);
}

void Phonebook::_add()
{
	_cur_contact++;
	if (_cur_contact >= 8 || _get_contact_count() == 8)
	{
		format_output("Phonebook is full! An old contact will be overwritten!", COLOR_YELLOW, 2, true);
		_cur_contact = 0;
	}
	format_output("Adding contact...", COLOR_GREEN, 2, true);
	_contacts[_cur_contact].set_contact();
	format_output("Added contact successfully!", COLOR_GREEN, 2, true);
}

void Phonebook::_search() const
{
	std::string	cur_line;
	int			index;
	
	format_output("Searching Contacts...", COLOR_BLUE, 2, true);
	format_output("┌──────────┬──────────┬──────────┬──────────┐", COLOR_CYAN, 4, true);
	format_output("│ INDEX    │First Name│ Last Name│ Nickname │", COLOR_CYAN, 4, true);
	format_output("├──────────┼──────────┼──────────┼──────────┤", COLOR_CYAN, 4, true);
	for (int i = 0; i < 8; i++)
	{
		_contacts[i].print_contact_line(COLOR_CYAN, 4, i);
	}
	format_output("└──────────┴──────────┴──────────┴──────────┘", COLOR_CYAN, 4, true);
	index = get_input_index("Which contact would you like to see? index", COLOR_BLUE, 2);
	_contacts[index].display_contact(4);
}
