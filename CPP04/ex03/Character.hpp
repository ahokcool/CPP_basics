/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 22:37:05 by astein            #+#    #+#             */
/*   Updated: 2024/04/02 15:36:37 by astein           ###   ########.fr       */
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
		// Note: When calling the 'unequip' member function, the pointer
		// to the materia is lost. This means that the materia is not
		// deleted from memory. This is a memory leak. To avoid this, the
		// calling code should delete the materia after calling 'unequip'.
		// Therefore the function 'getMateria' is provided to get the
		// pointer to the materia before calling 'unequip'.
		virtual void				unequip(int idx);
		virtual void 				use(int idx, ICharacter &target);
		AMateria					*getMateria(int idx) const;

	private:
		std::string					_name;
		AMateria*					_materia[4];
};

#endif