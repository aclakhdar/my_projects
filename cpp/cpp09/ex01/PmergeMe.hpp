#define PmergeMe_HPP
#pragma once
# include <iostream>
#include <stack>
#include <sstream>
#include <stdlib.h>

class PmergeMe
{
	private:
		std::stack<int>	c;
		std::string token;
		PmergeMe(void);
		bool	is_number(std::string &str);
		bool	is_operator(std::string &str);
		int		pop();
	public:
		PmergeMe(std::string numbers);
		PmergeMe(const PmergeMe& other);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe();
		void calculate();
};


