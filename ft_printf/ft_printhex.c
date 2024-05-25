/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 21:55:01 by aclakhda          #+#    #+#             */
/*   Updated: 2023/12/04 21:57:03 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhex(unsigned long long nb, int c)
{
	char	*base;
	int		count;

	count = 0;
	if (c == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (nb >= 16)
	{
		count += ft_printhex(nb / 16, c);
		count += ft_printhex(nb % 16, c);
	}
	else
		count += ft_putchar(base[nb]);
	return (count);
}
