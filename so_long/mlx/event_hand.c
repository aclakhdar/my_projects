/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_hand.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 23:35:33 by aclakhda          #+#    #+#             */
/*   Updated: 2024/04/19 21:13:56 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	clear_and_put(t_mlx *data)
{
	t_elemnt	ij;

	ft_memset(&ij, 0, sizeof(t_elemnt));
	mlx_clear_window(data->mlx_ptr, data->window);
	put_image(data, ij);
}

void	uldr(int keycode, t_mlx *data)
{
	if (keycode == 0)
	{
		left(data);
		clear_and_put(data);
	}
	else if (keycode == 2)
	{
		right(data);
		clear_and_put(data);
	}
	else if (keycode == 13)
	{
		up(data);
		clear_and_put(data);
	}
	else if (keycode == 1)
	{
		down(data);
		clear_and_put(data);
	}
}

int	event_hand(int keycode, t_mlx *data)
{
	if (keycode == 53)
	{
		ft_free(data->map);
		mlx_destroy_window(data->mlx_ptr, data->window);
		exit(0);
	}
	else
		uldr(keycode, data);
	return (0);
}

int	mouse_exit(t_mlx *data)
{
	mlx_destroy_window(data->mlx_ptr, data->window);
	ft_free(data->map);
	exit(0);
	return (0);
}
