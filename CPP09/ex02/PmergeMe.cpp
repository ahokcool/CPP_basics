/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 19:12:32 by astein            #+#    #+#             */
/*   Updated: 2024/04/30 00:55:46 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// Private Functions
PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe &other) { (void)other; }
PmergeMe	&PmergeMe::operator=(const PmergeMe &other) { (void)other; return (*this); }

// Parametric Constructor
PmergeMe::PmergeMe(const char **argv, bool p) throw (std::exception) : _timeVector(0), _timeDeque(0), _print(p)
{
	this->parseInput(argv);
}

// Destructor
PmergeMe::~PmergeMe(){}

// Member Functions
void		PmergeMe::run()
{
	// Print Array
	if (_print)
	{
		std::cout << "Unsorted Array:\t\t";
		for (std::vector<unsigned int>::iterator it = _unsorted.begin(); it != _unsorted.end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;
	}

	// Populate the Containers and calculate the jacobsthal sequence
	populateContainer(this->_v);
	populateContainer(this->_d);
	this->populateJacob();

	// Sort the Vector Container
	sortContainer(this->_v, this->_pv, &_timeVector);
	// Sort the List Container
	sortContainer(this->_d, this->_pd, &_timeDeque);

	// Print the Results
	this->printResult();
}

void		PmergeMe::parseInput(const char **argv) throw (std::exception)
{
	for (int i = 1; argv[i]; i++)
	{
		if (argv[i][0] == '-')
		{
			std::cout << "Error: found '-' sign..." << std::endl;
			throw std::exception();
		}
		
		// Check if argv[i] is an unsigned int (not too big!)
        char *end;
        unsigned long num = std::strtoul(argv[i], &end, 10);
        if (*end != 0 || num > UINT_MAX)
		{
            std::cout << "Error: Invalid number " << argv[i] << std::endl;
			throw std::exception();
        }

        // Check for duplicates in vector _unsorted
        if (std::find(_unsorted.begin(), _unsorted.end(), static_cast<unsigned int>(num)) != _unsorted.end())
		{
            std::cout << "Error: Duplicate number " << num << std::endl;
            throw std::exception();
        }

        // Add to vector _unsorted
        _unsorted.push_back(static_cast<unsigned int>(num));
	}
}

void		PmergeMe::populateJacob()
{
	// Populate the Jacobsthal Sequence
	_jacobsthal.push_back(0);
	_jacobsthal.push_back(1);
	_jacobsthal.push_back(3);
	for (unsigned int i = 3; i < _unsorted.size(); i++)
		_jacobsthal.push_back(_jacobsthal[i - 1] + 2 * _jacobsthal[i - 2]);
	// Print jacob
	if (_print)
	{
		std::cout << "Jacobsthal Sequence:\t";
		for (std::vector<unsigned int>::iterator it = _jacobsthal.begin(); it != _jacobsthal.end(); it++)
			std::cout << *it << " ";
	}
}

void		PmergeMe::printResult() const
{
	unsigned long n = _unsorted.size();

	std::cout << "Before:\t";
	for (std::vector<unsigned int>::const_iterator it = _unsorted.begin(); it != _unsorted.end(); it++)
		std::cout << *it << " ";
	std::cout << "\nAfter:\t";
	for (std::vector<unsigned int>::const_iterator it = _v.begin(); it != _v.end(); it++)
		std::cout << *it << " ";
	std::cout << "\nTime to process a range of " <<
	n <<
	"\telements with std::vector:\t" <<
	_timeVector <<
	"us" << std::endl;
	std::cout << "Time to process a range of " <<
	n <<
	"\telements with std::deque:\t" <<
	_timeDeque <<
	"us" << std::endl;
}
