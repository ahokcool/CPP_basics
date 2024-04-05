/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 15:28:57 by astein            #+#    #+#             */
/*   Updated: 2024/04/05 19:20:59 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

# define CLR_RED "\033[31m"
# define CLR_GRN "\033[32m"
# define CLR_YLW "\033[33m"
# define CLR_BLU "\033[34m"
# define CLR_RST "\033[0m"

class Bureaucrat
{
	public:
		// Constructors and destructor
		Bureaucrat(const std::string &name, unsigned int grade)
									throw(Bureaucrat::GradeTooHighException, Bureaucrat::GradeTooLowException);
		Bureaucrat(const Bureaucrat &other);
		~Bureaucrat();

		// Operator overloads
		Bureaucrat 				&operator=(const Bureaucrat &other);
		Bureaucrat 				&operator++()
									throw(Bureaucrat::GradeTooHighException);
		Bureaucrat 				operator++(int)
									throw(Bureaucrat::GradeTooHighException);
		Bureaucrat 				&operator--()
									throw(Bureaucrat::GradeTooLowException);
		Bureaucrat 				operator--(int)
									throw(Bureaucrat::GradeTooLowException);
		// Getters
		const std::string 		&getName() const;
		unsigned int			getGrade() const;
		
	// EXCEPTIONS
	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char	*what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char	*what() const throw();
	};
	
	private:
		// Private default constructor, should not be used
		Bureaucrat();

		// Private member attributes
		const std::string 		_name;
		unsigned int			_grade;		
};

// Insertion operator overload
std::ostream 					&operator<<(std::ostream &out, const Bureaucrat &b);

#endif
