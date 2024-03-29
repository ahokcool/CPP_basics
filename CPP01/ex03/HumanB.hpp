/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 01:06:27 by astein            #+#    #+#             */
/*   Updated: 2024/03/29 21:52:10 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class HumanB
{
	public:
		HumanB(const std::string &name);
		~HumanB();

		// Member functions
		void	attack() const;
		void	setWeapon(Weapon &weapon);
		
	private:
		std::string	_name;
		Weapon		*_weapon;
};

#endif
