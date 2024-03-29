/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 01:02:53 by astein            #+#    #+#             */
/*   Updated: 2024/03/29 21:44:37 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>

class Weapon
{
	public:
		Weapon(const std::string &type);
		~Weapon();

		// Member functions
		const std::string	&getType() const;
		void				setType(const std::string &type);

	private:
		std::string	_type;
};

#endif
