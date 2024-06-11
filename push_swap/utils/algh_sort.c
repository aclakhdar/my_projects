/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algh_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 21:32:24 by aclakhda          #+#    #+#             */
/*   Updated: 2024/06/10 15:37:48 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_max(t_node **b)
{
	t_node	*node;
	int		max;

	node = *b;
	max = node->value;
	while (node)
	{
		if (node->value > max)
			max = node->value;
		node = node->next;
	}
	return (max);
}

int	find_max_position(t_node **b, int max, int size)
{
	int		i;
	t_node	*tmp;

	tmp = *b;
	i = 0;
	while (tmp)
	{
		if (tmp->value == max)
			break ;
		tmp = tmp->next;
		i++;
	}
	if (i <= size / 2)
		return (0);
	if (i == 1)
		return (2);
	return (1);
}

void	part_2(t_node **b, t_node **a, t_var var, int *arr)
{
	while (*b)
	{
		var.max = find_max(b);
		var.i = find_max_position(b, var.max, var.size);
		if (var.i == 0)
		{
			while ((*b)->value != var.max)
				ra(b, 1);
		}
		else if (var.i == 2)
		{
			while ((*b)->value != var.max)
				sa(b, 1);
		}
		else
		{
			while ((*b)->value != var.max)
				rra(b, 1);
		}
		pb(b, a, 0);
		var.size = size_stack_2(*b);
	}
	free(arr);
}

int	*creat_arr(t_node **a, t_var *var, int size, char **av)
{
	int	*arr;

	var->start = 0;
	var->max = ft_sqrt(size * 3);
	var->size = size;
	arr = (int *)malloc(sizeof(int) * size);
	if (arr == NULL)
		k(a, av);
	ft_fill_arr(a, arr, size);
	return (arr);
}

void	algh_sort(t_node **a, t_node **b, int size, char **av)
{
	int		*arr;
	t_var	var;

	arr = creat_arr(a, &var, size, av);
	while (*a)
	{
		var.i = var.start;
		while (var.i < var.max)
		{
			if (arr[var.i] == (*a)->value)
			{
				check_b(b, a, &var, size);
				break ;
			}
			var.i++;
		}
		if (var.i == var.max)
		{
			if (check_back(arr, var.start, (*a)->value))
				helper_2(a, b, &var, size);
			else
				ra(a, 0);
		}
	}
	part_2(b, a, var, arr);
}
