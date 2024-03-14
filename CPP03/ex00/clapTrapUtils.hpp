/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clapTrapUtils.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:53:57 by astein            #+#    #+#             */
/*   Updated: 2024/03/14 18:16:10 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAPUTILS_HPP
# define CLAPTRAPUTILS_HPP

# include "ClapTrap.hpp"

void		print_status(const ClapTrap &c);
ClapTrap	*getClapTrap(const std::string &name);
void		deleteClapTrap(const ClapTrap *c);
void		addClapTrap(const ClapTrap *c);

#endif