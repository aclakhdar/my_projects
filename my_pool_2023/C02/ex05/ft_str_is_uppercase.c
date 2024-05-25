/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 23:45:10 by aclakhda          #+#    #+#             */
/*   Updated: 2023/09/20 22:12:10 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_uppercase(char *str)
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
			if (str[x] >= 65 && str[x] <= 90)
			{
				x++;
			}
			else
				return (0);
		}
	}
	return (1);
}
