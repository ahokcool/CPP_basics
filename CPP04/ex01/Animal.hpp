/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 18:06:44 by astein            #+#    #+#             */
/*   Updated: 2024/03/27 15:36:21 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include "Brain.hpp"

class Animal
{
	public:
		Animal();
		Animal(std::string type);
		Animal(const Animal &other);
		Animal &operator=(const Animal &other);
		virtual ~Animal();

		// Member functions
		std::string getType() const;
		void setType(std::string type);
		virtual void makeSound() const;

		// Brain functions
		void		setIdea(int i, std::string idea);
		std::string	getIdea(int i) const;
		void		print_ideas() const;

	protected:
		std::string	_type;

	private:
		Brain* _brain;	
};

#endif
