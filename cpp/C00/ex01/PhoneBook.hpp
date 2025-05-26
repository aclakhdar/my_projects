#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <iomanip>
#include "contact.hpp"

class PhoneBook
{
private:
	Contact contact[8];
	int count;
public:
	PhoneBook();
	~PhoneBook();

	void add_contact();
	int get_count();
	void dispay_contact();
	void display_contact_info(int index);
};

void	eof_check();

#endif
