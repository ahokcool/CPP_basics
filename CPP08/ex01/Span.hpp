/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:30:36 by astein            #+#    #+#             */
/*   Updated: 2024/04/27 16:29:51 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <exception>
# include <vector>
# include <algorithm>

class Span
{
	public:
		Span(unsigned int N);
		Span(const Span &other);
		~Span();

		// Member functions
		void				addNumber(const int i)	throw (std::overflow_error);
		unsigned int 		shortestSpan()			throw (std::invalid_argument);
		unsigned int 		longestSpan() 			throw (std::invalid_argument);
		void				print() const;
		void				addRange(const std::vector<int>::const_iterator &begin, const std::vector<int>::const_iterator &end) throw (std::overflow_error);

	private:
		Span();
		Span 				&operator=(const Span &other);
		
		const unsigned int	_N;
		std::vector<int> 	_v;
};

#endif
