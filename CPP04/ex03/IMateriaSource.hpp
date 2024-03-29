/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 22:45:48 by astein            #+#    #+#             */
/*   Updated: 2024/03/29 00:59:43 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

# include "AMateria.hpp"

class IMateriaSource
{
	public:
		// Destructor
		virtual ~IMateriaSource() {}

		// Pure virtual functions
		virtual void 		learnMateria(AMateria*) = 0;
		virtual AMateria	*createMateria(const std::string &type) = 0;
};

#endif
