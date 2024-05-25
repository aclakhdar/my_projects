/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_xy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:52:27 by aclakhda          #+#    #+#             */
/*   Updated: 2024/04/18 16:26:20 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	player_xy(char **arr, t_xy *player)
{
	int	i;
	int	j;

	i = 0;
	while (arr[i])
	{
		j = 0;
		while (arr[i][j])
		{
			if (arr[i][j] == 'P')
			{
				player->x = i;
				player->y = j;
			}
			j++;
		}
		i++;
	}
}
