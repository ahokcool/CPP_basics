/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 23:48:53 by astein            #+#    #+#             */
/*   Updated: 2024/03/27 00:24:38 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal
{
	public:
		WrongAnimal();
		WrongAnimal(std::string type);
		WrongAnimal(const WrongAnimal &other);
		WrongAnimal &operator=(const WrongAnimal &other);
		~WrongAnimal();
		// THIS DESTRUCTOR SHOULD BE VIRTUAL BUT IT IS NOT
		// TO DEMONSTRATE THE IMPORTANCE OF HAVING A VIRTUAL DESTRUCTOR
		// -> SEE main.cpp (therefore this leads to a memory leak)

		// Member functions
		std::string getType() const;
		void makeSound() const;

	protected:
		std::string _type;
};

#endif
