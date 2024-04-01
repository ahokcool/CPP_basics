/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 18:06:44 by astein            #+#    #+#             */
/*   Updated: 2024/04/01 22:40:45 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include "Brain.hpp"

class Animal
{
	public:
		// Constructors and destructor
		Animal();
		Animal(std::string type);
		Animal(const Animal &other);
		virtual ~Animal();

		// Operator overloads
		Anima// // Brain functions
// void		Animal::setIdea(int i, std::string idea)
// {
// 	std::cout << "Setting idea " << i << " to " << idea << std::endl;
// 	this->_brain->setIdea(i, idea);
// }

// std::string	Animal::getIdea(int i) const
// {
// 	return this->_brain->getIdea(i);
// }

// void		Animal::print_ideas() const
// {
// 	this->_brain->print_ideas();
// }
l &operator=(const Animal &other);

		// Member functions
		std::string		getType() const;
		void 			setType(std::string type);
		virtual void 	makeSound() const;

	protected:
		std::string		_type;
		Brain			*_brain;	
};

#endif
