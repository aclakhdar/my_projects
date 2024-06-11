/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 21:31:55 by aclakhda          #+#    #+#             */
/*   Updated: 2024/06/08 16:08:48 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_sign(char av)
{
	return (av == '+' || av == '-');
}

int	isnt_num(char *av)
{
	int	i;

	i = 0;
	if (is_sign(av[i]) && av[i + 1] != '\0')
		i++;
	while (av[i] && ft_isdigit(av[i]))
		i++;
	if (av[i] != '\0' && !ft_isdigit(av[i]))
		return (0);
	return (1);
}

int	isnt_zero(char *av)
{
	int	i;

	i = 0;
	if (av[i] == '-' || av[i] == '+')
		i++;
	while (av[i] && av[i] == '0')
		i++;
	if (av[i] == '\0')
		return (1);
	return (0);
}

void	check_arg(char **av, char *argv)
{
	int	i;
	int	zero;

	free(argv);
	i = 0;
	zero = 0;
	while (av[i])
	{
		if (!isnt_num(av[i]))
		{
			ft_free_av(av);
			printf_and_ex("error", 1);
		}
		zero += isnt_zero(av[i]);
		i++;
	}
	if (zero > 1)
	{
		ft_free_av(av);
		printf_and_ex("error", 1);
	}
}
