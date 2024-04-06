/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 18:56:38 by astein            #+#    #+#             */
/*   Updated: 2024/04/06 00:13:24 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Form
{
	public:
		// Constructors and destructor
		Form(const std::string &name, unsigned int gradeToSign, unsigned int gradeToExecute)
			throw(GradeTooHighException, GradeTooLowException);
		Form(const Form &other);
		~Form();

		// Operator overloads
		Form					&operator=(const Form &other);

		// Getters
		const std::string		&getName() const;
		unsigned int			getGradeToSign() const;
		unsigned int			getGradeToExecute() const;
		bool					getSigned() const;
		
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