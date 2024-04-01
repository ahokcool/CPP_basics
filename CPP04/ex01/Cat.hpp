/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 18:06:47 by astein            #+#    #+#             */
/*   Updated: 2024/04/01 22:41:45 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal
{
	public:
		// Constructors and destructor
		Cat();
		Cat(const Cat &other);
		~Cat();

		// Operator overloads
		Cat 			&operator=(const Cat &other);
		
		// Member functions override
		virtual void 	makeSound() const;	
};

#endif
