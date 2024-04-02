/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 22:28:29 by astein            #+#    #+#             */
/*   Updated: 2024/04/02 14:58:30 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

/* NOTE:
	Check the NOTE in the Character.hpp file regarding the use of
	the keyword 'virtual' in the member functions of this class.
*/

class Cure : public AMateria
{
	public:
		// Constructors and destructor
		Cure();
		Cure(const Cure &other);
		virtual ~Cure();

		// Operator overloads
		Cure 				&operator=(const Cure &other);

		// Member functions
		virtual AMateria	*clone() const;
		virtual void		use(const ICharacter &target);
};

#endif
