/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:06:52 by astein            #+#    #+#             */
/*   Updated: 2024/03/01 20:11:57 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "freak_bible.hpp"
# include "Phonebook.hpp"

std::string int_to_str(int number) {
    std::stringstream ss;
    ss << number;
    return ss.str();
}

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

int get_input_index(std::string promt, std::string color, int indentation)
{
	char input;

	input = 0;
	promt = promt + ": ";
	while(true)
	{
		format_output(promt, color, indentation, false);
		std::cin >> input;
		std::cout << input << std::endl;
		break;
	}
	return (input);
}

int main()
{
	Phonebook my_phonebook;

	my_phonebook.run();
	return (0);
}