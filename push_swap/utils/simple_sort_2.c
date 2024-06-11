/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 22:10:51 by aclakhda          #+#    #+#             */
/*   Updated: 2024/06/08 13:09:31 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	min_value_1(t_node **a)
{
	int			min;
	t_node		*tmp;
	static int	stay_here;
	static int	i;

	tmp = *a;
	min = tmp->value;
	while (tmp && tmp->next)
	{
		tmp = tmp->next;
		if (tmp->value < min)
		{
			if (i == 0)
				min = tmp->value;
			else if (tmp->value != stay_here)
				min = tmp->value;
		}
	}
	stay_here = min;
	i++;
	return (min);
}

int	min_value_2(t_node **a)
{
	int			min;
	t_node		*tmp;
	static int	stay_here;
	static int	i;

	tmp = *a;
	min = tmp->value;
	while (tmp && tmp->next)
	{
		tmp = tmp->next;
		if (tmp->value < min)
		{
			if (i == 0)
				min = tmp->value;
			else if (tmp->value != stay_here)
				min = tmp->value;
		}
	}
	stay_here = min;
	i++;
	return (min);
}

void	sort_4(t_node **a, t_node **b)
{
	int	dest;

	dest = destance(a, min_value_1(a));
	if (dest == 1)
		sa(a, 0);
	else if (dest == 2)
	{
		ra(a, 0);
		sa(a, 0);
	}
	else if (dest == 3)
		rra(a, 0);
	if (is_sorted(a))
		return ;
	pb(a, b, 1);
	sort_3(a);
	pb(b, a, 0);
}

void	sort_5(t_node **a, t_node **b)
{
	int	dest;

	dest = destance(a, min_value_2(a));
	if (dest == 1)
		sa(a, 0);
	else if (dest == 2)
	{
		ra(a, 0);
		sa(a, 0);
	}
	else if (dest == 3)
	{
		rra(a, 0);
		rra(a, 0);
	}
	else if (dest == 4)
		rra(a, 0);
	if (is_sorted(a))
		return ;
	pb(a, b, 1);
	sort_4(a, b);
	pb(b, a, 0);
}
