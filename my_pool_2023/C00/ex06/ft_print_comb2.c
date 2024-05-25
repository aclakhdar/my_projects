/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 23:59:55 by aclakhda          #+#    #+#             */
/*   Updated: 2023/09/17 00:01:42 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	is_more(int first, int last)
{
	int	f1;
	int	f2;
	int	l1;
	int	l2;

	f1 = first / 10 + 48;
	f2 = first % 10 + 48;
	l1 = last / 10 + 48;
	l2 = last % 10 + 48;
	ft_putchar(f1);
	ft_putchar(f2);
	ft_putchar(' ');
	ft_putchar(l1);
	ft_putchar(l2);
	if ((first / 10 != 9) || (first % 10 != 8))
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_comb2(void)
{
	int	f;
	int	l;

	f = 0;
	while (f <= 99)
	{
		l = f + 1;
		while (l <= 99)
		{
			is_more(f, l);
			l++;
		}
		f++;
	}
}
