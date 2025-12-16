#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <sstream>
#include <stdexcept>
#include <algorithm>
#include <sys/time.h>
#include <limits>

class PmergeMe
{
	private:
		std::vector<int>	vec;
		std::deque<int>		list;
		std::vector<int>	jacobsthal(int n);	//generete the jaco sequence 3la 7sab our arr size
		std::string			print_c(std::vector<int> &c);
		size_t				get_m();
		void				ford_algho(std::vector<int>	&c);
		void				ford_algho(std::deque<int>	&c);
	public:
		PmergeMe(void);
		PmergeMe(const PmergeMe& other);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe();
		void	parse(int ac, char **av);
		void	sort();
};

#endif

