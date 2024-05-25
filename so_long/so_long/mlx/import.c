/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:42:45 by aclakhda          #+#    #+#             */
/*   Updated: 2024/04/18 16:09:24 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	import(t_mlx *data, t_map *cord)
{
	data->p_img.player_img = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/player.xpm", &(cord->long_img), &(cord->hight_img));
	if (!(data->p_img.player_img))
	{
		ft_free(data->map);
		print_and_ex("failed to get the image of player");
	}
	data->p_img.path_img = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/path.xpm", &(cord->long_img), &(cord->hight_img));
	if (!(data->p_img.path_img))
	{
		ft_free(data->map);
		print_and_ex("failed to get the image of the path");
	}
	data->p_img.player_up_img = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/player_up.xpm", &(cord->long_img), &(cord->hight_img));
	if (!(data->p_img.player_up_img))
	{
		ft_free(data->map);
		print_and_ex("failed to get the image of player");
	}
}
