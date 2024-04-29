/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:41:33 by astein            #+#    #+#             */
/*   Updated: 2024/04/29 18:14:56 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <sstream>
# include <string>

class RPN
{
	public:
		// Member functions
		static std::string	rpn(const std::string &str);
	
	private:
		// Construtor and Destructor
		RPN();
		RPN(const RPN &other);
		~RPN();
		
		// Overload
		RPN 				&operator=(const RPN &other);
};

#endif