#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <stdexcept>
#include <limits>
#include <cstdlib>
#include <ctime>

class Span
{
	private:
		unsigned int		N;
		std::vector<int>	arr;
		Span(void);
	public:
		Span(unsigned int N);
		Span(const Span& other);
		Span &operator=(const Span &other);
		~Span();
		void	addNumber(int number);
		int		shortestSpan(void);
		int		longestSpan(void);
};

#endif

