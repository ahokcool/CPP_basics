/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 13:15:57 by astein            #+#    #+#             */
/*   Updated: 2024/04/09 17:45:08 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	public:
		// Constructors and destructor
		ShrubberyCreationForm(const std::string &target);
		ShrubberyCreationForm(const ShrubberyCreationForm &other);
		~ShrubberyCreationForm();

		// Operator overloads
		ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &other);

		// Member functions
		void					createShrubbery() const;

		// Base class pure virtual function
		void					execute(Bureaucrat const &executor) const
			throw (AForm::GradeTooLowException, AForm::FormNotSignedException);

	private:
		ShrubberyCreationForm();	// private, should not be used
};

// Insertion operator overload
std::ostream	&operator<<(std::ostream &os, const AForm &form);

# endif