/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 18:56:08 by astein            #+#    #+#             */
/*   Updated: 2024/04/28 16:12:04 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// Constructors and destructors
BitcoinExchange::BitcoinExchange()
{
	// Private...
}

BitcoinExchange::BitcoinExchange(bool print_info) : _print_info(print_info)
{
	if (_print_info)
		info ("Loading database stored in file: " + std::string(CSV_FILE), CLR_ORN);
	loadFile(CSV_FILE, PARSE_DATA, _data);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	// This uses the equal operator of the std::map class which is a deep copy
	_data = other._data;
}

BitcoinExchange::~BitcoinExchange()
{
	// Nothing to do here
}

// Operator overloads
BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this == &other)
		return *this;
	// This uses the equal operator of the std::map class which is a deep copy
	_data = other._data;
	return *this;
}

// Member functions
void			BitcoinExchange::msgLine(const std::string &fn, int cur_line, const std::string &msg, const std::string &clr, bool print_anyway) const
{
	if (_print_info || print_anyway)
	{
		std::cout << 
			"[" << fn <<
			": line " << 
			std::setw(2) << std::setfill('0') << cur_line << 
			"]: " << clr <<
			msg << CLR_RST <<
			std::endl;
	}
}

bool 			BitcoinExchange::checkValue(double v, int type) const
{
	// Since parsing the input.txt and the data.csv is similar I use the same
	// function to check the values. The only difference is the type which will
	// check if the input.txt values are in the right range.
	
	if(type == PARSE_DATA)
	{
		// The subject doenst say anything about the range of the values in the
		// data.csv but they have to be positive.
		if (v >= 0.0f)
			return true;
		else
			return false;
	}
	if (type == PARSE_INPUT)
	{
		// The subject is strange and says:
		// "A valid value must be either a float or a positive integer, between 0 and 1000."
		// So I assume that all values between 0f and 1000.0f are valid
		if (v >= 0.0f && v <= 1000.0f)
			return true;
		else
			return false;
	}
	// If the type is not valid
	return false;
}

bool			BitcoinExchange::isValidDate(const std::string &date) const
{
	// Check the basic format
    if (date.length() != 10 || date[4] != '-' || date[7] != '-') {
        return false;
    }

    // Extract year, month, day
    std::string yearStr = date.substr(0, 4);
    std::string monthStr = date.substr(5, 2);
    std::string dayStr = date.substr(8, 2);

    int year = atoi(yearStr.c_str());
    int month = atoi(monthStr.c_str());
    int day = atoi(dayStr.c_str());

	// The bitcoin was created in 2009
    if (year < 2009)
        return false;

    // Check month
    if (month < 1 || month > 12)
        return false;
    
    // Check day based on month and handle leap years
    switch (month)
	{
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            if (day < 1 || day > 31) return false;
            break;
        case 4: case 6: case 9: case 11:
            if (day < 1 || day > 30) return false;
            break;
        case 2:
            if ((year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)))
			{
                if (day < 1 || day > 29) return false;
			}
            else
			    if (day < 1 || day > 28) return false;
            break;
        default:
            return false;
    }

    return true;
}

bool 			BitcoinExchange::checkDate(const std::string &date, int type) const
{
	// Test if date is valid
	if (!isValidDate(date))
		return false;

	if(type == PARSE_DATA)
	{
		// The date hast to be unique (so I check if the date is already in the map)
		return (_data.find(date) == _data.end());
	}
	return true;
}

void			BitcoinExchange::loadFile(const std::string &filename, int type, std::map<std::string, double> &map) const
{
	std::ifstream	file(filename.c_str());
	std::string 	cur_line;
	int			 	cur_line_nr = 0;
	char 			sep = '|';
	size_t 			cur_sep_pos;
	std::string 	cur_date;
	double 			cur_value;

	// Set the right seperator for the right type
	if (type == PARSE_DATA)
		sep = ',';
	
	// Open the file
	if (!file.is_open())
	{
		std::cout << "Error: could not open file: " << filename << std::endl;
		return;
	}

	// Read the lines of the file
	while (std::getline(file, cur_line))
	{
		cur_line_nr++;
		// Check for the header
		// date,exchange_rate or date | value
		if (!_print_info && (cur_line == "date | value" || cur_line == "date,exchange_rate"))
			continue;
			
		if (cur_line.empty())
		{
			msgLine(filename, cur_line_nr, "<empty line>", CLR_YLW, false);
			continue;	
		}
		if (cur_line[0] == '#')
		{
			msgLine(filename, cur_line_nr, "<comment>", CLR_BLU, false);
			continue;	
		}
		cur_sep_pos = cur_line.find(sep);
		if (cur_sep_pos == std::string::npos)
		{
			msgLine(filename, cur_line_nr, "<no separator>", CLR_RED, false);
			continue;
		}

		// Extract the DATE...
		cur_date = cur_line.substr(0, cur_sep_pos).c_str();

		// Trim whitespaces in a stupid but easy way
		size_t i = 0;
		while (i < cur_date.length() && std::isspace(cur_date[i]))
			i++;
		cur_date = cur_date.substr(i);
		i = 0;
		while (cur_date[i] && !std::isspace(cur_date[i]))
			i++;
		cur_date = cur_date.substr(0, i);

		if (!checkDate(cur_date, type))
		{
			msgLine(filename, cur_line_nr, "<invalid/duplicate date>", CLR_RED, true);
			continue;
		}

		// Extract the VALUE...		
		cur_value = std::strtod(cur_line.substr(cur_sep_pos + 1).c_str(), NULL);

		// Check if the value is a valid double
		if (cur_value == HUGE_VAL || cur_value == -HUGE_VAL)
		{
			msgLine(filename, cur_line_nr, "<value bigger than double>", CLR_RED, true);
			continue;
		}
		
		if (!checkValue(cur_value, type))
		{
			msgLine(filename, cur_line_nr, "<invalid value>", CLR_RED, true);
			continue;
		}
			
		// Add the pair to the map and print the success message
		map[cur_date] = cur_value;
	}
	file.close();
}

void	BitcoinExchange::calculate(const std::string &filename) const
{
	// If the data map is empty aka the constructor failed
	// I dont have to do anything
	if (_data.empty())
	{
		info ("CALCULATE ERROR: No data available", CLR_RED);
		return;
	}
	
	if (_print_info)
		info ("Reading data from file: " + filename, CLR_ORN);
	
	// Map for the values of the input file
	std::map<std::string, double> in;

	// Load the input file
	loadFile(filename, PARSE_INPUT, in);

	// Loop through the input values and check if they are in the data map
	if (_print_info)
		info ("Results for input file: " + filename, CLR_ORN);
	std::map<std::string, double>::const_iterator itd;
	double cur_result;
	for (std::map<std::string, double>::const_iterator it = in.begin(); it != in.end(); it++)
	{
		// This prints:
		// "2009-01-01 =>        42.00 = "
		std::cout << CLR_BLU <<
            std::setw(10) << std::setfill(' ') << std::left << it->first << CLR_RST <<
            " => " << CLR_YLW <<
            std::fixed << std::setprecision(2) << std::setw(12) << std::setfill(' ') << std::right << it->second << CLR_RST <<
            " = ";
		
		// This returns the first element with a key bigger than the date
		// so I have to decrement the iterator to get the right element
		// https://en.cppreference.com/w/cpp/container/map/upper_bound
		itd = _data.upper_bound(it->first);

		// Test if the date is the database (i checked before if the db is empty)
		// 
		if (itd == _data.begin())
		{
			std::cout << std::fixed << std::setprecision(2) << std::setw(12) << std::setfill(' ') << std::right << "???.??" << CLR_RST;

			std::cout << CLR_RED << " (no data available since the lowest date in db is: " << _data.begin()->first << ")" << std::endl;
			continue;
		}
		--itd;			
		cur_result = it->second * itd->second;
		std::cout << CLR_ORN <<
		std::fixed << std::setprecision(2) << std::setw(12) << std::setfill(' ') << std::right << cur_result << CLR_RST;
		if (itd->first != it->first)
			std::cout << " (closest date: " << itd->first << ") " << std::endl;
		else
			std::cout << std::endl;
	}
}

// Helper functions for pretty outputs
void	title(std::string str, bool newline_before, bool newline_after)
{
	if (newline_before)
		std::cout << std::endl;
	std::cout << CLR_ORN <<
		">>> " << str << " <<<" <<
		CLR_RST << std::endl;
	if (newline_after)
		std::cout << std::endl;
}

void	info(std::string str, std::string clr)
{
	std::cout <<
		clr <<
		" >> " << str <<
		CLR_RST << std::endl;
}
