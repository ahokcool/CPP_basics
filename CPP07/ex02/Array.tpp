/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 18:52:32 by astein            #+#    #+#             */
/*   Updated: 2024/04/21 14:28:49 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
#define ARRAY_TPP

// Default Contructor
template<class T>
Array<T>::Array() : _size(0), _arr(NULL)
{
	// Nothing to do here
}

// Parameterized Constructor
template<class T>
Array<T>::Array(const unsigned int n) : _size(n), _arr(new T[n])
{
	// Primitive Types like int and float won't be initialized to zero
	// by default -  therefore we can call the default constructor, which
	// will also work for instances of classes...
	for (unsigned int i = 0; i < n; i++)
        _arr[i] = T();
}

// Copy Constructor
template<class T>
Array<T>::Array(const Array<T> &other) : _size(other._size), _arr(NULL)
{
	if (other._arr)
    {
        _arr = new T[_size];
        for (size_t i = 0; i < _size; i++)
            _arr[i] = other._arr[i];
    }
}

// Destructor
template<class T>
Array<T>::~Array()
{
	delete [] _arr;
}

// Overload the = operator
template<class T>
Array<T>		&Array<T>::operator=(const Array<T> &other)
{
	if (this != &other)
	{
		if (_arr)
		{
			// Delete old array if present...
			delete [] _arr;
			_arr = NULL;
		}
		
		_size = other._size;
		if (other._arr)
		{
			_arr = new T[_size];
			for (size_t i = 0; i < _size; i++)
				_arr[i] = other._arr[i];
		}
	}
	return *this;
}

// Overload the [] operator
template<class T>
T				&Array<T>::operator[](const size_t i) throw(std::exception)
{
	if (i >= _size)
		throw std::out_of_range("index is out of array range!");
	return _arr[i];
}

// Overload the [] operator CONST
template<class T>
const T			&Array<T>::operator[](const size_t i) const throw(std::exception)
{
	if (i >= _size)
		throw std::out_of_range("index is out of array range!");
	return _arr[i];
}

// Return the size of the array
template<class T>
unsigned int Array<T>::size() const
{
	return _size;
}

#endif