/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freak_bible.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:15:10 by astein            #+#    #+#             */
/*   Updated: 2024/03/02 15:39:50 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREAK_BIBLE_HPP
# define FREAK_BIBLE_HPP

# include <string>
# include <iostream>
# include <sstream>
# include <iomanip>


// Escape sequences for terminal colors
#define COLOR_RESET  "\x1b[0m"
#define COLOR_RED    "\x1b[31m"
#define COLOR_GREEN  "\x1b[32m"
#define COLOR_BLUE   "\x1b[34m"
#define COLOR_PURPLE "\x1b[35m"
#define COLOR_YELLOW "\x1b[33m"
#define COLOR_CYAN   "\x1b[36m"

std::string	int_to_str(const int number);
std::string get_input(const std::string promt, const bool mandatory, const std::string color, const int indentation, const int setw);
int			get_input_index(const std::string promt, const std::string color, const int indentation);
void		format_output(const std::string str, const std::string color, const int indentation, const bool newline, const int setw);

#endif
