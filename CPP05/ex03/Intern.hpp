/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 20:36:58 by astein            #+#    #+#             */
/*   Updated: 2024/04/13 21:33:52 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
	public:
		// Constructors and destructor
		Intern();
		Intern(const Intern &other);
		~Intern();

		// Operator overloads
		Intern		&operator=(const Intern &other);
		
		// Member functions
		AForm		*makeForm(const std::string &formName, const std::string &target) const;

	private:
		AForm		*createS(std::string target) const;
		AForm		*createR(std::string target) const;
		AForm		*createP(std::string target) const;
};

#endif