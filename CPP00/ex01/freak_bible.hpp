/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freak_bible.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:15:10 by astein            #+#    #+#             */
/*   Updated: 2024/03/01 20:11:57 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREAK_BIBLE_HPP
# define FREAK_BIBLE_HPP

# include <string>
# include <iostream>
#include <sstream>

// Escape sequences for terminal colors
#define COLOR_RESET  "\x1b[0m"
#define COLOR_RED    "\x1b[31m"
#define COLOR_GREEN  "\x1b[32m"
#define COLOR_BLUE   "\x1b[34m"
#define COLOR_PURPLE "\x1b[35m"
#define COLOR_YELLOW "\x1b[33m"
#define COLOR_CYAN   "\x1b[36m"

std::string	int_to_str(int number);
std::string	get_input(std::string promt, bool mandatory, std::string color, int indentation);
int			get_input_index(std::string promt, std::string color, int indentation);
void		format_output(std::string str, std::string color, int indentation, bool newline);

#endif
