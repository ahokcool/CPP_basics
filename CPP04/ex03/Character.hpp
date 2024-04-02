/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 22:37:05 by astein            #+#    #+#             */
/*   Updated: 2024/04/02 14:55:58 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include <iostream>

// Forward declaration
class AMateria;

/*	NOTE:
	The keyword 'virtual' is used in the declaration of the destructor and
	the member functions of the base class (interface) to ensure that the
	destructor and the member functions of the derived class are called
	when deleting a pointer to the base class that points to an object of
	the derived class.

	Since Chaaracter is not further derived, the destructor and the member
	functions do not need to be declared as virtual. Anyway, it's a good
	practice to keep it consistent with the base class.
*/

class Character : public ICharacter
{
	public:
		// Constructors and destructor
		Character();
		Character(const std::string &name);
		Character(const Character &other);
		virtual ~Character();

		// Operator overloads
 		Character 					&operator=(const Character &other);
		
		// Member functions from ICharacter
		virtual const std::string 	&getName() const;
		virtual void 				equip(AMateria *m);
		virtual void				unequip(int idx);
		virtual void 				use(int idx, ICharacter &target);

	private:
		std::string					_name;
		AMateria*					_materia[4];
};

#endif