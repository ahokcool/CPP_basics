/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 22:23:01 by astein            #+#    #+#             */
/*   Updated: 2024/03/29 01:07:22 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include "ICharacter.hpp"

class AMateria
{
	public:
		AMateria(const std::string &type);
		AMateria(const AMateria &other);
		AMateria &operator=(const AMateria &other);
		virtual ~AMateria();
		
		const std::string	&getType() const;
		virtual AMateria 	*clone() const = 0;
		virtual void 		use(ICharacter &target);

protected:
		std::string	_type;

private:
		AMateria(); //Default constructor should not be used
};

#endif