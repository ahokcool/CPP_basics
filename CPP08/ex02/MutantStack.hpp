/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 15:09:30 by astein            #+#    #+#             */
/*   Updated: 2024/04/27 15:57:57 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
	    // Constructors and Destructor
	    MutantStack();
	    MutantStack(const MutantStack &other);
	    ~MutantStack();
	
	    // Operators
	    MutantStack 			&operator=(const MutantStack &other);
	
	    // Iterators
	    typedef typename std::stack<T>::container_type::iterator 				iterator;
	    typedef typename std::stack<T>::container_type::reverse_iterator 		reverse_iterator;
	    typedef typename std::stack<T>::container_type::const_iterator 			const_iterator;
	    typedef typename std::stack<T>::container_type::const_reverse_iterator	const_reverse_iterator;

		// NOTE:
		// I know that there are more iterators like random_access_iterator, etc.
		// But since the implementation of those is not hard just time consuming
		// I will leave it for another time since the main goal of this exercise
		// is to understand the basics of iterators and how to implement them.
	
	    // Iterator methods declaration
	    iterator 				begin();
	    iterator 				end();
	    reverse_iterator 		rbegin();
	    reverse_iterator 		rend();
	    const_iterator 			begin()		const;
	    const_iterator 			end()		const;
	    const_reverse_iterator	rbegin()	const;
	    const_reverse_iterator	rend()		const;
};

#include "MutantStack.tpp"

#endif
