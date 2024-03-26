/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 18:06:44 by astein            #+#    #+#             */
/*   Updated: 2024/03/26 18:19:42 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{

	public:
		Animal();
		Animal(const Animal &other);
		Animal &operator=(const Animal &other);
		~Animal();

		// Member functions
		virtual void makeSound() const;

	private:

	protected:
		std::string _type;

};

#endif