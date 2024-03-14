/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 14:43:40 by astein            #+#    #+#             */
/*   Updated: 2024/03/14 17:41:34 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "freak_bible.hpp"

std::string	int_to_str(const int number) {
    std::stringstream ss;
    ss << number;
    return ss.str();
}

void		format_output(const std::string str, const std::string color, const int indentation, const bool newline, const int setw)
{
	for (int i = 0; i < indentation; i++)
		std::cout << " ";
	std::cout << color << "├─ ";
	if (setw > 0)
		std::cout << std::left << std::setw(setw) << str << COLOR_RESET;
	else
		std::cout << str << COLOR_RESET;
	if (newline)
		std::cout << std::endl;
}

std::string	get_input(const std::string promt, const bool mandatory, const std::string color, const int indentation, const int setw)
{
	std::string cur_line;
	std::string lng_promt;

	if (std::cin.eof() || std::cin.fail())
			return "EXIT";
	lng_promt = promt + ": ";
	format_output(lng_promt, color, indentation, false, setw);
	getline(std::cin, cur_line);
	if (std::cin.eof() || std::cin.fail())
		return "EXIT";
	while (cur_line == "" && mandatory)
	{
		if (std::cin.eof() || std::cin.fail())
			return "EXIT";
		format_output("Please enter a value!", COLOR_RED, indentation + 2, true, -1);
		format_output(lng_promt, color, indentation, false, setw);
		getline(std::cin, cur_line);
		if (std::cin.eof() || std::cin.fail())
			return "EXIT";
	}
	return cur_line;
}

int 		get_input_index(const std::string promt, const std::string color, const int indentation)
{
	std::string cur_line;
	std::string lng_promt;
	int 		index;

	lng_promt = promt + ": ";
	index = -1;
	while(true)
	{
		format_output(lng_promt, color, indentation, false, -1);
		getline(std::cin, cur_line);
		if (std::cin.eof() || std::cin.fail())
			return -1;
		std::istringstream iss(cur_line);
		if (!(iss >> index))
     	   format_output("non numeric input - try again!", COLOR_RED, indentation + 2, true, -1);
    	else
		{
			if (index >= 0 && index < 8)
				return index;
			else
				format_output("Invalid index! try again!", COLOR_RED, indentation + 2, true, -1);
    	}
	}
}