/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 19:12:32 by astein            #+#    #+#             */
/*   Updated: 2024/04/30 00:10:18 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// This is the abstract base class for the Merge Insertion Sort
// -----------------------------------------------------------------------------
PmergeMe::Mis::Mis() : _ts_start(0), _ts_end(0) {}
PmergeMe::Mis::~Mis() {}

// Private
PmergeMe::Mis		&PmergeMe::Mis::operator=(const Mis &other) { (void)other; return (*this); }

// Protected
PmergeMe::Mis::Mis(const Mis &other) { (void)other; }

// This is the derived class for the Merge Insertion Sort using a vector
// -----------------------------------------------------------------------------
PmergeMe::MisVector::MisVector() : Mis() {}
PmergeMe::MisVector::~MisVector() {}

// Private
PmergeMe::MisVector::MisVector(const MisVector &other) : PmergeMe::Mis(other) { (void)other; }
PmergeMe::MisVector	&PmergeMe::MisVector::operator=(const MisVector &other) { (void)other; return (*this); }

// Member Functions
void		PmergeMe::MisVector::sort()
{
	// std::sort
}

std::string	PmergeMe::MisVector::getSorted() const
{
	// return sorted vector
	return ("asd");
}

// This is the derived class for the Merge Insertion Sort using a list
// -----------------------------------------------------------------------------
PmergeMe::MisList::MisList() {}
PmergeMe::MisList::~MisList() {}

// Private
PmergeMe::MisList::MisList(const MisList &other) : PmergeMe::Mis(other) { (void)other; }
PmergeMe::MisList	&PmergeMe::MisList::operator=(const MisList &other) { (void)other; return (*this); }

// Member Functions
void		PmergeMe::MisList::sort()
{
	// std::sort
}

std::string	PmergeMe::MisList::getSorted() const
{
	// return sorted list
	return (std::string());
}

// This is the main class for the Merge Insertion Sort aka "PmergeMe"
// -----------------------------------------------------------------------------
// Private Functions
PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe &other) { (void)other; }
PmergeMe	&PmergeMe::operator=(const PmergeMe &other) { (void)other; return (*this); }

// Parametric Constructor
PmergeMe::PmergeMe(const char **argv) throw (std::exception)
{
	this->parseInput(argv);
}

// Destructor
PmergeMe::~PmergeMe(){}

// Member Functions
void		PmergeMe::run()
{
	// Populate the Containers and calculate the jacobsthal sequence
	populateContainer(this->_v);
	this->populateJacob();

	// Sort the Vector Container
	sortContainer(this->_v, this->_pv, &_timeVector);

	// Sort the List Container

	// Print the Results
	this->printResult();
}

bool		PmergeMe::parseInput(const char **argv) throw (std::exception)
{
	for (int i = 1; argv[i]; i++)
	{
		if (argv[i][0] == '-')
		{
			std::cout << "Error: found '-' sign..." << std::endl;
			return false;
		}
		
		// Check if argv[i] is an unsigned int (not too big!)
        char *end;
        unsigned long num = std::strtoul(argv[i], &end, 10);
        if (*end != 0 || num > UINT_MAX)
		{
            std::cout << "Error: Invalid number " << argv[i] << std::endl;
            return false;
        }

        // Check for duplicates in vector _unsorted
        if (std::find(_unsorted.begin(), _unsorted.end(), static_cast<unsigned int>(num)) != _unsorted.end())
		{
            std::cout << "Error: Duplicate number " << num << std::endl;
            return false;
        }

        // Add to vector _unsorted
        _unsorted.push_back(static_cast<unsigned int>(num));
	}
	return (true);
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
	std::cout << "Jacobsthal Sequence:\t";
	for (std::vector<unsigned int>::iterator it = _jacobsthal.begin(); it != _jacobsthal.end(); it++)
		std::cout << *it << " ";
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
	"\telements with std::list:\t" <<
	_timeDeque <<
	"us" << std::endl;
}
