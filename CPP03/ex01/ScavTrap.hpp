/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:37:40 by astein            #+#    #+#             */
/*   Updated: 2024/04/01 14:53:27 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		// Constructors and Destructor
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &other);
		~ScavTrap();
		
		// Operator overloads
		ScavTrap	&operator=(const ScavTrap &other);

		// Member functions
		void		attack(const std::string &target);
		void		guardGate();
		
	private:
		ScavTrap();	// private default constructor
		bool	_gateKeeperMode;
};

#endif