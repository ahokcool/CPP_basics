/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 18:06:49 by astein            #+#    #+#             */
/*   Updated: 2024/04/02 13:47:42 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"

class Dog : public AAnimal
{
	public:
		// Constructors and destructor
		Dog();
		Dog(const Dog &other);
		~Dog();

		// Operator overloads
		Dog		&operator=(const Dog &other);

		// Member functions override
		void 	makeSound() const;
};

#endif
