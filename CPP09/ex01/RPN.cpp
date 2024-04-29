/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:42:34 by astein            #+#    #+#             */
/*   Updated: 2024/04/29 18:15:31 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

// Helper Functions in this file
std::string	toString(int i);
bool		calculate(std::stack<int> &stack, char c);
std::string deliverResult(std::stack<int> &stack);
std::string deliverResult();


// Private Construtor and Destructor
RPN::RPN() {}
RPN::RPN(const RPN &other) { (void)other; }
RPN::~RPN() {}

// Private overload
RPN		&RPN::operator=(const RPN &other)
{
	(void)other;
	return (*this);
}

// Member functions
std::string		RPN::rpn(const std::string &str)
{
	std::stack<int> stack;	

	for (std::string::const_iterator it = str.begin(); it != str.end(); ++it)
	{
		char c = *it;
		switch (c)
		{
			case '+': case '-': case '*': case '/':
				// Operators will pop the last two numbers from the stack,
				// apply the operation and push the result back to the stack
				if (!calculate(stack, c))
					return (deliverResult());
				break;

			default:
				if (std::isspace(c))
					// Whitespaces will be ignored
					continue;
				else if (std::isdigit(c))
					// Digits will be pushed to the stack
					stack.push(c - '0');
				else
					// Everything else will end in an error
					return (deliverResult());
		}
	}
	return deliverResult(stack);
}

// Helper Functions
// -----------------------------------------------------------------------------
std::string	toString(int i)
{
	std::string str;
	std::stringstream ss;
	ss << i;
	ss >> str;
	return (str);
}

// Operators will pop the last two numbers from the stack,
// apply the operation and push the result back to the stack
bool		calculate(std::stack<int> &stack, char c)
{
	int op1;
	int op2;

	if (stack.size() < 2)
		return (false);
	op2 = stack.top();
	stack.pop();
	op1 = stack.top();
	stack.pop();
	if (c == '+')
		stack.push(op1 + op2);
	else if (c == '-')
		stack.push(op1 - op2);
	else if (c == '*')
		stack.push(op1 * op2);
	else if (c == '/')
	{
		if (op2 == 0)
			return (false);
		stack.push(op1 / op2);
	}
	return (true);
}

// This function will be used to deliver the result in the correct format
std::string deliverResult(std::stack<int> &stack)
{
	if(stack.size() == 1)
	{
		std::string result = toString(stack.top());
		stack.pop();
		std::cout << result << std::endl;
		return result;
	}
	else
		return deliverResult();
}

// This function overload will be used to deliver "Error"
std::string deliverResult()
{
	std::string result = "Error";
	std::cout << result << std::endl;
	return result;
}
