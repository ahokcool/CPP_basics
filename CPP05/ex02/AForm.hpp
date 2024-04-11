/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 18:56:38 by astein            #+#    #+#             */
/*   Updated: 2024/04/11 13:35:41 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"
# include <iomanip> 

class AForm
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
			    GradeTooLowException(const std::string& msg = "") 	throw();
				virtual const char	*what() const 					throw();
				virtual 			~GradeTooLowException() 		throw();
			
			private:
				std::string			_msg;
		};

		class FormNotSignedException : public std::exception
		{
			public:
			    FormNotSignedException(const std::string& msg = "")	throw();
				virtual const char	*what() const 					throw();
				virtual 			~FormNotSignedException() 		throw();
			
			private:
				std::string			_msg;
		};
		
		// Constructors and destructor
		AForm(const std::string &name, unsigned int gradeToSign, unsigned int gradeToExecute)
			throw(Bureaucrat::GradeTooHighException, Bureaucrat::GradeTooLowException);
		AForm(const std::string &name, unsigned int gradeToSign, unsigned int gradeToExecute, const std::string &target)
			throw(Bureaucrat::GradeTooHighException, Bureaucrat::GradeTooLowException);
		AForm(const AForm &other);
		~AForm();

		// Operator overloads
		AForm					&operator=(const AForm &other);

		// Getters
		const std::string		&getName() const;
		unsigned int			getGradeToSign() const;
		unsigned int			getGradeToExecute() const;
		bool					getSigned() const;

		// Member functions
		virtual std::ostream	&print(std::ostream& os) const;
		// To be able to reuse the print function in the derived classes
		// I created this virtual function which is called by the insertion
		// operator overload. This way I can reuse the print function :)
		
		void					beSigned(const Bureaucrat &bureaucrat)
			throw(AForm::GradeTooLowException);
		bool					isExecutable(const Bureaucrat &bureaucrat) const
			throw (AForm::GradeTooLowException, AForm::FormNotSignedException);
		
		// Pure virtual function
		virtual void			execute(Bureaucrat const &executor) const
			throw (std::exception) = 0;
		// Since the different derived classes have different execute functions,
		// and therefore throw different exceptions, I am not specific about the
		// exceptions that can be thrown by this function in this abstract class.
		// The exceptions are specified in the derived classes.
		
	private:
		// Private default constructor, should not be used
		AForm();

		// Member attributes
		const std::string		_name;
		const unsigned int		_gradeToSign;
		const unsigned int		_gradeToExecute;
		bool					_signed;

	// Since all three derived classes have the same attributes, I made the
	// decision to have this attribute as protected in the base class.
	// Since it has to be set in the constructor of the derived classes, I made
	// the decision to have it const in the base class.
	// Therefore I added a new constructor to the base class which also takes
	// the target as a parameter and initializes the attribute.
	protected:
		const std::string		_target;
};

// Insertion operator overload
std::ostream	&operator<<(std::ostream &os, const AForm &theForm);

# endif