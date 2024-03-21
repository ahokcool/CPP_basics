/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:17:20 by astein            #+#    #+#             */
/*   Updated: 2024/03/21 22:22:03 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"
# include "clapTrapUtils.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	public:
		DiamondTrap(std::string name);
		~DiamondTrap();

		// Overriding base class member functions
		void				print_status() const;
		const std::string	getName() const;		//needs an override because this class has a different name than the base class

		// Choosing which attack to use
		using				ScavTrap::attack;
		
		//  Member functions
		void				whoAmI();
		
	private:
		DiamondTrap();	// private default constructor
		std::string	_name;
};

#endif
