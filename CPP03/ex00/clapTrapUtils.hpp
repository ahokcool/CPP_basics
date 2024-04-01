/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clapTrapUtils.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:53:57 by astein            #+#    #+#             */
/*   Updated: 2024/04/01 13:33:28 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAPUTILS_HPP
# define CLAPTRAPUTILS_HPP

# include "ClapTrap.hpp"

// Escape sequences for terminal colors
# define COLOR_RESET  "\x1b[0m"
# define COLOR_RED    "\x1b[31m"
# define COLOR_GREEN  "\x1b[32m"
# define COLOR_BLUE   "\x1b[34m"
# define COLOR_PURPLE "\x1b[35m"
# define COLOR_YELLOW "\x1b[33m"
# define COLOR_CYAN   "\x1b[36m"

// Print Functions
void		print_status(const ClapTrap &c);
void		print_all_status();

// Linked List Functions
void		addCT(ClapTrap *c);
void		removeCT(ClapTrap *c);

// Utils
ClapTrap	*getCTbyName(const std::string &name);
int			getCTCount();

#endif
