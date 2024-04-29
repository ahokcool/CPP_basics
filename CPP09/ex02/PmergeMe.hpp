/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 18:25:59 by astein            #+#    #+#             */
/*   Updated: 2024/04/30 00:25:25 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGE_ME_HPP
# define PMERGE_ME_HPP

# include <iostream>
# include <cstdlib>
# include <ctime>
# include <climits>
# include <vector>
# include <list>
# include <algorithm>
# include <exception>


class PmergeMe
{
	// This is the abstract base class for the Merge Insertion Sort
	// -------------------------------------------------------------------------
	class Mis
	{
		public:
			Mis();
			virtual ~Mis();

			// Pure virtual functions
			virtual void				sort() = 0;
			virtual std::string			getSorted() const = 0;

		protected:
			Mis(const Mis &other);
			
			// Member functions
			// binary insert for list
			// binary insert for vector

			// Attributes
			double						_ts_start;
			double						_ts_end;
		
		private:
			Mis							&operator=(const Mis &other);
	};

	// This is the derived class for the Merge Insertion Sort using a vector
	// -------------------------------------------------------------------------
	class MisVector : public Mis
	{
		public:
			MisVector();
			~MisVector();
		
			// override
			void		sort();
			std::string	getSorted() const;
			
		private:
			MisVector(const MisVector &other);
			MisVector	&operator=(const MisVector &other);
	};

	// This is the derived class for the Merge Insertion Sort using a list
	// -------------------------------------------------------------------------
	class MisList : public Mis
	{
		public:
			MisList();
			~MisList();

			// override
			void		sort();
			std::string	getSorted() const;

		private:
			MisList(const MisList &other);
			MisList	&operator=(const MisList &other);
	};

	// This is the main class for the Merge Insertion Sort aka "PmergeMe"
	// -------------------------------------------------------------------------
	public:
		PmergeMe(const char **argv) throw (std::exception);
		~PmergeMe();
		
		// This starts the process
		void		run();
	
	private:
		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe	&operator=(const PmergeMe &other);


		// Member functions
		bool		parseInput(const char **argv) throw (std::exception);
		void		populateJacob();
		void		printResult() const;

		// Attributes
		std::vector<unsigned int>							_jacobsthal;
		std::vector<unsigned int>							_unsorted;
		std::vector<unsigned int> 							_v;
        std::vector<std::pair<unsigned int,unsigned int> >	_pv;
		long												_timeVector;
		long												_timeDeque;

		// Template functions
		template<typename T>
		void		populateContainer(T &container)
		{
			for (std::vector<unsigned int>::iterator it = _unsorted.begin(); it != _unsorted.end(); it++)
				container.push_back(*it);
		}

		// Recursive function to sort all the pairs by the lager element of the pair
		template<typename P>
		void		sortPairs(P &p, size_t i)
		{
			if (i == p.size())
				return ;
			for (size_t j = i + 1; j < p.size(); j++)
			{
				if (p[i].second > p[j].second)
				{
					std::pair<unsigned int, unsigned int> tmp = p[i];
					p[i] = p[j];
					p[j] = tmp;
				}
			}
			sortPairs(p, i + 1);
		}
			
		template<typename P>
		void		printPairs(P &p)
		{
			std::cout << "\nPairs:\n";
			for (typename P::iterator it = p.begin(); it != p.end(); it++)
				std::cout << "(" << it->first << "\t| " << it->second << ") " << std::endl;
		}
		
		template<typename C>
		void		printContainer(C &c)
		{
			std::cout << "\nContainer:\n";
			for (typename C::iterator it = c.begin(); it != c.end(); it++)
				std::cout << *it << " ";
			std::cout << std::endl;
		}

		// Recursive function to insert
		template<typename C>
		void		binarySearchInsert(C &c, size_t low, size_t high, unsigned int value)
		{
			// Find mid value
			size_t mid = low + (high - low) / 2;
			if (low == high)
			{
				c.insert(c.begin() + mid, value);
				return ;
			}
			if (value < c[mid])
				binarySearchInsert(c, low, mid, value);
			else
				binarySearchInsert(c, mid + 1, high, value);
		}

		template<typename C>
		size_t findIndex(C &c, unsigned int value)
		{
			size_t i = 0;
			for (typename C::iterator it = c.begin(); it != c.end(); it++)
			{
				if (*it == value)
					return i;
				i++;
			}
			// If not found return the last index
			return i;
		}

		template<typename C, typename P>
		void		startBinarySearchInsert(C &c, P &p, size_t k)
		{
			unsigned int value = p[k].first;
			size_t low = 0;
			size_t high = findIndex(c, value);
			binarySearchInsert(c, low, high, value);
		}

		template<typename C, typename P>
		void		sortContainer(C &c, P &p, long *time)
		{
			long ts_start = clock();
			
			// Group by pairs
			unsigned int a = 0;
			unsigned int b = 0;
			long		 leftover = -1;
			for (typename C::iterator it = c.begin(); it != c.end(); it++)
			{
				a = *it;
				it++;
				if (it == c.end())
				{
					leftover = a;
					break;
				}
				b = *it;
				p.push_back(std::make_pair(a, b));
			}

			// Print the pairs
			printPairs(p);
				
			// Sort the pairs in place
			for (typename P::iterator it = p.begin(); it != p.end(); it++)
			{
				if (it->first > it->second)
				{
					unsigned int tmp = it->first;
					it->first = it->second;
					it->second = tmp;
				}
			}

			// Print the pairs
			printPairs(p);

			// Sort all the pairs by the lager element of the pair
			sortPairs(p, 0);

			// add the leftover
			if (leftover != -1)
				p.push_back(std::make_pair(leftover, 0));

			// Print the pairs
			printPairs(p);

			// Add the lowest pair member to the container
			c.clear();
			c.push_back(p.begin()->first);
			
			// Add the bigger (second) values of the pairs to the container
			for (typename P::iterator it = p.begin(); it != p.end(); it++)
				c.push_back(it->second);

			// Print the container
			printContainer(c);

			// insert the paried values in the container
			bool 	done	 = false;
			size_t 	jIndex	 = 1;
			size_t 	jPrev	 = _jacobsthal[jIndex - 1];
			size_t 	k;
			while (!done)
			{
				std::cout << "Next Jacobsthal number: " << _jacobsthal[jIndex] << "\n";
				// Insert the next paired number following the
				// Jaconsthal numberindex
				k = _jacobsthal[jIndex];
				if (k >= p.size()-1)
				{
					k = p.size() - 1;
					done = true;
				}
				// Insert backwards down to the previous Jacobsthal number
				while (k > jPrev)
				{
					startBinarySearchInsert(c, p, k);
					printContainer(c);
					k--;
				}

				// Increment the Jacobsthal index
				jPrev = _jacobsthal[jIndex];
				jIndex++;
			}

			*time = clock() - ts_start;
		}

		// MisVector					_misVector;
		// MisList						_misList;
};

#endif