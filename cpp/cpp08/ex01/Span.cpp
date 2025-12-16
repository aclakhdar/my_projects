#include "Span.hpp"

Span::Span(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->N = 0;
	return ;
}

Span::Span(const Span &other)
{
	std::cout << "Copy constructor called" << std::endl;
	this->N = other.N;
	this->arr = other.arr;
	return ;
}

Span &Span::operator=(const Span &other)
{
	std::cout << "Assignment operator called" << std::endl;
	if (this != &other)
	{
		this->N = other.N;
		this->arr = other.arr;
	}
	return (*this);
}

Span::~Span(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

Span::Span(unsigned int N)
{
	this->N = N;
}

void	Span::addNumber(int number)
{
	if(arr.size() >= N)
		throw std::out_of_range("Span is full");
	arr.push_back(number);
}

int	Span::longestSpan()
{
	if (arr.size() < 2)
		throw std::logic_error("Not enough numbers to find a span");
	int min = *std::min_element(arr.begin(), arr.end());
	int max = *std::max_element(arr.begin(), arr.end());
	return (max - min);
}

int	Span::shortestSpan()
{
	if (arr.size() < 2)
		throw std::logic_error("Not enough numbers to find a span");
	std::vector<int> tmp = arr; // sort arr complexity time 
	std::sort(tmp.begin(), tmp.end());
	int min_span = __INT_MAX__;
	for (size_t i = 1; i < tmp.size(); ++i)
	{
		int span = tmp[i] - tmp[i - 1];
		if (span < min_span)
			min_span = span;
	}
	return (min_span);
}
