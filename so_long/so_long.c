/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 20:33:51 by aclakhda          #+#    #+#             */
/*   Updated: 2024/04/19 20:16:34 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char *av[])
{
	t_mlx	data;

	ft_memset(&data, 0, sizeof(t_mlx));
	if (ac == 2)
	{
		map_checker(av[1]);
		window(&data, av[1]);
	}
	else
		print_and_ex("not the valid number of argument!");
	return (0);
}
