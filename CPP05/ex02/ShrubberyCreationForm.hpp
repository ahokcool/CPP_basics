/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 13:15:57 by astein            #+#    #+#             */
/*   Updated: 2024/04/14 23:37:07 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <fstream>

class ShrubberyCreationForm : public AForm
{
	public:
		// Constructors and destructor
		ShrubberyCreationForm(const std::string &target);
		ShrubberyCreationForm(const ShrubberyCreationForm &other);
		~ShrubberyCreationForm();

		// Operator overloads
		ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &other);

		// Base class pure virtual function override
		void					execute(const Bureaucrat &executor) const
			throw (AForm::GradeTooLowException, AForm::FormNotSignedException, std::runtime_error);

	private:
		ShrubberyCreationForm();	// private, should not be used
};

// Insertion operator overload
std::ostream	&operator<<(std::ostream &os, const AForm &form);

# endif