/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 18:06:44 by astein            #+#    #+#             */
/*   Updated: 2024/04/02 12:42:07 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
	public:
		// Constructors and destructor
		Animal();
		Animal(const std::string &type);
		Animal(const Animal &other);
		virtual ~Animal();

		// Operator overloads
		Animal 			&operator=(const Animal &other);

		// Member functions
		std::string 	getType() const;
		void 			setType(const std::string &type);
		virtual void 	makeSound() const;

	protected:
		std::string 	_type;
};

#endif
