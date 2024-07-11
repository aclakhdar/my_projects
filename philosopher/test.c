#include <stdio.h>
#include <unistd.h>
int    ft_iterative_factorial(int nb)
{
	if (nb == 0)
		return 1;
	if (nb < 0)
		return 0;
	if (nb == 1)
		return 1;
	return (nb * ft_iterative_factorial(nb - 1));
}

int main()
{
	printf("%d\n", ft_iterative_factorial(4));
}
