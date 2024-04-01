/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:59:11 by astein            #+#    #+#             */
/*   Updated: 2024/04/01 15:16:56 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	public:
		// Constructors and Destructor
		FragTrap(std::string name);
		FragTrap(const FragTrap &other);
		virtual ~FragTrap();
		
		// Operator overloads
		FragTrap			&operator=(const FragTrap &other);
		
		// Member functions
		void				attack(const std::string &target);
		void				highFivesGuys() const;
		
	private:
		FragTrap();	// private default constructor
		
};

#endif