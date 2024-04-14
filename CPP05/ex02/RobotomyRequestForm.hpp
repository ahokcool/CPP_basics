/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 13:04:54 by astein            #+#    #+#             */
/*   Updated: 2024/04/14 23:37:02 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <stdlib.h>

class RobotomyRequestForm : public AForm
{
	public:
		// Constructors and destructor
		RobotomyRequestForm(const std::string &target);
		RobotomyRequestForm(const RobotomyRequestForm &other);
		~RobotomyRequestForm();

		// Operator overloads
		RobotomyRequestForm	&operator=(const RobotomyRequestForm &other);

		// Base class pure virtual function override
		void					execute(const Bureaucrat &executor) const
			throw (AForm::GradeTooLowException, AForm::FormNotSignedException);

	private:
		RobotomyRequestForm();	// private, should not be used
};

// Insertion operator overload
std::ostream	&operator<<(std::ostream &os, const AForm &form);

# endif