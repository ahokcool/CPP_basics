/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 14:43:40 by astein            #+#    #+#             */
/*   Updated: 2024/03/02 15:08:03 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "freak_bible.hpp"

std::string int_to_str(int number) {
    std::stringstream ss;
    ss << number;
    return ss.str();
}

void	format_output(std::string str, std::string color, int indentation, bool newline, int setw)
{
	for (int i = 0; i < indentation; i++)
		std::cout << " ";
	std::cout << color << "├─ ";
	if (setw > 0)
		std::cout << std::left << std::setw(setw) << str << COLOR_RESET;
	else
		std::cout << color << str << COLOR_RESET;
	if (newline)
		std::cout << std::endl;
}

std::string get_input(std::string promt, bool mandatory, std::string color, int indentation, int setw)
{
	std::string cur_line;

	promt = promt + ": ";
	format_output(promt, color, indentation, false, setw);
	getline(std::cin, cur_line);
	while (cur_line == "" && mandatory)
	{
		format_output("Please enter a value!", COLOR_RED, indentation + 2, true, -1);
		format_output(promt, color, indentation, false, setw);
		getline(std::cin, cur_line);
	}
	return (cur_line);
}

int get_input_index(std::string promt, std::string color, int indentation)
{
	std::string cur_line;
	int 		index;

	promt = promt + ": ";
	index = -1;
	while(true)
	{
		format_output(promt, color, indentation, false, -1);
		getline(std::cin, cur_line);
		std::istringstream iss(cur_line);
		if (!(iss >> index))
     	   format_output("non numeric input - try again!", COLOR_RED, indentation + 2, true, -1);
    	else
		{
			if (index >= 0 && index < 8)
				return (index);
			else
				format_output("Invalid index! try again!", COLOR_RED, indentation + 2, true, -1);
    	}
	}
}