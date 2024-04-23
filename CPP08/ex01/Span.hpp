/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:30:36 by astein            #+#    #+#             */
/*   Updated: 2024/04/23 18:53:31 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <exception>
# include <set>

class Span
{
	public:
		Span(unsigned int N);
		~Span();

		// Member functions
		void	addNumber(const int i)	throw (std::exception);
		int 	shortestSpan()			throw (std::exception);
		int 	longestSpan() 			throw (std::exception);

	private:
		Span();
		Span(const Span &other);
		Span &operator=(const Span &other);
		
		unsigned int	_n;
		unsigned int	_N;
		int				_shortestSpan;
		std::set<int> 	_s;
};

#endif
