#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	std::cout << "Copy constructor called" << std::endl;
	(void) other;
	return ;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	std::cout << "Assignment operator called" << std::endl;
	(void) other;
	return (*this);
}

PmergeMe::~PmergeMe(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

PmergeMe::PmergeMe(std::string numbers)
{
	this->token = numbers;
	return ;
}

bool PmergeMe::is_number(std::string &str)
{
	if (str.empty() || str.size() > 2)
		return false;
	int i = 0;
	if (str[0] == '-' || str[0] == '+')
	{
		if (str.size() == 1)
			return false;
		i = 1;
	}
	if (str.size() - i > 1)
		return false;
	return true;
}

bool	PmergeMe::is_operator(std::string &str)
{
	if (str == "+" or str == "-" or str == "*" or str == "/")
		return true;
	return false;
}

int	PmergeMe::pop()
{
	int	value;

	if (c.empty())
		throw	std::runtime_error("stack is empty");
	value = c.top();
	c.pop();
	return value;
}

void PmergeMe::calculate()
{
	std::istringstream iss(this->token);
	std::string token;
	int n1;
	int n2;

	while(iss >> token)
	{
		if (!is_number(token) and !is_operator(token))
			throw std::invalid_argument("invalide token : " + token);
		if (is_number(token) and !is_operator(token))
			c.push(static_cast<int>(std::strtol(token.c_str(), NULL, 10)));
		else
		{
			n2 = pop();
			n1 = pop();
			switch (token[0])
			{
			case '+':
				c.push(n1 + n2);
				break;
			case '-':
				c.push(n1 - n2);
				break;
			case '*':
				c.push(n1 * n2);
				break;
			case '/':
				if (n2 == 0)
					throw std::runtime_error("cant divide by 0");
				c.push(n1 / n2);
			default:
				break;
			}
		}

	}
	if (c.size() != 1)
		throw std::runtime_error("invalide expresion");
	std::cout << c.top() << std::endl;
}
