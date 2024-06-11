/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 22:28:43 by aclakhda          #+#    #+#             */
/*   Updated: 2024/06/08 15:24:54 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_free_stack(t_node **stack)
{
	t_node	*now;
	t_node	*next;

	now = *stack;
	while (now != NULL)
	{
		next = now->next;
		free(now);
		now = next;
	}
}

void	ft_free_av(char **av)
{
	int	i;

	i = 0;
	if (av)
	{
		while (av[i])
		{
			free(av[i]);
			i++;
		}
		free(av);
	}
}

void	k(t_node **a, char **av)
{
	ft_free_av(av);
	ft_free_stack(a);
	printf_and_ex("error", 1);
}

void	ft_free_end(t_node **a, char **av)
{
	ft_free_stack(a);
	ft_free_av(av);
}
