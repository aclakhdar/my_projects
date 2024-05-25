/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 20:59:55 by aclakhda          #+#    #+#             */
/*   Updated: 2024/04/18 22:08:36 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_free(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	map(char *path, t_map *cord)
{
	char		**arr;
	t_xy		player;
	t_elemnt	el;

	ft_memset(&el, 0, sizeof(t_elemnt));
	arr = dup_map(path);
	map_content(arr, el);
	wall_checker(arr, cord->long_map, cord->hight_map);
	player_xy(arr, &player);
	path_to_ex(arr, player.x, player.y, cord);
	check_pc(arr);
	path_to_ex_e(arr, player.x, player.y, cord);
	check_eee(arr);
	ft_free(arr);
}
