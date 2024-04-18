/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:32:28 by astein            #+#    #+#             */
/*   Updated: 2024/04/18 12:36:57 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <sstream>
# include <iomanip>
# include <cerrno>
# include <cstdlib>
# include <limits>
# include <cmath>


// COLORS
# define CLR_RED "\033[31m"
# define CLR_GRN "\033[32m"
# define CLR_YLW "\033[33m"
# define CLR_BLU "\033[34m"
# define CLR_ORN "\033[38;5;202m"
# define CLR_BLD "\033[1m"
# define CLR_RST "\033[0m"

// INPUT TYPES
enum
{
	ERROR,			// 0
	CHAR,			// 1
	NUMBER,			// 2
	PSEUDO_N_INF,	// 3
	PSEUDO_P_INF,	// 4
	PSEUDO_NAN,		// 5
};

class ScalarConverter
{
	public:
		static void 		convert(const std::string &str);

	private:
		// Constructor and Destructor
		ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		~ScalarConverter();

		// Operator Overload
		ScalarConverter 	&operator=(const ScalarConverter &other);

		// Static type functions
		static int				check_pseudo(const std::string &str);
		static int				check_char(const std::string &str);
		static int				check_number(const std::string &str);

		// Static put functions
		static void				put_char(const double c);
		static void				put_error();
		static void				put_pseudo(const int type);
		
		// Static functions to print all 4 lines for one type
		static void				type_char(const char c);
		static void				type_number(const std::string &str);
};

#endif
