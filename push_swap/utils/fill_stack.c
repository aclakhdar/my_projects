/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 16:08:37 by aclakhda          #+#    #+#             */
/*   Updated: 2024/06/10 16:23:58 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*fill(int value, t_node **a, char **av)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		k(a, av);
	new->value = value;
	new->next = NULL;
	return (new);
}

t_node	*last_node(t_node *a)
{
	while (a && a->next)
		a = a->next;
	return (a);
}

void	add_last_node(t_node **a, t_node *new)
{
	t_node	*last;

	if (!*a)
	{
		*a = new;
		return ;
	}
	last = last_node(*a);
	last->next = new;
}

t_node	*fill_stack(char **av)
{
	t_node	*a;
	int		i;
	long	number;

	i = 0;
	a = NULL;
	while (av[i])
	{
		number = ft_atoi(av[i]);
		if (number > INT_MAX || number < INT_MIN || number == LONG_MAX)
			k(&a, av);
		add_last_node(&a, fill((int)number, &a, av));
		i++;
	}
	return (a);
}
