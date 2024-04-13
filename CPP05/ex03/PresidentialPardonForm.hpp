/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 20:20:01 by astein            #+#    #+#             */
/*   Updated: 2024/04/13 20:23:17 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	public:
		// Constructors and destructor
		PresidentialPardonForm(const std::string &target);
		PresidentialPardonForm(const PresidentialPardonForm &other);
		~PresidentialPardonForm();

		// Operator overloads
		PresidentialPardonForm	&operator=(const PresidentialPardonForm &other);

		// Base class pure virtual function override
		void					execute(Bureaucrat const &executor) const
			throw (AForm::GradeTooLowException, AForm::FormNotSignedException);

	private:
		PresidentialPardonForm();	// private, should not be used
};

// Insertion operator overload
std::ostream	&operator<<(std::ostream &os, const AForm &form);

# endif