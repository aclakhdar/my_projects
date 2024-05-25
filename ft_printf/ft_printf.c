/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:26:43 by aclakhda          #+#    #+#             */
/*   Updated: 2023/12/08 20:18:43 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format(char c, va_list arg)
{
	int		count;

	count = 0;
	if (c == 'c')
		count += ft_putchar(va_arg(arg, int));
	else if (c == 's')
		count += ft_putstr(va_arg(arg, char *));
	else if (c == 'd' || c == 'i')
		count += ft_putnbr((long)va_arg(arg, int));
	else if (c == 'u')
		count += ft_putun((unsigned long)va_arg(arg, unsigned int));
	else if (c == 'x' || c == 'X')
		count += ft_printhex((unsigned long)va_arg(arg, unsigned int), c);
	else if (c == 'p')
		count += ft_putptr((unsigned long)va_arg(arg, void *));
	else if (c == '%')
		count += ft_putchar('%');
	else
		count += ft_putchar(c);
	return (count);
}

int	ft_printf(const char *src, ...)
{
	va_list	ag;
	int		i;

	if (!src)
		return (-1);
	i = 0;
	va_start(ag, src);
	while (*src)
	{
		if (*src == '%')
		{
			src++;
			if (!*src)
				break ;
			i += ft_format(*src, ag);
		}
		else
			i += ft_putchar(*src);
		src++;
	}
	va_end(ag);
	return (i);
}
