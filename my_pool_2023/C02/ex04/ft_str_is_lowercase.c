/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 23:42:43 by aclakhda          #+#    #+#             */
/*   Updated: 2023/09/20 22:11:23 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_lowercase(char *str)
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
			if (str[x] >= 97 && str[x] <= 122)
			{
				x++;
			}
			else
				return (0);
		}
	}
	return (1);
}
