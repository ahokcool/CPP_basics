/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:10:10 by astein            #+#    #+#             */
/*   Updated: 2024/03/30 17:38:59 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <iostream>

class ClapTrap
{

	public:
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &other);
		ClapTrap &operator=(const ClapTrap &other);
		~ClapTrap();

		// Getter
		std::string			getName() const;
		unsigned int		getHitPoints() const;
		unsigned int		getEnergyPoints() const;
		unsigned int		getAttackDamage() const;
		ClapTrap			*getHead() const;
		ClapTrap			*getNext() const;

		// Setter
		void				setHead(ClapTrap *head);
		void				setNext(ClapTrap *next);

		// Member functions
		void				attack(const std::string &target);
		void				takeDamage(unsigned int amount);
		void				beRepaired(unsigned int amount);

	private:
		ClapTrap(); 							// private default constructor
		const std::string	_name;				// Unique name of the ClapTrap
		unsigned int		_hitPoints;			// Health points
		unsigned int		_energyPoints;		// Energy is needed to attack and repair
		unsigned int		_attackDamage;		// How strong the hit is
		ClapTrap			*_next;				// All instances are stored in a linked list
		static ClapTrap		*_head;
};

#endif