/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 21:42:40 by aclakhda          #+#    #+#             */
/*   Updated: 2024/05/22 17:54:39 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	destance(t_node **a, int min)
{
	t_node	*tmp;
	int		dis;

	tmp = *a;
	dis = 0;
	while (tmp)
	{
		if (tmp->value == min)
			return (dis);
		dis++;
		tmp = tmp->next;
	}
	return (dis);
}

int	only_space(char *av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (av[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

void	check_space_em(char **av, int ac)
{
	int	i;

	i = 0;
	while (i < ac)
	{
		if (!ft_strlen(av[i]))
			printf_and_ex("error", 1);
		i++;
	}
	i = 0;
	while (i < ac)
	{
		if (only_space(av[i]))
			printf_and_ex("error", 1);
		i++;
	}
}
