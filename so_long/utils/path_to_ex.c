/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_to_ex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 17:14:57 by aclakhda          #+#    #+#             */
/*   Updated: 2024/04/18 16:25:54 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	path_to_ex(char **arr, int x, int y, t_map *cord)
{
	if (x < 0 || y < 0 || x >= cord->hight_map || y >= cord->long_map)
		return ;
	if (arr[x][y] == 'P' || arr[x][y] == 'C' || arr[x][y] == '0')
	{
		arr[x][y] = 'X';
		path_to_ex(arr, x + 1, y, cord);
		path_to_ex(arr, x - 1, y, cord);
		path_to_ex(arr, x, y + 1, cord);
		path_to_ex(arr, x, y - 1, cord);
	}
}

void	path_to_ex_e(char **arr, int x, int y, t_map *cord)
{
	if (x < 0 || y < 0 || x >= cord->hight_map || y >= cord->long_map)
		return ;
	if (arr[x][y] == 'P' || arr[x][y] == 'E' || arr[x][y] == 'X')
	{
		arr[x][y] = '@';
		path_to_ex_e(arr, x + 1, y, cord);
		path_to_ex_e(arr, x - 1, y, cord);
		path_to_ex_e(arr, x, y + 1, cord);
		path_to_ex_e(arr, x, y - 1, cord);
	}
}
