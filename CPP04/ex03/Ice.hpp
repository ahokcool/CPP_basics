/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 22:28:31 by astein            #+#    #+#             */
/*   Updated: 2024/04/02 14:58:09 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

/* NOTE:
	Check the NOTE in the Character.hpp file regarding the use of
	the keyword 'virtual' in the member functions of this class.
*/

class Ice : public AMateria
{
	public:
		// Constructors and destructor
		Ice();
		Ice(const Ice &other);
		virtual ~Ice();

		// Operator overloads
		Ice 				&operator=(const Ice &other);
		
		// Member functions
		virtual AMateria	*clone() const;
		virtual void		use(const ICharacter &target);
};

#endif
