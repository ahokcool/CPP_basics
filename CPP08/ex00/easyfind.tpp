/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:22:06 by astein            #+#    #+#             */
/*   Updated: 2024/04/23 16:49:21 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_TPP
# define EASYFIND_TPP

template<typename T>
int	easyfind(const T &container, const int i) throw(std::exception)
{
	typename T::const_iterator cit = std::find(container.begin(), container.end(), i);
	if (cit == container.end())
		throw std::exception();
		
	return *cit;	
}

#endif
