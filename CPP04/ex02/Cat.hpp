/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 18:06:47 by astein            #+#    #+#             */
/*   Updated: 2024/04/02 13:46:56 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "AAnimal.hpp"

class Cat : public AAnimal
{
	public:
		// Constructors and destructor
		Cat();
		Cat(const Cat &other);
		~Cat();

		// Operator overloads
		Cat 	&operator=(const Cat &other);

		// Member functions override
		void	makeSound() const;
};

#endif
