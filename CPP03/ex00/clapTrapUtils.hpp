/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clapTrapUtils.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:53:57 by astein            #+#    #+#             */
/*   Updated: 2024/03/21 14:31:45 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAPUTILS_HPP
# define CLAPTRAPUTILS_HPP

# include "ClapTrap.hpp"
# include <iostream>

// Escape sequences for terminal colors
# define COLOR_RESET  "\x1b[0m"
# define COLOR_RED    "\x1b[31m"
# define COLOR_GREEN  "\x1b[32m"
# define COLOR_BLUE   "\x1b[34m"
# define COLOR_PURPLE "\x1b[35m"
# define COLOR_YELLOW "\x1b[33m"
# define COLOR_CYAN   "\x1b[36m"

void		print_status(const ClapTrap &c);
void		print_all_status(const ClapTrap &c);
ClapTrap	*getClapTrap(const ClapTrap &c, const std::string &name);
void		deleteClapTrap(const ClapTrap *c);
void		addClapTrap(ClapTrap *c);
int			getClapTrapCount(ClapTrap *c);

#endif
