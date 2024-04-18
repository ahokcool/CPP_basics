/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:38:16 by astein            #+#    #+#             */
/*   Updated: 2024/04/18 12:36:04 by astein           ###   ########.fr       */
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

// Returns PSEUDO_N_INF, PSEUDO_P_INF or PSEUDO_NAN
// if the string is a pseudo number
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

// Returns CHAR if the string is a single char
int		ScalarConverter::check_char(const std::string &str)
{
	if (str.length() == 1 && !isdigit(str[0]))
		return CHAR;
	return ERROR;
}

// Returns NUMBER if the string is an int, float or double
// Returns ERROR if the string is not a number
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
		return NUMBER;
	
	// If there is a dot, it could be float or double, else error
	if (str[i] == '.')
	{
		i++;
		// Skip all numeric values (after the dot)
		while (str[i] && isdigit(str[i]))
			i++;
		// If string is over its a double
		if (!str[i])
			return NUMBER;	// double
		else if (str[i] == 'f' && !str[i + 1])
			return NUMBER;	// float
		else
			return ERROR;
	}
	else
		return ERROR;	
}

void 	ScalarConverter::put_char(const double c)
{
	// Print the char if possible
	// Since the argument is a double, we have to check if the double
	// is in the range of a char
	if (c >= std::numeric_limits<char>::min() && c <= std::numeric_limits<char>::max())
	{
		if (isprint(static_cast<char>(c)))
			std::cout << "\tchar:\t'" << CLR_GRN << static_cast<char>(c) << CLR_RST << "'" << std::endl;
		else
			std::cout << "\tchar:\t" << CLR_RED << "non displayable" << CLR_RST << std::endl;
	}
	else
		std::cout << "\tchar:\t" << CLR_RED << "impossible" << CLR_RST << std::endl;
}

void	ScalarConverter::put_error()
{
	std::cout << "\tchar:\t"	<< CLR_RED << "impossible" << CLR_RST << std::endl;
	std::cout << "\tint:\t" 	<< CLR_RED << "impossible" << CLR_RST << std::endl;
	std::cout << "\tfloat:\t" 	<< CLR_RED << "impossible" << CLR_RST << std::endl;
	std::cout << "\tdouble:\t" 	<< CLR_RED << "impossible" << CLR_RST << std::endl;
}

void	ScalarConverter::put_pseudo(const int type)
{
	std::cout << "\tchar:\t" << CLR_RED << "impossible" << CLR_RST << std::endl;
	std::cout << "\tint:\t" << CLR_RED << "impossible" << CLR_RST << std::endl;
	switch (type)
	{
		case PSEUDO_N_INF:
			std::cout << "\tfloat:\t" << CLR_YLW << "-inff" << CLR_RST << std::endl;
			std::cout << "\tdouble:\t" << CLR_YLW << "-inf" << CLR_RST << std::endl;
			break;
		case PSEUDO_P_INF:
			std::cout << "\tfloat:\t" << CLR_YLW << "+inff" << CLR_RST << std::endl;
			std::cout << "\tdouble:\t" << CLR_YLW << "+inf" << CLR_RST << std::endl;
			break;
		case PSEUDO_NAN:
			std::cout << "\tfloat:\t" << CLR_YLW << "nanf" << CLR_RST << std::endl;
			std::cout << "\tdouble:\t" << CLR_YLW << "nan" << CLR_RST << std::endl;
			break;
	}
}

void 	ScalarConverter::type_char(const char c)
{
	// Print the char if possible
	put_char (c);
	// Cast the char to int, float and double and print them
	std::cout << "\tint:\t" 	<< CLR_GRN << static_cast<int>(c) << CLR_RST << std::endl;
	std::cout << "\tfloat:\t"	<< CLR_GRN << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << CLR_RST << std::endl;
	std::cout << "\tdouble:\t" 	<< CLR_GRN << std::fixed << std::setprecision(1) << static_cast<double>(c) << CLR_RST << std::endl;
}

void	ScalarConverter::type_number(const std::string &str)
{
	errno = 0;
	double d = std::strtod(str.c_str(), NULL);
	if (d == HUGE_VAL || d == -HUGE_VAL || errno == ERANGE)
	{
		// The number is bigger than the maximum value of an double,
		// so it's impossible to convert it to char, int, float or double!
		put_error();
		return ;
	}
	
	// Print the char if possible
	put_char(d);
	
	// Print the int if possible
	if (d >= std::numeric_limits<int>::min() && d <= std::numeric_limits<int>::max())
	{
		int i = static_cast<int>(d);
		std::cout << "\tint:\t" << CLR_GRN << i << CLR_RST << std::endl;
	}
	else
		std::cout << "\tint:\t" << CLR_RED << "impossible" << CLR_RST << std::endl;

	// Print the float if possible
	// NOTE:
	// U  have to check for -max instead of std::numeric_limits<float>::min()
	// because the min value is the smallest positive value a float can have
	// and not the smallest negative value!
	if (d >= -std::numeric_limits<float>::max() && d <= std::numeric_limits<float>::max())
	{
		float f = static_cast<float>(d);
		std::cout << "\tfloat:\t" << CLR_GRN << std::fixed << std::setprecision(1) << f << "f" << CLR_RST << std::endl;
	}
	else
		std::cout << "\tfloat:\t" << CLR_RED << "impossible" << CLR_RST << std::endl;

	// Print the double
	std::cout << "\tdouble:\t" << CLR_GRN << std::fixed << std::setprecision(1) << d << CLR_RST << std::endl;
}

void 	ScalarConverter::convert(const std::string &str)
{
	if (str.empty())
	{
		std::cout << CLR_BLU << "Start converting: " << "NULL aka empty string" << CLR_RED << std::endl;
		ScalarConverter::put_error();
	}
	else
	{
		std::cout << CLR_BLU << "Start converting: " << str << CLR_RST;
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
		std::cout << " (type: " << type << ")" << std::endl;
		// print the determined values
		switch (type)
		{
			case ERROR:
				ScalarConverter::put_error();
				break;	
			case CHAR:
				ScalarConverter::type_char(str[0]);
				break;
			case NUMBER:
				ScalarConverter::type_number(str);
				break;
				
			default:
				ScalarConverter::put_pseudo(type);
		}
	}
	std::cout << std::endl;
}