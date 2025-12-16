#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <cstdlib>
#include <iomanip>


class BitcoinExchange
{
	private:
		std::map<std::string, double>	data; //hna radi nstory data dyal database
		std::string						input_file;
		void	load_data(std::ifstream &file);
		void	print_data(std::ifstream &infile);
		void	parsevalue(const std::string &value);
		void	parsedate(const std::string &date);
		void	print(const std::string &date, const std::string &value);
	public:
		BitcoinExchange(void);
		BitcoinExchange(std::string inputFile);
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		~BitcoinExchange();
		void	execute();
};

#endif

