/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 15:10:30 by astein            #+#    #+#             */
/*   Updated: 2024/03/29 22:04:05 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

static void replace(std::ifstream *fd_in, std::ofstream *fd_out, std::string s1, std::string s2)
{
	std::string	line;
	long 		line_nr = 0;
	long		line_replaces;

	while (std::getline(*fd_in, line))
	{	
		line_nr++;
		
		size_t found = line.find(s1);
		// Empty line
		if (line.length() < 1)
		{
			std::cout << "Line " << line_nr << " is empty" << std::endl;
			*fd_out << std::endl;
			continue;
		}

		// Replace all occurences of s1 by s2
		line_replaces = 0;
		while (found != std::string::npos) //In the context of string searching, std::string::npos is used to indicate that no matches were found.
		{
			line_replaces++;
			*fd_out << line.substr(0, found);
			*fd_out << s2;
			line = line.substr(found + s1.length());
			found = line.find(s1);
		}
		
		// Write rest of line
		*fd_out << line;
		
		// Write a new line if the file is not at the end
		if(!fd_in->eof())
			*fd_out << std::endl;
			
		// Print Info
		std::cout << "Line " << line_nr << " has " << line_replaces << " replacements" << std::endl;
	}
}

int	main(int argc, char **argv)
{
	// Check number of arguments
	if (argc != 4)
	{
		std::cout << "Invalid number of arguments" << std::endl;
		return 1;
	}
	
	// Open input file
	std::ifstream fd_in(argv[1]);
	if (!fd_in.is_open())
	{
		std::cout << "File " << argv[1] << " not found" << std::endl;
		return 1;
	}
	
	// Open / create output file
	std::string new_fn = argv[1] + std::string(".replace");
	std::ofstream fd_out(new_fn.c_str());
	if (!fd_out.is_open())
	{
		std::cout << "File " << argv[1] + std::string(".replace") << " not found" << std::endl;
		return 1;
	}

	// Get strings
	std::string s1 = argv[2];
	if (s1.length() < 1)
	{
		std::cout << "Error: string to replace is empty" << std::endl;
		return 1;
	}
	std::string s2 = argv[3];
	
	// Replace
	replace(&fd_in, &fd_out, s1, s2);
	
	// Close files
	fd_in.close();
	fd_out.close();
	return 0;
}
