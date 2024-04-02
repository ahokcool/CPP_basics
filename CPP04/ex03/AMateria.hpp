/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 22:23:01 by astein            #+#    #+#             */
/*   Updated: 2024/04/02 14:13:39 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include "colors.hpp"

// Do not include ICharacter.hpp here, because of circular dependency
// # include "ICharacter.hpp"
// Instead use forward declaration:
class ICharacter;

class AMateria
{
	public:
		// Constructors and destructor
		AMateria(const std::string &type);
		AMateria(const AMateria &other);
		virtual ~AMateria();
		
		// Operator overloads
		AMateria 			&operator=(const AMateria &other);

		// Member functions
		const std::string	&getType() const;
		virtual AMateria 	*clone() const = 0;
		virtual void 		use(const ICharacter &target);
		// Not sure why I couldn't make 'use' pure virtual

protected:
		std::string	_type;

private:
		AMateria(); //Default constructor should not be used
};

#endif