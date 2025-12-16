#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	std::cout << "Copy constructor called" << std::endl;
	(void) other;
	return ;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	std::cout << "Assignment operator called" << std::endl;
	(void) other;
	return (*this);
}

ScalarConverter::~ScalarConverter(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

void ScalarConverter::convert(const std::string &literal)
{
	if (literal.empty())
	{
		std::cerr << "error : string is empty" << std::endl;
		return;
	}
	//1-check the type of literal
	if (is_char(literal))
	{
		print_char(literal);
	}
	else if (is_pseudo(literal))
	{
		print_pseudo(literal);
	}
	else if (is_int(literal) || is_float(literal) || is_double(literal))
	{
		print_numeric(literal);
	}
	else
	{
		std::cerr << "error : unknown string type" << std::endl;
		return;
	}
	//2-convert the literal to the appropriate type
	//3-print the converted value <:
}
