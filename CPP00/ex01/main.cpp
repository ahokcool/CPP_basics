/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:06:52 by astein            #+#    #+#             */
/*   Updated: 2024/03/01 17:54:35 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "my_awesome_phone_book.hpp"
# include "Phonebook.hpp"

void	format_output(std::string str, std::string color, int indentation, bool newline)
{
	for (int i = 0; i < indentation; i++)
		std::cout << " ";
	std::cout << color << "├─ " << str << COLOR_RESET;
	if (newline)
		std::cout << std::endl;
}

std::string get_input(std::string promt, bool mandatory, std::string color, int indentation)
{
	std::string cur_line;

	promt = promt + ": ";
	format_output(promt, color, indentation, false);
	getline(std::cin, cur_line);
	while (cur_line == "" && mandatory)
	{
		format_output("Please enter a value!", COLOR_RED, indentation + 2, true);
		format_output(promt, color, indentation, false);
		getline(std::cin, cur_line);
	}
	return (cur_line);
}

int main()
{
	Phonebook my_phonebook;

	my_phonebook.run();
	return (0);
}