#include "ScalarConverter.hpp"

bool	is_char(const std::string &str)
{
	if (str.length() == 1 && std::isprint(str[0]))
		return (true);
	return (false);
}

bool	is_int(const std::string &str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!std::isdigit(str[i]))
			return (false);
	}
	return (true);
}

bool	is_float(const std::string &str)
{
	size_t start;
	if (str[0] == '-' || str[0] == '+')
		start = 1;
	else
		start = 0;
	bool dot = false;
	while (start < str.size())
	{
		if (str[start] == '.')
		{
			if (dot)
				return false;
			dot = true;
			start++;
			continue;
		}
		if (!std::isdigit(str[start]))
		{
			if (str[start] == 'f' && start + 1 == str.size())
				return true;
			else
				return false;
		}
		start++;
	}
	return false;
}

bool	is_double(const std::string &str)
{
	size_t start;
	if (str[0] == '-' || str[0] == '+')
		start = 1;
	else
		start = 0;
	bool dot = false;
	while (start < str.size()) {
		if (str[start] == '.' && !dot) {
			dot = true;
			start++;
			continue;
		}
		if (!std::isdigit(str[start]))
			return false;
		start++;
	}
	return true;
}

bool	is_pseudo(const std::string &str)
{
	if (str == "nan" || str == "inf" || str == "-inf" || str == "+inf")
		return true;
	if (str == "nanf" || str == "inff" || str == "-inff" || str == "+inff")
		return true;
	return false;
}

int count(const std::string &str)
{
	size_t start;
	if (str[0] == '-' || str[0] == '+')
		start = 1;
	else
		start = 0;
	size_t count = 0;
	bool dot = false;
	while (start < str.size())
	{
		if (str[start] == '.' && !dot)
		{
			dot = true;
			start++;
			continue;
		}
		if (dot)
			count++;
		start++;
	}
	if (!dot)
		return 1;
	return count;
}

void	print_char(const std::string &str)
{
	char c = str[0];
	if (c < CHAR_MIN || c > CHAR_MAX)
		std::cout << "char: impossible" << std::endl;
	if (!std::isprint(c))
		std::cout << "char: non displayable" << std::endl;
	else
		std::cout << "char: '" << c << "'" << std::endl;

	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << std::fixed << std::setprecision(count(str));
	std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << std::endl;
}

void print_numeric(const std::string &str)
{
	double d = std::strtod(str.c_str(), NULL);//hhadi double
	if (!std::isfinite(d))
	{
		std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible" << std::endl;
		return ;
	}
	long l = static_cast<long>(d);
	float f = static_cast<float>(d);
	//char
	if (l < CHAR_MIN || l > CHAR_MAX)
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(static_cast<char>(l)))
		std::cout << "char: non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(l) << "'" << std::endl;
	//int
	if (l < INT_MIN || l > INT_MAX)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(l) << std::endl;
	//float
	std::cout << std::fixed << std::setprecision(count(str));
	std::cout << "float: " << f << "f" << std::endl;
	//double
	std::cout << "double: " << d << std::endl;
}

void	print_pseudo(const std::string &str)
{
	if (str == "nan" || str == "nanf") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	} else if (str == "inf" || str == "+inf") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: inff" << std::endl;
		std::cout << "double: inf" << std::endl;
	} else if (str == "inff" || str == "+inff") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: inff" << std::endl;
		std::cout << "double: inf" << std::endl;
	} else if (str == "-inf" || str == "-inff") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}

}
