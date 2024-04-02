/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 23:50:14 by astein            #+#    #+#             */
/*   Updated: 2024/04/02 12:47:35 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		// Constructors and destructor
		WrongCat();
		WrongCat(const WrongCat &other);
		~WrongCat();

		// Operator overloads
		WrongCat 		&operator=(const WrongCat &other);
		
		// Member functions override
		void 			makeSound() const;
		
	private:
		// Member Atributes
		// since the destructor of the parent class is not virtual,
		// the destructor of the child class will not be called
		// and the memory allocated for the child class will not be freed!
};

#endif
