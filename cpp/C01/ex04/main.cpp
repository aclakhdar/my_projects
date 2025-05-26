/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 19:33:06 by aclakhda          #+#    #+#             */
/*   Updated: 2025/05/18 16:24:18 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

int	parising(int ac, char **av)
{
	if (ac != 4)
		return (1);
	if (av[1][0] == '\0' || av[2][0] == '\0' || av[3][0] == '\0')
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	std::string line;
	std::string input_file;
	std::string output_file;
	std::ifstream input;
	std::ofstream output;
	std::string new_line;
	size_t pos;
	size_t found;
	int i;

	if (parising(ac, av))
	{
		std::cerr << "Error: Invalid arguments" << std::endl;
		return 1;
	}
	input_file = av[1];
	output_file = input_file + ".replace";
	input.open(input_file.c_str());
	if (!input.is_open())
	{
		std::cerr << "Error: Could not open input file" << std::endl;
		return 1;
	}
	output.open(output_file.c_str());
	if (!output.is_open())
	{
		std::cerr << "Error: Could not open output file" << std::endl;
		input.close();
		return 1;
	}
	while (std::getline(input, line))
	{
		i = 0;
		while((found = line.find(av[2], i)) != std::string::npos)
		{
			new_line += line.substr(i, found - i);
			new_line += av[3];
			i = found + std::string(av[2]).length();
		}
		new_line += line.substr(i);
		output << new_line << std::endl;
		new_line.clear();
	}
	input.close();
	output.close();
	return 0;
}
