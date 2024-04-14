/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 15:28:57 by astein            #+#    #+#             */
/*   Updated: 2024/04/14 23:32:48 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>

class AForm;

# define CLR_RED "\033[31m"
# define CLR_GRN "\033[32m"
# define CLR_YLW "\033[33m"
# define CLR_BLU "\033[34m"
# define CLR_ORN "\033[38;5;202m"
# define CLR_BLD "\033[1m"
// I added these specific colors for Clerk, Form and Grade
# define CLR_CLERK "\033[1m\033[35m"
# define CLR_FORM "\033[1m\033[36m"
# define CLR_GRADE "\033[1m\033[93m"
# define CLR_TARGET "\033[1m\033[96m"
// RESET
# define CLR_RST "\033[0m"



class Bureaucrat
{
	public:
		// EXCEPTIONS
		// It looks shitty that they are at the top but it is the only way to
		// avoid the "incomplete type" error and still have them as inner classes
		// which is a requirement of the subject...
		class GradeTooHighException : public std::exception
		{
			public:
				// default value of msg is an empty string
			    GradeTooHighException(const std::string& msg = "") 	throw();
				virtual const char	*what() const 					throw();
				virtual 			~GradeTooHighException() 		throw();
		
			private:
				std::string			_msg;
		};
		
		class GradeTooLowException : public std::exception
		{
			public:
				// default value of msg is an empty string
				GradeTooLowException(const std::string &msg = "") 	throw();
				virtual const char	*what() const					throw();
				virtual				~GradeTooLowException() 		throw();
			
			private:
				std::string			_msg;
		};

		// Constructors and destructor
		Bureaucrat(const std::string &name, unsigned int grade)
			throw(Bureaucrat::GradeTooHighException, Bureaucrat::GradeTooLowException);
		Bureaucrat(const Bureaucrat &other);
		~Bureaucrat();

		// Operator overloads
		Bureaucrat	&operator=(const Bureaucrat &other);

		// Increment and decrement operators for grade
		Bureaucrat	&operator++()	throw(Bureaucrat::GradeTooHighException);
		Bureaucrat	operator++(int)	throw(Bureaucrat::GradeTooHighException);
		Bureaucrat	&operator--()	throw(Bureaucrat::GradeTooLowException);
		Bureaucrat	operator--(int)	throw(Bureaucrat::GradeTooLowException);
		
		// Getters
		const std::string 			&getName() const;
		unsigned int				getGrade() const;

		// Member functions
		void						signForm(AForm &form) const;
		void						executeForm(const AForm &form) const;
		
	private:
		// Private default constructor, should not be used
		Bureaucrat()				throw(Bureaucrat::GradeTooHighException);

		const std::string			_name;
		unsigned int				_grade;		
};

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &b);

#endif
