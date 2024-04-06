/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 15:28:57 by astein            #+#    #+#             */
/*   Updated: 2024/04/06 01:14:18 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>

# define CLR_RED "\033[31m"
# define CLR_GRN "\033[32m"
# define CLR_YLW "\033[33m"
# define CLR_BLU "\033[34m"
# define CLR_ORN "\033[38;5;202m"
# define CLR_BLD "\033[1m"
# define CLR_RST "\033[0m"


// EXCEPTIONS
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
		~GradeTooLowException() 							throw();
	
	private:
		std::string			_msg;
};

class Bureaucrat
{
	public:
		// Constructors and destructor
		Bureaucrat(const std::string &name, unsigned int grade)
			throw(GradeTooHighException, GradeTooLowException);
			
		Bureaucrat(const Bureaucrat &other);
		~Bureaucrat();

		// Operator overloads
		Bureaucrat	&operator=(const Bureaucrat &other);

		// Increment and decrement operators for grade
		Bureaucrat	&operator++()	throw(GradeTooHighException);
		Bureaucrat	operator++(int)	throw(GradeTooHighException);
		Bureaucrat	&operator--()	throw(GradeTooLowException);
		Bureaucrat	operator--(int)	throw(GradeTooLowException);
		
		// Getters
		const std::string 			&getName() const;
		unsigned int				getGrade() const;
		
	private:
		// Private default constructor, should not be used
		Bureaucrat()				throw(GradeTooHighException);

		const std::string			_name;
		unsigned int				_grade;		
};

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &b);

#endif
