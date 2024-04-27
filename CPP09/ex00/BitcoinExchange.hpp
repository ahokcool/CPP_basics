/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 18:01:56 by astein            #+#    #+#             */
/*   Updated: 2024/04/27 22:20:33 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <sstream>
# include <fstream>
# include <cstdlib>
# include <string>
# include <map>
# include <iomanip>
# include <math.h>

# define CLR_RED "\033[31m"
# define CLR_GRN "\033[32m"
# define CLR_YLW "\033[33m"
# define CLR_BLU "\033[34m"
# define CLR_ORN "\033[38;5;202m"
# define CLR_BLD "\033[1m"
# define CLR_RST "\033[0m"

# define CSV_FILE "data.csv"
# define PARSE_INPUT 0
# define PARSE_DATA 1

class BitcoinExchange
{
	public:
		// Constructors and destructors
		BitcoinExchange(bool print_info = false);
		BitcoinExchange(const BitcoinExchange &other);
		~BitcoinExchange();

		// Operator overloads
		BitcoinExchange &operator=(const BitcoinExchange &other);

		// Member function to do the calculations
		void	calculate(const std::string &filename) const;

	private:
		BitcoinExchange();

		// Member functions
		void	msgLine(const std::string &fn, int cur_line, const std::string &msg, const std::string &clr, bool print_anyway) const;
		bool	checkValue(double v, int type) const;
		bool	isValidDate(const std::string &date) const;
		bool	checkDate(const std::string &date, int type) const;
		void	loadFile(const std::string &filename, int type, std::map<std::string, double> &map) const;

		// Attributes
		std::map<std::string, double> 	_data;
		bool 							_print_info;
};

void	title(std::string str, bool newline_before, bool newline_after);
void	info(std::string str, std::string clr);

#endif