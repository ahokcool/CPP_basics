/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:37:59 by astein            #+#    #+#             */
/*   Updated: 2024/04/21 14:09:28 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>

class Data
{
	public:
		// Constructors & Destructors
		Data();
		Data(const std::string &name, int moreData);
		Data(const Data &other);
		~Data();

		// Equal assignment operator overload
		Data			&operator=(const Data &other);
		bool			operator<(const Data &other) const;
		bool			operator>(const Data &other) const;

		// Member functions
		void			printData() const;
		void			setName(const std::string &name);

	private:
		// Attributes
		std::string		_name;
		int				_moreData;
};

#endif