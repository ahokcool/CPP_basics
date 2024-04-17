/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:32:28 by astein            #+#    #+#             */
/*   Updated: 2024/04/17 20:21:53 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <sstream>
# include <iomanip>

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
	ERROR,
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	PSEUDO_N_INF,
	PSEUDO_P_INF,
	PSEUDO_NAN,
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
		static int					check_pseudo(const std::string &str);
		static int					check_char(const std::string &str);
		static int					check_number(const std::string &str);

		// Static put functions
		static void				put_char(const char c);
		// static void				put_int(const int *i);
		// static void				put_float(const float *f);
		// static void				put_double(const double *d);
		static void				put_pseudo(const int type);
		static void				put_error();
};

#endif
