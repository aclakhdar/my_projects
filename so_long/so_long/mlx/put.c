/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 23:56:07 by aclakhda          #+#    #+#             */
/*   Updated: 2024/04/17 23:56:34 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_collect(t_mlx *data, int i, int j)
{
	mlx_put_image_to_window(data->mlx_ptr, data->window,
		data->p_img.c_img, j * 60, i * 60);
}

void	put_player(t_mlx *data, int i, int j)
{
	if (data->collect == 0)
		mlx_put_image_to_window(data->mlx_ptr, data->window,
			data->p_img.player_up_img, j * 60, i * 60);
	else
		mlx_put_image_to_window(data->mlx_ptr, data->window,
			data->p_img.player_img, j * 60, i * 60);
}

void	put_path(t_mlx *data, int i, int j)
{
	mlx_put_image_to_window(data->mlx_ptr, data->window,
		data->p_img.path_img, j * 60, i * 60);
}
