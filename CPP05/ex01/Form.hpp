/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 18:56:38 by astein            #+#    #+#             */
/*   Updated: 2024/04/06 03:15:51 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"
# include <iomanip> 

class Form
{
	public:
		// EXCEPTIONS
		// It looks shitty that it is at the top but it is the only way to
		// avoid the "incomplete type" error and still have it as inner class
		// which is a requirement of the subject...
		// Also it would be nice to be allowed to use the same exceptions as in
		// Bureaucrat.hpp but the subject requires to have them as inner classes
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char	*what() const 					throw();
		};

		// Constructors and destructor
		Form(const std::string &name, unsigned int gradeToSign, unsigned int gradeToExecute)
			throw(Bureaucrat::GradeTooHighException, Bureaucrat::GradeTooLowException);
		Form(const Form &other);
		~Form();

		// Operator overloads
		Form					&operator=(const Form &other);

		// Getters
		const std::string		&getName() const;
		unsigned int			getGradeToSign() const;
		unsigned int			getGradeToExecute() const;
		bool					getSigned() const;

		// Member functions
		void					beSigned(const Bureaucrat &bureaucrat)
			throw(Form::GradeTooLowException);
		
	private:
		// Private default constructor, should not be used
		Form();

		// Member attributes
		const std::string		_name;
		const unsigned int		_gradeToSign;
		const unsigned int		_gradeToExecute;
		bool					_signed;
};

// Insertion operator overload
std::ostream	&operator<<(std::ostream &os, const Form &form);

# endif