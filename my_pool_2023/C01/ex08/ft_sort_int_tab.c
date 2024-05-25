/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 20:16:50 by aclakhda          #+#    #+#             */
/*   Updated: 2023/09/17 20:47:27 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_sort_int_tap(int *tab, int size)
{	
	int	i;
	int	swip;

	while (size > 0)
	{
		i = 0;
		while (i < (size - 1))
		{
			if (tab[i] > tab[i + 1])
			{
				swip = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = swip;
			}
				i++;
		}
		size--;
	}
}
