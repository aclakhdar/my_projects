/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:57:26 by aclakhda          #+#    #+#             */
/*   Updated: 2024/06/10 12:23:33 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_sorted(t_node **a)
{
	t_node	*tmp;

	tmp = *a;
	while (tmp && tmp->next)
	{
		if ((tmp->value > tmp->next->value))
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

static t_node	*find_max(t_node **a)
{
	t_node	*tmp;
	int		max;
	t_node	*max_node;

	tmp = *a;
	max_node = tmp;
	max = tmp->value;
	while (tmp)
	{
		if (tmp->value > max)
		{
			max = tmp->value;
			max_node = tmp;
		}
		tmp = tmp->next;
	}
	return (max_node);
}

void	sort_3(t_node **a)
{
	t_node	*tmp;

	tmp = find_max(a);
	if (tmp == (*a))
		ra(a, 0);
	else if (tmp == (*a)->next)
		rra(a, 0);
	if ((*a)->value > (*a)->next->value)
		sa(a, 0);
}

void	simple_sort(t_node **a, t_node **b, int i)
{
	if (is_sorted(a))
		return ;
	if (i == 2)
		sa(a, 0);
	if (i == 3)
		sort_3(a);
	if (i == 4)
		sort_4(a, b);
	if (i == 5)
		sort_5(a, b);
}
