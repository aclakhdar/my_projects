/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 18:36:56 by aclakhda          #+#    #+#             */
/*   Updated: 2024/04/18 16:32:25 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	wall_checker(char **arr, int nbr_collumns, int nbr_lines)
{
	int	i;

	i = 0;
	while (i < strlen_of_line(arr[0]) - 1)
	{
		if (arr[0][i++] != '1')
		{
			ft_free(arr);
			print_and_ex("first line in the map is not valid");
		}
	}
	i = 0;
	while ((i < strlen_of_line(arr[nbr_lines - 1])))
	{
		if (arr[nbr_lines - 1][i] != '1')
		{
			ft_free(arr);
			print_and_ex("last line in the map is not valid");
		}
		i++;
	}
	wall_checker2(arr, nbr_collumns, nbr_lines);
}

void	wall_checker2(char **arr, int nbr_collumns, int nbr_lines)
{
	int	i;

	i = 0;
	while (i < nbr_lines - 1)
	{
		if (arr[i][0] != '1')
		{
			ft_free(arr);
			print_and_ex("first collumn men chi line machi hiya hadik");
		}
		if (arr[i][nbr_collumns - 1] != '1')
		{
			ft_free(arr);
			print_and_ex("last collumn men chi line machi hiya hadik");
		}
		i++;
	}
}
