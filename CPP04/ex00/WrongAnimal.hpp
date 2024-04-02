/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 23:48:53 by astein            #+#    #+#             */
/*   Updated: 2024/04/02 12:34:23 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal
{
	public:
		// Constructors and destructor
		WrongAnimal();
		WrongAnimal(const std::string &type);
		WrongAnimal(const WrongAnimal &other);
		~WrongAnimal();
		// THIS DESTRUCTOR SHOULD BE VIRTUAL BUT IT IS NOT
		// TO DEMONSTRATE THE IMPORTANCE OF HAVING A VIRTUAL DESTRUCTOR
		// -> SEE main.cpp (therefore this leads to a memory leak)
		
		// Operator overloads
		WrongAnimal		&operator=(const WrongAnimal &other);

		// Member functions
		std::string 	getType() const;
		void 			makeSound() const;

	protected:
		std::string 	_type;
};

#endif
