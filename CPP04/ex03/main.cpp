/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:17:08 by astein            #+#    #+#             */
/*   Updated: 2024/04/02 18:16:35 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <cstdlib> // For std::atoi

void	test1();
void	test2();
void	test3();
void	test4();


int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << CLR_YELLOW << std::endl <<
			"---------------------------------------------" << std::endl <<
			" CPP 04 ex03" << std::endl <<
			"---------------------------------------------" << CLR_CYAN << std::endl <<
			" NOTE: run it with valgrind --leak-check=full" << std::endl <<
			"---------------------------------------------" << CLR_BLUE << std::endl <<
			" Usage: ./ex03 <test nr as string>" << std::endl << CLR_BLUE <<
			"---------------------------------------------" << CLR_YELLOW << std::endl <<
			" Avaliable tests:" << std::endl <<
			"---------------------------------------------" << CLR_RESET << std::endl <<
			" [1]:\tOCCF Character" << std::endl <<
			" [2]:\tOCCF Cure & Ice" << std::endl <<
			" [3]:\tOCCF MateriaSource" << std::endl <<
			" [4]:\tUse Case aka wtf!" << std::endl <<
			"---------------------------------------------" << CLR_RED << std::endl;
		return 0;
	}

	int testNumber = std::atoi(argv[1]);

	switch (testNumber)
    {
        case 1:
            test1();
            break;
        case 2:
            test2();
            break;
		case 3:
            test3();
            break;
		case 4:
			test4();
			break;
        default:
            std::cout << "Invalid test number!" << std::endl;
            break;
    }
	return 0;
}
