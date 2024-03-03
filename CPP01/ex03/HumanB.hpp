/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 01:06:27 by astein            #+#    #+#             */
/*   Updated: 2024/03/03 02:41:22 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <iostream>
# include <string>
# include "Weapon.hpp"

class HumanB
{
	private:
		std::string	_name;
		Weapon*		_weapon;
		
	public:
		HumanB(const std::string& name);
		~HumanB();
		HumanB& operator= (const HumanB& assign);

		void	attack() const;
		void	setWeapon(Weapon& weapon);
};

#endif