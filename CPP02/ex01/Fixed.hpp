/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 21:22:36 by astein            #+#    #+#             */
/*   Updated: 2024/03/13 16:41:13 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{

	public:
		Fixed();
		Fixed(const Fixed &other);
		Fixed(const int value);
		Fixed(const float value);
		Fixed &operator=(const Fixed &other);
		~Fixed();

		int						getRawBits() const;
		void					setRawBits(const int raw);
		float					toFloat() const;
		int						toInt() const;
		
	private:
		int					_value;
		static const int	_fractionalBits;

};

	std::ostream 	&operator<<(std::ostream &os, const Fixed &fixed);
#endif