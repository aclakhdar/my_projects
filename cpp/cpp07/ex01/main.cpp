#include "iter.hpp"

void	printInt(int const &x)
{
	std::cout<< x << std::endl;
}

void addTen(int &x)
{
	x += 10;
}

int main()
{
	int  intArray[] = {1, 2, 3, 4, 5};
	size_t intArraySize = sizeof(intArray) / sizeof(intArray[0]);

	std::cout << "Printing int array:" << std::endl;
	iter(intArray, intArraySize, addTen);
	iter(intArray, intArraySize, printInt);

	std::string const str[] = {"ananas", "msmna", "tfa7", "meaw", ":3"};
	size_t sizestr = sizeof(str) / sizeof(str[0]);
	std::cout << "Printing string  array:" << std::endl;

	iter(str, sizestr, print<std::string>);


	double d[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	size_t sized = sizeof(d) / sizeof(d[0]);
	std::cout << "Printing double  array:" << std::endl;
	iter(d, sized, print<double>);
	return 0;
}

// void ft_tolower(char &arr)
// {
// 	arr = std::tolower(static_cast<unsigned char>(arr));
// }

// void ft_toupper(char &arr)
// {
// 	arr = std::toupper(static_cast<unsigned char>(arr));
// }

// int main()
// {
// 	char a[] = {'A', 'B', 'C'};

// 	std::cout << "Original:" <<
// 	"\n\ta[0]: " << a[0] <<
// 	"\n\ta[1]: " << a[1] <<
// 	"\n\ta[2]: " << a[2] <<
// 	std::endl << std::endl;

// 	::iter(a, sizeof(a) / sizeof(char), ft_tolower);

// 	std::cout << "Changed:" <<
// 	"\n\ta[0]: " << a[0] <<
// 	"\n\ta[1]: " << a[1] <<
// 	"\n\ta[2]: " << a[2] <<
// 	std::endl << std::endl;

// 	::iter(a, 2, ft_toupper);

// 	std::cout << "Changed:" <<
// 	"\n\ta[0]: " << a[0] <<
// 	"\n\ta[1]: " << a[1] <<
// 	"\n\ta[2]: " << a[2] <<
// 	std::endl << std::endl;
// }
