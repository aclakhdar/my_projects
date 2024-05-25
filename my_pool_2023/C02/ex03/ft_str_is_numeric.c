/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 23:36:06 by aclakhda          #+#    #+#             */
/*   Updated: 2023/09/20 22:10:08 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_numeric(char *str)
{
	int	x;

	x = 0;
	if (str == '\0' || str == NULL)
	{
		return (1);
	}
	else
	{
		while (str[x])
		{
			if (str[x] >= 48 && str[x] <= 57)
			{
				x++;
			}
			else
				return (0);
		}
	}
	return (1);
}
