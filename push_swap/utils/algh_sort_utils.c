/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algh_sort_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 23:14:27 by aclakhda          #+#    #+#             */
/*   Updated: 2024/05/21 00:50:23 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort(int *arr, int size)
{
	int	n;
	int	temp;
	int	i;
	int	j;

	n = size;
	i = 0;
	while (i < (n - 1))
	{
		j = 0;
		while (j < n - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

void	ft_fill_arr(t_node **a, int *arr, int size)
{
	int		i;
	t_node	*node;

	i = 0;
	node = *a;
	while (i < size)
	{
		arr[i] = node->value;
		node = node->next;
		i++;
	}
	sort(arr, size);
}

int	check_back(int *arr, int end, int value)
{
	int	i;

	i = 0;
	if (end == 0)
		return (0);
	while (i < end)
	{
		if (arr[i] == value)
			return (1);
		i++;
	}
	return (0);
}

void	helper_2(t_node **a, t_node **b, t_var *var, int size)
{
	pb(a, b, 1);
	ra(b, 1);
	inc(var, size);
}
