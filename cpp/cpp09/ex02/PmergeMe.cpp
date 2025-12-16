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

void	PmergeMe::parse(int ac, char **av) {
	for (int i = 1;i < ac;i++) {
		std::string arg(av[i]);
		if (arg.empty())
			throw std::invalid_argument("Empty argument");
		for (size_t j = 0; j < arg.size(); j++) {
			if (!isdigit(arg[j]))
				throw std::invalid_argument("Invalid character in argument");
		}
		long long numl = std::strtol(arg.c_str(), NULL, 10);
		if (numl > std::numeric_limits<int>::max() || numl < std::numeric_limits<int>::min())
			throw std::invalid_argument("Number out of int range");
		int num = static_cast<int>(numl);
		if (num < 0)
			throw std::invalid_argument("Negative number");
		if (std::find(this->vec.begin(), this->vec.end(), num) != this->vec.end())
			throw std::invalid_argument("Duplicate number");
		this->vec.push_back(num);
		this->list.push_back(num);
	}
}

std::vector<int>	PmergeMe::jacobsthal(int n)
{
	std::vector<int>	seq;
	seq.push_back(0);
	seq.push_back(1);
	while(1)
	{
		int next = seq[seq.size()-1] + 2 * seq[seq.size()-2];
		if (next >= n)
			break;
		seq.push_back(next);
	}
	return seq;
}

std::string	PmergeMe::print_c(std::vector<int> &c)
{
	std::ostringstream oss;
	for (size_t i = 0; i < c.size(); i++)
	{
		oss << c[i];
		if (i != c.size() - 1)
			oss << " ";
	}
	return oss.str();
}

size_t PmergeMe::get_m()
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return (long long)tv.tv_sec * 1000000 + tv.tv_usec;
}

void insertion_sort(std::vector<int> &vec)
{
	for (size_t i = 1; i < vec.size(); i++)
	{
		int key = vec[i];
		int j = i - 1;
		while (j >= 0 && vec[j] > key)
		{
			vec[j + 1] = vec[j];
			if (j == 0)
				break;
			j--;
		}
		if (vec[j] > key)
			vec[j + 1] = vec[j], vec[j] = key;
		else
			vec[j + 1] = key;
	}
}

void insertion_sort(std::deque<int> &vec)
{
	for (size_t i = 1; i < vec.size(); i++)
	{
		int key = vec[i];
		int j = i - 1;
		while (j >= 0 && vec[j] > key)
		{
			vec[j + 1] = vec[j];
			if (j == 0)
				break;
			j--;
		}
		if (vec[j] > key)
			vec[j + 1] = vec[j], vec[j] = key;
		else
			vec[j + 1] = key;
	}
}

void	PmergeMe::ford_algho(std::vector<int> &c)
{
	if (c.size() <= 10)
	{
		insertion_sort(c);
		return ;
	}
	std::vector<std::pair<int,int> > pairs;
	int leftover = -1;
	for (size_t i = 0; i + 1 < c.size(); i += 2)
	{
		int a = c[i], b = c[i+1];
		if (a < b) std::swap(a, b);
		pairs.push_back(std::make_pair(b, a));
	}
	if (c.size() % 2 != 0) leftover = c.back();

	std::vector<int> mainChain;
	for (size_t i = 0; i < pairs.size(); i++)
		mainChain.push_back(pairs[i].first);
	std::sort(mainChain.begin(), mainChain.end());

	std::vector<int> mins;
	for (size_t i = 0; i < pairs.size(); i++)
		mins.push_back(pairs[i].second);


	std::vector<int> order = PmergeMe::jacobsthal(mins.size());
	std::vector<bool> inserted(mins.size(), false);

	for (size_t k = 0; k < order.size(); k++)
	{
		int idx = order[k];
		if (idx < (int)mins.size() && !inserted[idx])
		{
			int val = mins[idx];
			mainChain.insert(std::lower_bound(mainChain.begin(), mainChain.end(), val), val);
			inserted[idx] = true;
		}
	}

	for (size_t i = 0; i < mins.size(); i++) {
		if (!inserted[i]) {
			int val = mins[i];
			mainChain.insert(std::lower_bound(mainChain.begin(), mainChain.end(), val), val);
		}
	}

	if (leftover != -1)
		mainChain.insert(std::lower_bound(mainChain.begin(), mainChain.end(), leftover), leftover);

	c = mainChain;
}

void	PmergeMe::ford_algho(std::deque<int> &c)
{
	if (c.size() <= 10)
	{
		insertion_sort(c);
		return ;
	}
	std::deque<std::pair<int, int> > pairs;
	int leftover = -1;

	for (size_t i = 0; i + 1 < c.size(); i += 2)
	{
		int a = c[i], b = c[i + 1];
		if (a < b) std::swap(a, b);
		pairs.push_back(std::make_pair(b, a));
	}

	if (c.size() % 2 != 0)
		leftover = c.back();
	std::deque<int> mainChain;
	for (size_t i = 0; i < pairs.size(); i++)
		mainChain.push_back(pairs[i].first);
	std::sort(mainChain.begin(), mainChain.end());

	std::deque<int> mins;
	for (size_t i = 0; i < pairs.size(); i++)
		mins.push_back(pairs[i].second);

	std::vector<int> order = PmergeMe::jacobsthal(mins.size());
	std::deque<bool> inserted(mins.size(), false);


	for (size_t k = 0; k < order.size(); k++)
	{
		int idx = order[k];
		if (idx < (int)mins.size() && !inserted[idx])
		{
			int val = mins[idx];
			mainChain.insert(std::lower_bound(mainChain.begin(), mainChain.end(), val), val);
			inserted[idx] = true;
		}
	}

	for (size_t i = 0; i < mins.size(); i++)
	{
		if (!inserted[i])
		{
			int val = mins[i];
			mainChain.insert(std::lower_bound(mainChain.begin(), mainChain.end(), val), val);
		}
	}

	if (leftover != -1)
		mainChain.insert(std::lower_bound(mainChain.begin(), mainChain.end(), leftover), leftover);

	c = mainChain;
}

void	PmergeMe::sort()
{
	std::cout << "before :" << print_c(vec) << std::endl;
	size_t	start = get_m();
	ford_algho(vec);
	size_t	end = get_m();
	size_t	vec_time = end - start;
	start = get_m();
	ford_algho(list);
	end	= get_m();
	size_t	list_time = end - start;
	std::cout << "After:  " << print_c(vec) << std::endl;
	std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " << vec_time << " us" << std::endl;
	std::cout << "Time to process a range of " << vec.size() << " elements with std::deque :  " << list_time << " us" << std::endl;
}
