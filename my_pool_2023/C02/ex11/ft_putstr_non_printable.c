/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 20:34:56 by aclakhda          #+#    #+#             */
/*   Updated: 2023/09/20 22:26:03 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	job(int sttr)
{
	char	*hex;
	int		dev;
	int		mod;

	hex = "0123456789abcdef";
	dev = sttr / 16;
	mod = sttr % 16;
	ft_putchar('\\');
	ft_putchar(hex[dev]);
	ft_putchar(hex[mod]);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 32 || str[i] >= 127)
		{
			job((unsigned char)str[i]);
		}
		else
		{
			write (1, &str[i], 1);
		}
		i++;
	}
}
