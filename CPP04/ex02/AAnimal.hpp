/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 18:06:44 by astein            #+#    #+#             */
/*   Updated: 2024/04/02 13:49:28 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AAANIMAL_HPP
# define AAANIMAL_HPP

# include <iostream>
# include "Brain.hpp"

// Colors
# define CLR_RED 	"\033[1;31m"
# define CLR_BLUE 	"\033[1;34m"
# define CLR_CYAN 	"\033[1;36m"
# define CLR_PINK 	"\033[1;35m"
# define CLR_RESET 	"\033[0m"

class AAnimal
{
	public:
		// Constructors and destructor
		AAnimal();
		AAnimal(const std::string &type);
		AAnimal(const AAnimal &other);
		virtual ~AAnimal();

		// Operator overloads
		AAnimal 		&operator=(const AAnimal &other);
		
		// Member functions
		std::string 	getType() const;
		void 			setType(const std::string &type);
		virtual void 	makeSound() const = 0;
		// This a pure virtual function, so the class is abstract

		// Brain related functions
		void 			setIdea(const int index, const std::string &idea);

	protected:
		std::string		_type;
		Brain			*_brain;
};

#endif
