/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 18:06:44 by astein            #+#    #+#             */
/*   Updated: 2024/04/02 13:29:20 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include "Brain.hpp"

// Colors
# define CLR_RED 	"\033[1;31m"
# define CLR_BLUE 	"\033[1;34m"
# define CLR_CYAN 	"\033[1;36m"
# define CLR_PINK 	"\033[1;35m"
# define CLR_RESET 	"\033[0m"

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
		
		// Brain related functions
		void 			setIdea(const int index, const std::string &idea);

	protected:
		std::string		_type;
		Brain			*_brain;	
};

#endif
