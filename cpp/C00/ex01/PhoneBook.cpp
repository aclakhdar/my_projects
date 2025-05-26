#include "PhoneBook.hpp"
#include "contact.hpp"

PhoneBook::PhoneBook()
{
	this->count = 0;
}

PhoneBook::~PhoneBook()
{
}

int	check_input(std::string a, std::string b, std::string c)
{
	bool	d;

	d = false;
	if (a.size() == 0)
		d = true;
	if (b.size() == 0)
		d = true;
	if (c.size() == 0)
		d = true;
	if (d)
	{
		std::cout << "invalide inpute try again\n";
		return 1;
	}
	return 0;
}

int	check_input2(std::string a, std::string b)
{
	bool	d;

	d = false;
	if (a.size() == 0)
		d = true;
	if (b.size() == 0)
		d = true;
	if (d)
	{
		std::cout << "invalide inpute try again\n";
		return 1;
	}
	return 0;
}

void	eof_check()
{
	if (std::cin.eof())
	{
		std::cout << "EOF detected. Exiting..." << std::endl;
		exit(0);
	}
}

void PhoneBook::add_contact()
{
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;
	static int	overwrite;

	std::cout << "Enter first name: ";
	std::getline(std::cin, first_name);
	eof_check();
	std::cout << "Enter last name: ";
	std::getline(std::cin, last_name);
	eof_check();
	std::cout << "Enter nickname: ";
	std::getline(std::cin, nickname);
	eof_check();
	std::cout << "Enter phone number: ";
	std::getline(std::cin, phone_number);
	eof_check();
	std::cout << "Enter darkest secret: ";
	std::getline(std::cin, darkest_secret);
	eof_check();
	if (check_input(first_name, last_name, nickname))
		return ;
	if (check_input2(phone_number, darkest_secret))
		return ;
	if (this->count >= 8)
	{
		if (overwrite == 8)
			overwrite = 0;
		this->contact[overwrite] = Contact(first_name, last_name, nickname, phone_number, darkest_secret);
		overwrite++;
		return;
	}
	this->contact[this->count] = Contact(first_name, last_name, nickname, phone_number, darkest_secret);
	this->count++;
}

void PhoneBook::dispay_contact()
{
	std::cout << "Index     |First Name|Last Name | Nickname " << std::endl;
	std::cout << "-----------------------------------------------" << std::endl;
	for (int i = 0; i < this->count; i++)
	{
		std::cout << i + 1 << "         |";
		if (this->contact[i].get_first_name().size() > 10)
			std::cout << this->contact[i].get_first_name().substr(0, 9) << ".|";
		else
		{
			std::cout << std::setw(10) << std::left;
			std::cout << this->contact[i].get_first_name();
			std::cout << "|";
		}
		if (this->contact[i].get_last_name().size() > 10)
			std::cout << this->contact[i].get_last_name().substr(0, 9) << ".|";
		else
		{
			std::cout << std::setw(10) << std::left;
			std::cout << this->contact[i].get_last_name();
			std::cout << "|";
		}
		if (this->contact[i].get_nickname().size() > 10)
			std::cout << this->contact[i].get_nickname().substr(0, 9) << ".|";
		else
		{
			std::cout << std::setw(10) << std::left;
			std::cout << this->contact[i].get_nickname();
			std::cout << "|";
		}
		std::cout << std::endl;
	}
}

void print_contact(Contact contact)
{
	std::cout << "first name: " << contact.get_first_name() << std::endl;
	std::cout << "last name: " << contact.get_last_name() << std::endl;
	std::cout << "nickname: " << contact.get_nickname() << std::endl;
	std::cout << "phone number: " << contact.get_phone_number() << std::endl;
	std::cout << "darkest secret: " << contact.get_darkest_secret() << std::endl;
}

void PhoneBook::display_contact_info(int index)
{
	if (index < 1 || index > this->get_count())
	{
		std::cout << "index is out of range try again\n";
		return ;
	}
	print_contact(this->contact[index - 1]);
}

int	PhoneBook::get_count()
{
	return (this->count);
}
