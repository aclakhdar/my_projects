/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 03:46:49 by aclakhda          #+#    #+#             */
/*   Updated: 2024/04/18 18:28:04 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_wall(t_mlx *data, int i, int j)
{
	mlx_put_image_to_window(data->mlx_ptr, data->window,
		data->p_img.img_l, j * 60, i * 60);
}

void	put_exit(t_mlx *data, int i, int j)
{
	mlx_put_image_to_window(data->mlx_ptr, data->window,
		data->p_img.e_img, j * 60, i * 60);
}

void	put_image(t_mlx *data, t_elemnt ij)
{
	ij.i = -1;
	while (data->map[++ij.i])
	{
		ij.j = 0;
		while (data->map[ij.i][ij.j])
		{
			if ((data->map[ij.i][ij.j]) == '1')
				put_wall(data, ij.i, ij.j);
			else if ((data->map[ij.i][ij.j]) == 'E')
				put_exit(data, ij.i, ij.j);
			else if ((data->map[ij.i][ij.j]) == 'C')
				put_collect(data, ij.i, ij.j);
			else if ((data->map[ij.i][ij.j]) == '0')
				put_path(data, ij.i, ij.j);
			else if ((data->map[ij.i][ij.j]) == 'P')
			{
				data->player.x = ij.i;
				data->player.y = ij.j;
				put_player(data, ij.i, ij.j);
			}
			ij.j++;
		}
	}
}
