#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <cctype>
#include <iomanip>
#include <limits>
#include <limits.h>
#include <cmath>
#include <cfloat>

class ScalarConverter
{
	private:
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter &operator=(const ScalarConverter &other);
		~ScalarConverter();
	public:
		static void convert(const std::string &literal);
};

bool	is_char(const std::string &str);
bool	is_int(const std::string &str);
bool	is_float(const std::string &str);
bool	is_double(const std::string &str);
bool	is_pseudo(const std::string &str);
void	print_char(const std::string &literal);
void	print_numeric(const std::string &literal);
void	print_pseudo(const std::string &str);

#endif

