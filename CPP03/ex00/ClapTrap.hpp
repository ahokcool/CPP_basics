/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:10:10 by astein            #+#    #+#             */
/*   Updated: 2024/04/01 21:07:27 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <iostream>

class ClapTrap
{
	public:
		// Constructors and Destructor
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &other);
		~ClapTrap();

		// Operator overloads
		ClapTrap 			&operator=(const ClapTrap &other);
		
		// Public Member functions
		void				attack(const std::string &target);
		void				takeDamage(unsigned int amount);
		void				beRepaired(unsigned int amount);
		
		// Accessors (Getters)
		std::string			getName() const;
		unsigned int		getHitPoints() const;
		unsigned int		getEnergyPoints() const;
		unsigned int		getAttackDamage() const;
		ClapTrap			*getNext() const;

		// Mutators (Setters)
		void				setNext(ClapTrap *next);

		// Static functions
		static ClapTrap		*getHead();
		static void			setHead(ClapTrap *head);

	// The member attributes should be protected instead of private so that
	// derived classes can access their member attributes without the detour
	// of inhherited getters and setter!
	private:
		ClapTrap(); 							// Private default constructor
		std::string			_name;				// Name of the ClapTrap
		unsigned int		_hitPoints;			// Health points
		unsigned int		_energyPoints;		// Energy is needed to attack and repair
		unsigned int		_attackDamage;		// How strong the hit is
		ClapTrap			*_next;				// All instances are stored in a linked list
		static ClapTrap		*_head;
};

#endif