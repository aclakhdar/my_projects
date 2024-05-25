/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 00:46:43 by aclakhda          #+#    #+#             */
/*   Updated: 2023/10/02 20:39:20 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int		i;
	int		*tap;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	tap = (int *)malloc(sizeof(int) * (max - min));
	if (tap == NULL)
	{
		return (-1);
	}
	else
	{
		i = 0;
		while (i < (max - min))
		{
			tap[i] = min + i;
			i++;
		}
		*range = tap;
		return (i);
	}
}
