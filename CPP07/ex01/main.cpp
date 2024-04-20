/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 15:13:38 by astein            #+#    #+#             */
/*   Updated: 2024/04/20 16:04:07 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.tpp"

int	main()
{
	std::cout << std::endl << "Test with integer array:" << std::endl;
	int ia[] = {1,2,4,6,8};
	size_t len = sizeof(ia) / sizeof(ia[0]);
	::iter(ia, len, ::put);	
	::iter(ia, len, ::add42);	
	std::cout << std::endl << "Added 42 to each element:" << std::endl;
	::iter(ia, len, ::put);	

	

	std::cout << std::endl << "Test with string array:" << std::endl;
	std::string sa[] = {"Hello", "World!", "Hello", "42"};
	len = sizeof(sa) / sizeof(sa[0]);
	::iter(sa, len, ::put);	
	::iter(sa, len, ::add42);	
	std::cout << std::endl << "Added 42 to each element:" << std::endl;
	::iter(sa, len, ::put);	


	std::cout << std::endl << "Test with float array:" << std::endl;
	float fa[] = {0.42f, 0.0001f, 42.42f};
	len = sizeof(fa) / sizeof(fa[0]);
	::iter(fa, len, ::put);
 	::iter(fa, len, ::add42);	
	std::cout << std::endl << "Added 42 to each element:" << std::endl;
	::iter(fa, len, ::put);


	return 0;
}