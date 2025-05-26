#include <iostream>
#include <cctype>

int main(int ac, char **av)
{
	if (ac != 1)
	{
		for (int i = 1; i < ac; i++)
		{
			for (int j = 0; av[i][j] != '\0'; j++)
			{
				if (isalpha(av[i][j]))
					std::cout << (char)toupper(av[i][j]);
				else
					std::cout << av[i][j];
			}
			if (i < ac - 1)
				std::cout << " ";
		}
		std::cout << std::endl;
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return 0;
}
