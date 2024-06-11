/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:06:16 by aclakhda          #+#    #+#             */
/*   Updated: 2024/06/10 15:21:26 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_node **node, int i)
{
	int	first;
	int	second;

	if (!(*node) || (*node)->next == NULL)
		return ;
	first = (*node)->value;
	second = (*node)->next->value;
	(*node)->value = second;
	(*node)->next->value = first;
	if (i)
	{
		if (i == 2)
			return ;
		write(1, "sb\n", 3);
		return ;
	}
	write(1, "sa\n", 3);
}

void	ra(t_node **node, int i)
{
	t_node	*last;

	if (!(*node) || (*node)->next == NULL)
		return ;
	last = *node;
	while (last->next != NULL)
		last = last->next;
	last->next = *node;
	*node = (*node)->next;
	last->next->next = NULL;
	if (i)
	{
		if (i == 2)
			return ;
		write(1, "rb\n", 3);
		return ;
	}
	write(1, "ra\n", 3);
}

void	rra(t_node **node, int i)
{
	t_node	*last_second;

	if (!(*node) || (*node)->next == NULL)
		return ;
	last_second = *node;
	if (last_second->next == NULL)
		return ;
	while (last_second->next->next != NULL)
		last_second = last_second->next;
	last_second->next->next = *node;
	*node = last_second->next;
	last_second->next = NULL;
	if (i)
	{
		if (i == 2)
			return ;
		write(1, "rrb\n", 4);
		return ;
	}
	write(1, "rra\n", 4);
}

void	pb(t_node **a, t_node **b, int i)
{
	t_node	*tmp;

	if (!(*a))
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = *b;
	*b = tmp;
	if (i)
	{
		if (i == 2)
			return ;
		write(1, "pb\n", 3);
		return ;
	}
	write(1, "pa\n", 3);
}
