/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 15:10:29 by astein            #+#    #+#             */
/*   Updated: 2024/04/02 13:13:56 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <iomanip>

class Brain
{
	public:
		// Constructors and destructor
		Brain();
		Brain(const Brain &other);
		~Brain();

		// Operator overloads
		Brain &operator=(const Brain &other);

		// Member functions
		std::string	getIdea(const int i) const;
		void		setIdea(const int i, const std::string &idea);
		void		print_ideas() const;

	private:
		std::string _ideas[100];
};

#endif
