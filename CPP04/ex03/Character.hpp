/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 22:37:05 by astein            #+#    #+#             */
/*   Updated: 2024/03/29 01:46:37 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include <iostream>

// Forward declaration
class AMateria;

class Character : public ICharacter
{
	public:
		Character();
		Character(const std::string name);
		Character(const Character &other);
 		Character & operator=(const Character &other);
		virtual ~Character();

		const std::string 	&getName() const;
		void 				equip(AMateria *m);
		void				unequip(int idx);
		void 				use(int idx, ICharacter &target);

	private:
		std::string	_name;
		AMateria*	_materia[4];
};

#endif