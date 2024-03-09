/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 17:58:14 by astein            #+#    #+#             */
/*   Updated: 2024/03/09 18:20:20 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

// Constructor
Harl::Harl()
{
	std::cerr << "Constructor: Harl is here" << std::endl;
}

// Destructor
Harl::~Harl()
{
	std::cerr << "Destructor: Harl is gone" << std::endl;
}

void Harl::_debug() const
{
    std::cerr << "Debug Message goes like bla bla bla..." << std::endl;
}

void Harl::_info() const
{
	std::cerr << "Info Message goes like bla bla bla..." << std::endl;
}

void Harl::_warning() const
{
    std::cerr << "Warning Message goes like bla bla bla..." << std::endl;
}

void Harl::_error() const
{
	std::cerr << "Error Message goes like bla bla bla..." << std::endl;
}

void Harl::complain(const std::string level) const
{
	void 		(Harl::*fnc_ptrs[4])() const = {&Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error};
	std::string	complain_lvls[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	bool		found = false;
	
	for (int i = 0; i < 4; i++)
	{
		if (!complain_lvls[i].compare(level))
		{
			(this->*fnc_ptrs[i])();
			found = true;
			break;
		}
	}
	if (!found)
		std::cerr << "Invalid complaint level!" << std::endl;
}

void Harl::complain_filter(const std::string level) const
{
	void 		(Harl::*fnc_ptrs[4])() const = {&Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error};
	std::string	complain_lvls[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int			complain_lvl = -1;
	std::string clr_red = "\033[31m";
	std::string clr_orange = "\033[91m";
	std::string clr_yellow = "\033[33m";
	std::string clr_blue = "\033[34m";
	std::string clr_reset = "\033[0m";
	
	for (int i = 0; i < 4; i++)
	{
		if (!complain_lvls[i].compare(level))
		{
			complain_lvl = i;
			break;
		}
	}
	
	switch (complain_lvl)
	{
	case 0:
		std::cerr << clr_yellow << std::endl << "[ " +complain_lvls[0] + " ]" << clr_reset << std::endl;
		(this->*fnc_ptrs[0])();
	case 1:
		std::cerr << clr_blue << std::endl << "[ " +complain_lvls[1] + " ]" << clr_reset << std::endl;
		(this->*fnc_ptrs[1])();
	case 2:
		std::cerr << std::endl << clr_orange << "[ " +complain_lvls[2] + " ]" << clr_reset << std::endl;
		(this->*fnc_ptrs[2])();
	case 3:
		std::cerr << std::endl << clr_red << "[ " +complain_lvls[3] + " ]" << clr_reset << std::endl;
		(this->*fnc_ptrs[3])();
		break;
	
	default:
		std::cerr << "Invalid complaint level!" << std::endl;
	}
}
