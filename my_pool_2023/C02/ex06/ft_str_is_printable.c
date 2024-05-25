/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 00:04:42 by aclakhda          #+#    #+#             */
/*   Updated: 2023/09/20 22:13:06 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_printable(char *str)
{
	int	x;

	x = 0;
	if (str == '\0')
	{
		return (1);
	}
	else
	{
		while (str[x])
		{
			if (str[x] >= 32 && str[x] < 127)
			{
				x++;
			}
			else
				return (0);
		}
	}
	return (1);
}
