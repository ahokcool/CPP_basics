/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 22:45:34 by astein            #+#    #+#             */
/*   Updated: 2024/04/02 17:55:24 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "AMateria.hpp"
# include "IMateriaSource.hpp"

/* NOTE:
	Check the NOTE in the Character.hpp file regarding the use of
	the keyword 'virtual' in the member functions of this class.
*/

class MateriaSource : public IMateriaSource
{
	public:
		// Constructors and destructor
		MateriaSource();
		MateriaSource(const MateriaSource &other);
		virtual ~MateriaSource();

		// Operator overloads
		MateriaSource 		&operator=(const MateriaSource &other);

		// Member functions from IMateriaSource
		virtual void		learnMateria(AMateria*);
		virtual AMateria	*createMateria(const std::string &type);

	private:
		AMateria*			_materias[4];
};

#endif
