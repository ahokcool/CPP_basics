/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:50:48 by astein            #+#    #+#             */
/*   Updated: 2024/03/21 13:50:43 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

Phonebook::Phonebook(void) : _cur_contact(-1){}

int		Phonebook::get_contact_index(void) const { return (_cur_contact); }

int		Phonebook::_get_contact_count(void) const
{
	int count;

	count = 0;	
	for (int i = 0; i < 8; i++)
	{
		if (_contacts[i].get_first_name() != "")
			count++;
	}
	return count;
}

void	Phonebook::run(void)
{
	std::string cur_line;

	std::cout << COLOR_CYAN << std::endl << std::endl;
	std::cout << " ┌────────────────────────────┐" << std::endl;
	std::cout << " │ Welcome to the freak bible │" << std::endl;
	std::cout << " └────────────────────────────┘" << std::endl;
	std::cout << COLOR_RESET;

	while (true)
	{
		cur_line = get_input("MAIN MENU", false, COLOR_YELLOW, 0, -1);
		if (cur_line == "EXIT" || cur_line == "e")
			break;
		else if (cur_line == "ADD" || cur_line == "a")
			_add();
		else if (cur_line == "SEARCH" || cur_line == "s")
			_search();
		else
			format_output("Invalid command! use: ADD (a), SEARCH (s) or EXIT (e)", COLOR_RED, 2, true, -1);
	}
}

void	Phonebook::_add(void)
{
	_cur_contact++;
	if (_cur_contact >= 8)
	{
		format_output("Phonebook is full! An old contact will be overwritten!", COLOR_YELLOW, 2, true, -1);
		_cur_contact = 0;
	}
	else if (_get_contact_count() == 8)
		format_output("Phonebook is full! An old contact will be overwritten!", COLOR_YELLOW, 2, true, -1);
	format_output("Adding contact...", COLOR_GREEN, 2, true, -1);
	if (_contacts[_cur_contact].set_contact())
		format_output("Added contact successfully!", COLOR_GREEN, 2, true, -1);
	else
	{
		std::cout << std::endl;
		format_output("Contact not added!", COLOR_RED, 2, true, -1);
	}
}

void	Phonebook::_search() const
{
	std::string	cur_line;
	int			index;
	
	format_output("Searching Contacts...", COLOR_BLUE, 2, true, -1);
	format_output("┌──────────┬──────────┬──────────┬──────────┐", COLOR_CYAN, 4, true, -1);
	format_output("│ INDEX    │First Name│ Last Name│ Nickname │", COLOR_CYAN, 4, true, -1);
	format_output("├──────────┼──────────┼──────────┼──────────┤", COLOR_CYAN, 4, true, -1);
	for (int i = 0; i < 8; i++)
	{
		_contacts[i].print_contact_line(COLOR_CYAN, 4, i);
	}
	format_output("└──────────┴──────────┴──────────┴──────────┘", COLOR_CYAN, 4, true, -1);
	index = get_input_index("Which contact would you like to see? index", COLOR_BLUE, 2);
	if (index == -1)
		return;
	_contacts[index].display_contact(4);
}
