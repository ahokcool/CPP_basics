/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:59:11 by astein            #+#    #+#             */
/*   Updated: 2024/03/21 17:13:02 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap(std::string name);
		FragTrap(const FragTrap &other);
		~FragTrap();
		
		// Member functions
		void	attack(const std::string &target);
		void	highFivesGuys();
		
	private:
		FragTrap();	// private default constructor
		
};




#endif