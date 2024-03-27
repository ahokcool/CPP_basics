/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 18:06:44 by astein            #+#    #+#             */
/*   Updated: 2024/03/27 19:07:37 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AAANIMAL_HPP
# define AAANIMAL_HPP

# include <iostream>
# include "Brain.hpp"

class AAnimal
{
	public:
		AAnimal();
		AAnimal(std::string type);
		AAnimal(const AAnimal &other);
		AAnimal &operator=(const AAnimal &other);
		virtual ~AAnimal();

		// Member functions
		std::string getType() const;
		void setType(std::string type);
		virtual void makeSound() const = 0;

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
