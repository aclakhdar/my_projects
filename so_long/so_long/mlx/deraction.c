/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deraction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 00:56:08 by aclakhda          #+#    #+#             */
/*   Updated: 2024/04/18 16:13:20 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	up(t_mlx *data)
{
	if (data->map[data->player.x - 1][data->player.y] == '0'
		|| data->map[data->player.x - 1][data->player.y] == 'C')
	{
		if (data->map[data->player.x - 1][data->player.y] == 'C')
			data->collect--;
		data->counter++;
		data->map[data->player.x - 1][data->player.y] = 'P';
		data->map[data->player.x][data->player.y] = '0';
		ft_printf("%d\n", data->counter);
		data->player.x--;
	}
	if (data->map[data->player.x - 1][data->player.y] == 'E')
	{
		if (data->collect == 0)
		{
			ft_free(data->map);
			ft_printf("-------> congratulation u won!!!\n");
			exit(0);
		}
	}
}

void	down(t_mlx *data)
{
	if (data->map[data->player.x + 1][data->player.y] == '0'
		|| data->map[data->player.x + 1][data->player.y] == 'C')
	{
		if (data->map[data->player.x + 1][data->player.y] == 'C')
			data->collect--;
		data->counter++;
		data->map[data->player.x + 1][data->player.y] = 'P';
		data->map[data->player.x][data->player.y] = '0';
		ft_printf("%d\n", data->counter);
		data->player.x++;
	}
	if (data->map[data->player.x + 1][data->player.y] == 'E')
	{
		if (data->collect == 0)
		{
			ft_free(data->map);
			ft_printf("-------> congratulation u won!!!\n");
			exit(0);
		}
	}
}

void	left(t_mlx *data)
{
	if (data->map[data->player.x][data->player.y - 1] == '0'
		|| data->map[data->player.x][data->player.y - 1] == 'C')
	{
		if (data->map[data->player.x][data->player.y - 1] == 'C')
			(data->collect)--;
		(data->counter)++;
		data->map[data->player.x][(data->player.y) - 1] = 'P';
		data->map[data->player.x][data->player.y] = '0';
		ft_printf("%d\n", data->counter);
		(data->player.y)--;
	}
	if (data->map[data->player.x][(data->player.y) - 1] == 'E')
	{
		if (data->collect == 0)
		{
			ft_free(data->map);
			ft_printf("-------> congratulation u won!!!\n");
			exit(0);
		}
	}
}

void	right(t_mlx *data)
{
	if (data->map[data->player.x][data->player.y + 1] == '0'
		|| data->map[data->player.x][data->player.y + 1] == 'C')
	{
		if (data->map[data->player.x][data->player.y + 1] == 'C')
			(data->collect)--;
		(data->counter)++;
		data->map[data->player.x][data->player.y + 1] = 'P';
		data->map[data->player.x][data->player.y] = '0';
		ft_printf("%d\n", data->counter);
		(data->player.y)++;
	}
	if (data->map[data->player.x][data->player.y + 1] == 'E')
	{
		if (data->collect == 0)
		{
			ft_free(data->map);
			ft_printf("-------> congratulation u won!!!\n");
			exit(0);
		}
	}
}
