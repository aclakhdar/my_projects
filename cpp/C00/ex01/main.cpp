#include <iostream>
#include "PhoneBook.hpp"
#include <limits>

int main()
{
	std::string command;
	std::string input;
	PhoneBook phonebook;
	int	index;

	while(true)
	{
		std::cout << "Enter command (ADD, SEARCH, EXIT): \n";
		std::getline(std::cin, command);
		eof_check();
		if (command.compare("ADD") == 0)
		{
			std::cout << "Adding contact..." << std::endl;
			phonebook.add_contact();
		}
		else if (command.compare("SEARCH") == 0)
		{
			std::cout << "Searching contact..." << std::endl;
			phonebook.dispay_contact();
			std::cout << "Enter the index of the contact you want to see: \n";
			std::getline(std::cin, input);
			eof_check();
			if (input.size() != 1 || !isdigit(input[0]) || input[0] < '1' || input[0] > '8')
			{
				std::cout << "Invalid input. Please enter a number between 1 and 8." << std::endl;
				continue;
			}
			index = atoi(input.c_str());
			phonebook.display_contact_info(index);
		}
		else if (command.compare("EXIT") == 0)
		{
			std::cout << "Exiting..." << std::endl;
			break;
		}
		else
			std::cout << "Invalid command. Please try again." << std::endl;
	}
	return (0);
}
