/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 16:33:08 by astein            #+#    #+#             */
/*   Updated: 2024/03/09 18:09:31 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

// Constructor
Harl::Harl()
{
	std::cerr << "Harl is here" << std::endl;
}

// Destructor
Harl::~Harl()
{
	std::cerr << "Harl is gone" << std::endl;
}

void Harl::_debug() const
{
    std::cerr << "Debug" << std::endl;
}

void Harl::_info() const
{
	std::cerr << "Info" << std::endl;
}

void Harl::_warning() const
{
    std::cerr << "Warning" << std::endl;
}

void Harl::_error() const
{
	std::cerr << "Error" << std::endl;
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
