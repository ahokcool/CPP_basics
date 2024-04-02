/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 22:25:43 by astein            #+#    #+#             */
/*   Updated: 2024/04/02 14:14:25 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

// Do not include AMateria.hpp here, because of circular dependency
// # include "AMateria.hpp"
// Instead use forward declaration:
class AMateria;

class ICharacter
{
	public:
		virtual ~ICharacter() {}
		virtual const std::string 	&getName() const = 0;
		virtual void 				equip(AMateria *m) = 0;
		virtual void 				unequip(int idx) = 0;
		virtual void 				use(int idx, ICharacter &target) = 0;
};

#endif
