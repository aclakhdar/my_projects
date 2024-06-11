/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 14:27:37 by aclakhda          #+#    #+#             */
/*   Updated: 2024/06/10 15:27:20 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	size_stack(t_node *a, char **av)
{
	int		i;
	t_node	*tmp;

	i = 0;
	tmp = a;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	check(i, av, &a);
	return (i);
}

void	check(int i, char **av, t_node **a)
{
	if (i == 1)
	{
		ft_free_av(av);
		ft_free_stack(a);
		exit(0);
	}
}

char	*all_args(int ac, char **av, int i)
{
	char	*combined_str;
	char	*tmp;

	check_space_em(av, ac);
	combined_str = ft_strdup("");
	if (!combined_str)
		return (NULL);
	while (i < ac)
	{
		tmp = ft_strjoin(combined_str, av[i]);
		free(combined_str);
		if (!tmp)
			return (NULL);
		combined_str = tmp;
		if (i < ac - 1)
		{
			tmp = ft_strjoin(combined_str, " ");
			free(combined_str);
			if (!tmp)
				return (NULL);
			combined_str = tmp;
		}
		i++;
	}
	return (combined_str);
}

int	has_duplicates(t_node *a)
{
	t_node	*tmp;

	while (a)
	{
		tmp = a->next;
		while (tmp)
		{
			if (a->value == tmp->value)
				return (1);
			tmp = tmp->next;
		}
		a = a->next;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_node	*a;
	t_node	*b;
	char	*argv;
	int		i;

	b = NULL;
	a = NULL;
	argv = all_args(ac, av, 1);
	av = ft_split(argv, ' ');
	check_arg(av, argv);
	a = fill_stack(av);
	if (has_duplicates(a))
		k(&a, av);
	i = size_stack(a, av);
	if (!is_sorted(&a))
	{
		if (i <= 5)
			simple_sort(&a, &b, i);
		else
			algh_sort(&a, &b, i, av);
	}
	ft_free_end(&a, av);
	return (0);
}
