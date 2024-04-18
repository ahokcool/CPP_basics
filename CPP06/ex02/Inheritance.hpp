/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Inheritance.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:57:21 by astein            #+#    #+#             */
/*   Updated: 2024/04/18 14:25:34 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INHERITANCE_HPP
# define INHERITANCE_HPP

# include <iostream>
#include <ctime>
#include <cstdlib>
#include <exception>

class Base
{
	public:
		Base();
		// One virtual function is enough to make the class polymorphic
		// This is because the vtable will be created for the class
		// and then we can use dynamic_cast to check the type of the object
		virtual ~Base();
};

class A : public Base {};
class B : public Base {};
class C : public Base {};
class D : public Base {};


// Test Functions
Base	*generate(void);
void	identify(Base *p);
void	identify(Base &r);


#endif
