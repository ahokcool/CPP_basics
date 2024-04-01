/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:59:11 by astein            #+#    #+#             */
/*   Updated: 2024/03/21 22:22:29 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap
{
	public:
		FragTrap(std::string name);
		FragTrap(const FragTrap &other);
		~FragTrap();
		
		// Overriding base class member functions
		void	print_status() const;
		void	attack(const std::string &target);
		
		// Member functions
		void	highFivesGuys();
		
	private:
		FragTrap();	// private default constructor
};

#endif
