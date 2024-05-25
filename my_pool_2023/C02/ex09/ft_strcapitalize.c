/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 00:59:52 by aclakhda          #+#    #+#             */
/*   Updated: 2023/09/18 01:35:28 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	oneorzero;

	i = 0;
	oneorzero = 1;
	while (str[i] != '\0')
	{
		if ((str[i] >= '0' && str[i] <= '9') || \
				(str[i] >= 'a' && str[i] <= 'z') || \
				(str[i] >= 'A' && str[i] <= 'Z'))
		{
			if (oneorzero && str[i] >= 'a' && str[i] <= 'z')
				str[i] = str[i] - 32;
			else if (!oneorzero && str[i] >= 'A' && str[i] <= 'Z')
				str[i] = str[i] + 32;
			oneorzero = 0;
		}
		else
			oneorzero = 1;
		i++;
	}
	return (str);
}
