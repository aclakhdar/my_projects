/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algh_sort_u2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 00:31:16 by aclakhda          #+#    #+#             */
/*   Updated: 2024/05/20 00:53:03 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	check_b(t_node **b, t_node **a, t_var *var, int size)
{
	t_node		*node;
	static int	i;

	pb(a, b, 1);
	node = *b;
	if (i != 0)
	{
		if (node->value < node->next->value)
			sa(b, 1);
	}
	i++;
	inc(var, size);
}

void	inc(t_var *var, int size)
{
	if (var->max < size)
	{
		var->max++;
		var->start++;
	}
}

int	size_stack_2(t_node *a)
{
	int	i;

	i = 0;
	while (a)
	{
		a = a->next;
		i++;
	}
	return (i);
}
