/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 18:04:30 by aclakhda          #+#    #+#             */
/*   Updated: 2024/04/18 16:14:18 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_pc(char **arr)
{
	int	i;
	int	j;

	i = 0;
	while (arr[i])
	{
		j = 0;
		while (arr[i][j])
		{
			if (arr[i][j] == 'P' || arr[i][j] == 'C')
			{
				ft_free(arr);
				print_and_ex("the player cant collect C");
			}
			j++;
		}
		i++;
	}
}

void	check_eee(char **arr)
{
	int	i;
	int	j;

	i = 0;
	while (arr[i])
	{
		j = 0;
		while (arr[i][j])
		{
			if (arr[i][j] == 'E')
			{
				ft_free(arr);
				print_and_ex("e surrounded by walls");
			}
			j++;
		}
		i++;
	}
}
