/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 17:58:27 by astein            #+#    #+#             */
/*   Updated: 2024/03/09 17:59:06 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP
# include <iostream>

class Harl
{
	private:
		void _debug() const;
		void _info() const;
		void _warning() const;
		void _error() const;
		
	public:
		Harl();
		~Harl();

		void	complain(const std::string level) const;
		void	complain_filter(const std::string level) const;
};

#endif