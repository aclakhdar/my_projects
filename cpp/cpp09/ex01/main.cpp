#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "usage: ./PmergeMe \"numbers\"" << std::endl;
		return (1);
	}
	try
	{
		PmergeMe pm(av[1]);
		pm.calculate();
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return (1);
	}
	catch (...)
	{
		std::cerr << "Unknown error occurred" << std::endl;
		return (1);
	}
	return (0);
}

