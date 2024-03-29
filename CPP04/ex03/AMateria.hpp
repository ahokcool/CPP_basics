/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 22:23:01 by astein            #+#    #+#             */
/*   Updated: 2024/03/29 01:50:31 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>

// Do not include ICharacter.hpp here, because of circular dependency
// # include "ICharacter.hpp"
// Instead use forward declaration:
class ICharacter;

class AMateria
{
	public:
		AMateria(const std::string &type);
		AMateria(const AMateria &other);
		AMateria &operator=(const AMateria &other);
		virtual ~AMateria();
		
		// Member functions
		const std::string	&getType() const;
		virtual AMateria 	*clone() const = 0;
		virtual void 		use(ICharacter &target);

protected:
		std::string	_type;

private:
		AMateria(); //Default constructor should not be used
};

#endif