/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:17:20 by astein            #+#    #+#             */
/*   Updated: 2024/04/01 15:24:08 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	public:
		// Constructors and Destructor
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap &other);
		~DiamondTrap();

		// Operator overloads
		DiamondTrap			&operator=(const DiamondTrap &other);
		
		// Needs an override because this class has a different name than the base class
		const std::string	getName() const;		

		// Needs an override because both ScavTrap and FragTrap have an attack function
		void				attack(const std::string &target);
		
		//  Member functions
		void				whoAmI() const;
		
	private:
		DiamondTrap();	// private default constructor
		std::string	_name;
};

#endif
