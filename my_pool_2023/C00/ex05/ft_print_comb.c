/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 23:05:39 by aclakhda          #+#    #+#             */
/*   Updated: 2023/09/15 21:33:11 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_job(char z, char x, char v)
{
	write (1, &z, 1);
	write (1, &x, 1);
	write (1, &v, 1);
	if (z != '7' || x != '8' || v != '9')
	{
		write (1, ",", 1);
		write (1, " ", 1);
	}
}

void	ft_print_comb(void)
{
	char	a;
	char	b;
	char	c;

	a = '0';
	while (a <= '7')
	{
		b = a + 1;
		while (b <= '8')
		{
			c = b + 1;
			while (c <= '9')
			{
				ft_job(a, b, c);
				c++;
			}
			b++;
		}
		a++;
	}
}
