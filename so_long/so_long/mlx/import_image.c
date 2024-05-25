/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 18:19:08 by aclakhda          #+#    #+#             */
/*   Updated: 2024/04/18 16:08:30 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	import_image(t_mlx *data, t_map *cord)
{
	data->p_img.img_l = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/Wall.xpm", &(cord->long_img), &(cord->hight_img));
	if (!(data->p_img.img_l))
	{
		ft_free(data->map);
		print_and_ex("failed to get the image of wall");
	}
	data->p_img.e_img = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/exit.xpm", &(cord->long_img), &(cord->hight_img));
	if (!(data->p_img.e_img))
	{
		ft_free(data->map);
		print_and_ex("failed to get the image of the exit");
	}
	data->p_img.c_img = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/coin.xpm", &(cord->long_img), &(cord->hight_img));
	if (!(data->p_img.c_img))
	{
		ft_free(data->map);
		print_and_ex("failed to get the image of coin");
	}
}
