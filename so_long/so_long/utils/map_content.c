/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_content.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 18:55:12 by aclakhda          #+#    #+#             */
/*   Updated: 2024/04/18 16:20:03 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	map_content(char **arr, t_elemnt el)
{
	while (arr[el.i])
	{
		el.j = 0;
		while (arr[el.i][el.j] && arr[el.i][el.j] != '\n')
		{
			if (arr[el.i][el.j] == 'E')
				el.e++;
			else if (arr[el.i][el.j] == 'P')
				el.p++;
			else if (arr[el.i][el.j] == 'C')
				el.c++;
			else if (arr[el.i][el.j] != '0' && arr[el.i][el.j] != '1')
			{
				ft_free(arr);
				print_and_ex("the map has more elemnt than 0 1 p e c");
			}
			el.j++;
		}
		el.i++;
	}
	if (el.e != 1 || el.p != 1 || el.c < 1)
	{
		ft_free(arr);
		print_and_ex("there is more than one E P or no C");
	}
}
