/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:38:16 by astein            #+#    #+#             */
/*   Updated: 2024/04/17 20:22:57 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

// Privte Constructor so the class isn't instanciable
ScalarConverter::ScalarConverter()
{
	// Nothing to do here
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	(void)other;
}

ScalarConverter::~ScalarConverter()
{
	// Nothing to do here
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	return *this;
}

int		ScalarConverter::check_pseudo(const std::string &str)
{
	if (str == "-inff" || str == "-inf")
		return PSEUDO_N_INF;
	if (str == "+inff" || str == "+inf")
		return PSEUDO_P_INF;
	if (str == "nanf" || str == "nan")
		return PSEUDO_NAN;
	return ERROR;
}

int		ScalarConverter::check_char(const std::string &str)
{
	if (str.length() == 1 && !isdigit(str[0]))
		return CHAR;
	return ERROR;
}

int		ScalarConverter::check_number(const std::string &str)
{
	int i = 0;
	// Trim whitespaces
	while (str[i] && isspace(str[i]))
		i++;

	// One sign is allowed
	if (str[i] && (str[i] == '+' || str[i] == '-'))
		i++;
	
	// Skip all numeric values
	while (str[i] && isdigit(str[i]))
		i++;
	
	// If string is over its an int
	if (!str[i])
		return INT;
	
	// If there is a dot, it could be float or double, else error
	if (str[i] == '.')
	{
		i++;
		// Skip all numeric values (after the dot)
		while (str[i] && isdigit(str[i]))
			i++;
		// If string is over its a double
		if (!str[i])
			return DOUBLE;
		else if (str[i] == 'f' && !str[i + 1])
			return FLOAT;
		else
			return ERROR;
	}
	else
		return ERROR;	
}


void 	ScalarConverter::put_char(const char c)
{
	// Print the required msg prefix
	std::cout << "\tchar:\t" 	<< CLR_GRN << c << CLR_RST << std::endl;
	std::cout << "\tint:\t" 	<< CLR_GRN << static_cast<int>(c) << CLR_RST << std::endl;
	std::cout << "\tfloat:\t"	<< CLR_GRN << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << CLR_RST << std::endl;
	std::cout << "\tdouble:\t" 	<< CLR_GRN << std::fixed << std::setprecision(1) << static_cast<double>(c) << CLR_RST << std::endl;
}
/* 
void 	ScalarConverter::put_int(const int *i)
{
	// Print the required msg prefix
	std::cout << "\tint:\t";
	
	// Check if int wasn't provided
	if (!i)
	{
		std::cout << CLR_RED << "impossible" << CLR_RST << std::endl;
		return ;
	}

	// Print the int
	std::cout << CLR_GRN << *i << CLR_RST << std::endl;
}

void 	ScalarConverter::put_float(const float *f)
{
	// Print the required msg prefix
	std::cout << "\tfloat:\t";
	
	// Check if float wasn't provided
	if (!f)
	{
		std::cout << CLR_RED << "impossible" << CLR_RST << std::endl;
		return ;
	}

	// Print the float
	std::cout << CLR_GRN << *f << "f" << CLR_RST << std::endl;
}

void 	ScalarConverter::put_double(const double *d)
{
	// Print the required msg prefix
	std::cout << "\tdouble:\t";
	
	// Check if double wasn't provided
	if (!d)
	{
		std::cout << CLR_RED << "impossible" << CLR_RST << std::endl;
		return ;
	}

	// Print the double
	std::cout << CLR_GRN << *d << CLR_RST << std::endl;
}
 */
void	ScalarConverter::put_pseudo(const int type)
{
	std::cout << "\tchar:\t" << CLR_RED << "impossible" << CLR_RST << std::endl;
	std::cout << "\tint:\t" << CLR_RED << "impossible" << CLR_RST << std::endl;
	switch (type)
	{
		case PSEUDO_N_INF:
			std::cout << "\tfloat:\t" << CLR_GRN << "-inff" << CLR_RST << std::endl;
			std::cout << "\tdouble:\t" << CLR_GRN << "-inf" << CLR_RST << std::endl;
			break;
		case PSEUDO_P_INF:
			std::cout << "\tfloat:\t" << CLR_GRN << "+inff" << CLR_RST << std::endl;
			std::cout << "\tdouble:\t" << CLR_GRN << "+inf" << CLR_RST << std::endl;
			break;
		case PSEUDO_NAN:
			std::cout << "\tfloat:\t" << CLR_GRN << "nanf" << CLR_RST << std::endl;
			std::cout << "\tdouble:\t" << CLR_GRN << "nan" << CLR_RST << std::endl;
			break;
	}
}

void	ScalarConverter::put_error()
{
	std::cout << "\tchar:\t" << CLR_RED << "impossible" << CLR_RST << std::endl;
	std::cout << "\tint:\t" << CLR_RED << "impossible" << CLR_RST << std::endl;
	std::cout << "\tfloat:\t" << CLR_RED << "impossible" << CLR_RST << std::endl;
	std::cout << "\tdouble:\t" << CLR_RED << "impossible" << CLR_RST << std::endl;
}

void 	ScalarConverter::convert(const std::string &str)
{
	if (str.empty())
	{
		std::cout << "Start converting: " << "NULL aka empty string" << std::endl;
		ScalarConverter::put_error();
	}
	else
	{
		std::cout << "Start converting: " << str << std::endl;
		// trim whitespaces and check if the string contains more than one word
		std::string word;
		std::string dummy;
		std::stringstream ss(str);
		// The stringsteam >> overload trims whitespaces and
		// reads until the next whitespace
		ss >> word;
		if (ss >> dummy)
		{
			std::cout << "Error: The string contains more than one word!" << std::endl;
			ScalarConverter::put_error();
			return ;
		}
		
		// define type
		int type = check_pseudo(str);
		if (type == ERROR)
			type = check_char(str);
		if (type == ERROR)
			type = check_number(str);
		
		// print the determined values
		switch (type)
		{
			case ERROR:
				ScalarConverter::put_error();
				break;	
			case CHAR:
				ScalarConverter::put_char(str[0]);
				break;
				
			default:
				ScalarConverter::put_pseudo(type);
		}
	}
	std::cout << std::endl;
}