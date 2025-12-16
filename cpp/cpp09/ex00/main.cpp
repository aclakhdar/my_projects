#include "BitcoinExchange.hpp"

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0] << " <input_file>" << std::endl;
		return 1;
	}

	try
	{
		std::string inputFile = argv[1];
		BitcoinExchange btc(inputFile);
		btc.execute();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	catch (...)
	{
		std::cerr << "Error: unknown exception caught" << '\n';
	}
	return 0;
}
