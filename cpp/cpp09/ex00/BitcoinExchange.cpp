#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
	return ;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	std::cout << "Assignment operator called" << std::endl;
	if (this != &other)
	{
		this->data = other.data;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

void	BitcoinExchange::load_data(std::ifstream &file) //hada dyyal database
{
	std::string line;
	std::string date;
	std::string value;
	size_t pos = 0;

	std::getline(file, line);
	while (std::getline(file, line))
	{
		if(line.empty())
			continue;
		pos = line.find(',');
		if (pos == std::string::npos)
			throw std::runtime_error("Error: invalid line format");
		date = line.substr(0, pos);
		value = line.substr(pos + 1);
		if (date.empty() || value.empty())
			throw std::runtime_error("Error: invalid line format");
		double value_f = std::atof(value.c_str());
		if (value_f < 0)
			throw std::runtime_error("Error: negative value not allowed");
		data[date] = value_f;
	}
	file.close();
}

void	BitcoinExchange::parsedate(const std::string &date)
{
	// std::cout << "\""+ date + "\" \n";
	if (date.empty())
		throw std::runtime_error("Error: empty date");
	if (date.size() != 10)
		throw std::runtime_error("Error 4 : invalid date format => " + date);
	if (date[4] != '-' || date[7] != '-')
		throw std::runtime_error("Error 3 : invalid date format => " + date);
	for (int i = 0; i < 10; i++)
	{
		if (!std::isdigit(date[i]) && i != 4 && i != 7)
			throw std::runtime_error("Error 2 : invalid date format => " + date);
	}
	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());
	if (year < 2009 || year > 2022 || month < 1 || month > 12 || day < 1 || day > 31)
		throw std::runtime_error("Error 1 : invalid date format => " + date);
}

void	BitcoinExchange::parsevalue(const std::string &value)
{
	bool	f = false;
	double	number;
	size_t i = 0;
	if (value.empty())
		throw std::runtime_error("Error: empty value");
	while (i < value.size()) {
		if (value[i] == '.' && !f) {
			f = true;
			i++;
			continue;
		}
		if (!std::isdigit(value[i]))
			throw std::runtime_error("Invalid value format => " + value);
		i++;
	}
	number = std::strtod(value.c_str(), NULL);
	if (number < 0)
		throw std::runtime_error("not a positive number");
	if (number > 1000)
		throw std::runtime_error("too large number");
}

void	BitcoinExchange::print(const std::string &date, const std::string &value)
{
	std::map<std::string, double>::iterator it = data.lower_bound(date);
	double rate;

	if (it == data.begin() && it->first > date)
		throw std::runtime_error("No data for date => " + date);
	if (it == data.end() || it->first > date)
		it--;
	rate = it->second;
	std::cout << date << " => " << value << " = " << rate * std::strtod(value.c_str(), NULL) << std::endl;
}

void	BitcoinExchange::print_data(std::ifstream &file)
{
	std::string line;
	std::string date;
	std::string value;
	int pos = 0;

	std::getline(file, line);
	if (line != "date | value")
		throw std::runtime_error("Error: invalid file header");
	while (std::getline(file, line))
	{
		if (line.empty() || line == "date | value")
			continue ;
		pos = line.find("|");
		try
		{
			if (line.size() < 13)
				throw std::runtime_error("bad inpute => " + line);
			if (line[10] != ' ' or line[11] != '|' or line[12] != ' ')
				throw std::runtime_error("bad inpute => " + line);
			date = line.substr(0, pos - 1);
			value = line.substr(pos + 2);
			parsedate(date);
			parsevalue(value);
			print(date, value);
		}
		catch (const std::exception &e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
		}
		catch (...)
		{
			std::cerr << "Unknown error occurred" << std::endl;
		}
	}

}

void	BitcoinExchange::execute()
{
	std::ifstream file("data.csv");
	if (!file.is_open())
		throw std::runtime_error("Error: could not open data.csv file");
	std::ifstream infile(input_file.c_str());
	if (!infile.is_open())
		throw std::runtime_error("Error: could not open input file");
	load_data(file);
	print_data(infile);
}

BitcoinExchange::BitcoinExchange(std::string inputFile)
{
	this->input_file = inputFile;
}
