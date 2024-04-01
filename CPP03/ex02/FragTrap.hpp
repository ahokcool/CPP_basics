/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:59:11 by astein            #+#    #+#             */
/*   Updated: 2024/04/01 21:29:41 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		// Constructors and Destructor
		FragTrap(std::string name);
		FragTrap(const FragTrap &other);
		~FragTrap();
		
		// Operator overloads
		FragTrap	&operator=(const FragTrap &other);
		
		// Member functions
		void		attack(const std::string &target); //Not needed by the subject
		void		highFivesGuys() const;
		
	private:
		FragTrap();	// private default constructor
		
};

#endif