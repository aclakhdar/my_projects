/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 18:10:11 by aclakhda          #+#    #+#             */
/*   Updated: 2024/04/18 20:32:54 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	window(t_mlx *data, char *path)
{
	t_map		cord;
	t_elemnt	ij;

	ft_memset(&ij, 0, sizeof(t_elemnt));
	data->path = path;
	data->mlx_ptr = mlx_init();
	if (!(data->mlx_ptr))
		print_and_ex("data->mlx is null");
	data->map = dup_map(path);
	data->collect = counter_collection(data->map);
	cord.hight_map = map_h(data->map);
	cord.long_map = map_l(data->map[0]);
	data->window = mlx_new_window(data->mlx_ptr, cord.long_map * 60,
			cord.hight_map * 60, "so_long");
	if (!(data->window))
	{
		free(data->map);
		print_and_ex("data->window is null");
	}
	import_image(data, &cord);
	import(data, &cord);
	put_image(data, ij);
	mlx_key_hook(data->window, event_hand, data);
	mlx_hook(data->window, 17, 0, mouse_exit, data);
	mlx_loop(data->mlx_ptr);
}
